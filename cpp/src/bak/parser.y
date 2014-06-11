  %{
    #include "mylanga_semantic_types.h"

    #include <iostream>
    using namespace std;

    extern int yylex();
    void yyerror(const char *s) { cout << "ERROR: " << s << endl; }

    #define sv(elem,field) elem->_##field
%}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* posibles tipos para el valor de un elemento de la gramatica */

%union {
    YYSTYPE() : val(new mylanga_semantic_types()) { }
    ~YYSTYPE() { if (val) delete val; }
    mylanga_semantic_types* val;
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* terminales de la gramática */

%token <val> ID
%token <val> INT_LITERAL
%token <val> FP_LITERAL
%token <val> KW_FOR KW_PLOT KW_IF KW_THEN KW_ELSE KW_WHILE KW_RETURN KW_FUNCTION KW_PI
%token <val> EQUAL COMMA ELLIPSIS
%token <val> L_OR L_AND L_NOT
%token <val> REL_EQ REL_LT REL_LEQ REL_GEQ REL_GT
%token <val> LPAREN RPAREN LBRACE RBRACE
%token <val> OP_PLUS OP_MINUS OP_MULT OP_DIV OP_EXP

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* no terminales de la gramática */

%type <val> program fun_def plot_cmd
%type <val> block stmt expr pred fun_call const_value
%type <val> seq_fun_def seq_stmt lst_id _lst_id lst_expr _lst_expr

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* precedencia de operadores */

%right KW_THEN KW_ELSE
%left L_OR
%left L_AND
%left L_NOT
%left OP_PLUS OP_MINUS
%left OP_MULT OP_DIV
%left UMINUS
%left OP_EXP

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* símbolo distinguido de la gramática */

%start program

%%

program
  : seq_fun_def plot_cmd          { sv($$,pg) = mp<ast_program>(sv($1,fds), sv($2,pc)); }
  ;

fun_def
  : KW_FUNCTION ID LPAREN lst_id RPAREN block
                                { sv($$,fd) = mp<ast_fun_def>(sv($2,id), sv($4,ids), sv($6,bl)); }
  ;

plot_cmd
  : KW_PLOT LPAREN fun_call COMMA fun_call RPAREN KW_FOR ID EQUAL const_value ELLIPSIS const_value ELLIPSIS const_value
    { sv($$,pc) = mp<ast_plot_cmd>(sv($3,fc), sv($5,fc), sv($8,id), sv($10,cv), sv($12,cv), sv($14,cv)); }
  ;

block
  : stmt                        { sv($$,bl) = mp<ast_block>(mp<list<ptr<ast_stmt>>>(1, sv($1,st))); }
  | LBRACE seq_stmt RBRACE      { sv($$,bl) = mp<ast_block>(sv($2,sts)); }
  ;

stmt
  : ID EQUAL expr                             { sv($$,st) = mp<ast_var_assign_stmt>(sv($1,id), sv($3,ex)); }
  | KW_IF pred KW_THEN block                  { sv($$,st) = mp<ast_if_then_stmt>(sv($2,pr), sv($4, bl)); }
  | KW_IF pred KW_THEN block KW_ELSE block    { sv($$,st) = mp<ast_if_then_else_stmt>(sv($2,pr), sv($4, bl), sv($6, bl)); }
  | KW_WHILE pred block                       { sv($$,st) = mp<ast_while_stmt>(sv($2,pr), sv($3,bl)); }
  | KW_RETURN expr                            { sv($$,st) = mp<ast_return_stmt>(sv($2,ex)); }
  ;

expr
  : INT_LITERAL                  { sv($$,ex) = sv($1,ex); }
  | FP_LITERAL                   { sv($$,ex) = sv($1,ex); }
  | KW_PI                        { sv($$,ex) = sv($1,ex); }
  | ID                           { sv($$,ex) = mp<ast_id_expr>(sv($1,id)); }
  | fun_call                     { sv($$,ex) = sv($1,ex); }
  | expr OP_PLUS expr            { sv($$,ex) = mp<ast_bin_op_expr>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | expr OP_MINUS expr           { sv($$,ex) = mp<ast_bin_op_expr>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | expr OP_MULT expr            { sv($$,ex) = mp<ast_bin_op_expr>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | expr OP_DIV expr             { sv($$,ex) = mp<ast_bin_op_expr>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | OP_MINUS expr %prec UMINUS   { sv($$,ex) = mp<ast_uny_op_expr>(sv($1,int), sv($2,ex)); }
  | expr OP_EXP expr             { sv($$,ex) = mp<ast_bin_op_expr>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | LPAREN expr RPAREN           { sv($$,ex) = sv($2,ex); }
  ;

pred
  : expr REL_LT expr             { sv($$,pr) = mp<ast_rel_pred>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | expr REL_LEQ expr            { sv($$,pr) = mp<ast_rel_pred>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | expr REL_EQ expr             { sv($$,pr) = mp<ast_rel_pred>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | expr REL_GEQ expr            { sv($$,pr) = mp<ast_rel_pred>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | expr REL_GT expr             { sv($$,pr) = mp<ast_rel_pred>(sv($1,ex), sv($2,int), sv($3,ex)); }
  | pred L_OR pred               { sv($$,pr) = mp<ast_bin_l_pred>(sv($1,pr), sv($2,int), sv($3,pr)); }
  | pred L_AND pred              { sv($$,pr) = mp<ast_bin_l_pred>(sv($1,pr), sv($2,int), sv($3,pr)); }
  | L_NOT pred                   { sv($$,pr) = mp<ast_uny_l_pred>(sv($1,int), sv($2,pr)); }
  | LPAREN pred RPAREN           { sv($$,pr) = sv($2,pr); }
  ;

fun_call
  : ID LPAREN lst_expr RPAREN     { sv($$,fc) = mp<ast_fun_call>(sv($1,id), sv($3,exs)); }
  ;

const_value
  : INT_LITERAL                   { sv($$,cv) = mp<ast_int_literal>(sv($1,str)); }
  | FP_LITERAL                    { sv($$,cv) = mp<ast_fp_literal>(sv($1,str)); }
  | KW_PI                         { sv($$,cv) = mp<ast_pi_literal>(); }
  | OP_MINUS INT_LITERAL          { sv($$,cv) = mp<ast_neg_int_literal>(sv($2,str)); }
  | OP_MINUS FP_LITERAL           { sv($$,cv) = mp<ast_neg_fp_literal>(sv($2,str)); }
  | OP_MINUS KW_PI                { sv($$,cv) = mp<ast_neg_pi_literal>(); }
  ;

seq_fun_def
  : fun_def                       { sv($$,fds) = mp<list<ptr<ast_fun_def>>>(1, sv($1,fd)); }
  | seq_fun_def fun_def           { sv($$,fds) = sv($1,fds); sv($$,fds)->push_back(sv($2,fd)); }
  ;

seq_stmt
  : stmt                          { sv($$,sts) = mp<list<ptr<ast_stmt>>>(1, sv($1,st)); }
  | seq_stmt stmt                 { sv($$,sts) = sv($1,sts); sv($$,sts)->push_back(sv($2,st)); }
  ;

lst_id
  : /* */                         { sv($$,ids) = mp<list<ptr<id>>>(); }
  | _lst_id                       { sv($$,ids) = sv($1,ids); }
  ;

_lst_id
  : ID                            { sv($$,ids) = mp<list<ptr<id>>>(1, sv($1,id)); }
  | _lst_id COMMA ID              { sv($$,ids) = sv($1,ids); sv($$,ids)->push_back(sv($3,id)); }
  ;

lst_expr
  : /* */                         { sv($$,exs) = mp<list<ptr<ast_expr>>>(); }
  | _lst_expr                     { sv($$,exs) = sv($1,exs); }
  ;

_lst_expr
  : expr                          { sv($$,exs) = mp<list<ptr<ast_expr>>>(1, sv($1,ex)); }
  | _lst_expr COMMA expr          { sv($$,exs) = sv($1,exs); sv($$,exs)->push_back(sv($3,ex)); }
  ;

%%