  %{
    #include "mylanga_ast.h"

    #include <list>
    #include <iostream>
    using namespace std;

    extern int yylex();
    void yyerror(const char *s) { cout << "ERROR: " << s << endl; }
    
    extern ast_program* pg;
%}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* posibles tipos para el valor semántico de un elemento de la gramática */

%union {
    int _int;
    id* _id;
    string* _str;
    ast_program* _pg;
    ast_fun_def* _fd;
    ast_plot_cmd* _pc;
    ast_block* _bl;
    ast_stmt* _st;
    ast_pred* _pr;
    ast_fun_call* _fc;
    ast_expr* _ex;
    ast_const_value* _cv;
    list<ast_fun_def*>* _fds;
    list<ast_stmt*>* _sts;
    list<id*>* _ids;
    list<ast_expr*>* _exs;
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* terminales de la gramática */

%token <_id> ID
%token <_str> INT_LITERAL
%token <_str> FP_LITERAL
%token <_int> KW_FOR KW_PLOT KW_IF KW_THEN KW_ELSE KW_WHILE KW_RETURN KW_FUNCTION KW_PI
%token <_int> EQUAL COMMA ELLIPSIS
%token <_int> L_OR L_AND L_NOT
%token <_int> REL_EQ REL_LT REL_LEQ REL_GEQ REL_GT
%token <_int> LPAREN RPAREN LBRACE RBRACE
%token <_int> OP_PLUS OP_MINUS OP_MULT OP_DIV OP_EXP

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* no terminales de la gramática */

%type <_pg> program
%type <_fd> fun_def
%type <_pc> plot_cmd
%type <_bl> block
%type <_st> stmt
%type <_ex> expr
%type <_pr> pred
%type <_fc> fun_call
%type <_cv> const_value
%type <_fds> seq_fun_def
%type <_sts> seq_stmt
%type <_ids> lst_id
%type <_ids> _lst_id
%type <_exs> lst_expr
%type <_exs> _lst_expr

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
  : seq_fun_def plot_cmd          { pg = $$ = new ast_program($1, $2); }
  ;

fun_def
  : KW_FUNCTION ID LPAREN lst_id RPAREN block
                                { $$ = new ast_fun_def($2, $4, $6); }
  ;

plot_cmd
  : KW_PLOT LPAREN fun_call COMMA fun_call RPAREN KW_FOR ID EQUAL const_value ELLIPSIS const_value ELLIPSIS const_value
    { $$ = new ast_plot_cmd($3, $5, $8, $10, $12, $14); }
  ;

block
  : stmt                        { $$ = new ast_block(new list<ast_stmt*>(1, $1)); }
  | LBRACE seq_stmt RBRACE      { $$ = new ast_block($2); }
  ;

stmt
  : ID EQUAL expr                             { $$ = new ast_var_assign_stmt($1, $3); }
  | KW_IF pred KW_THEN block                  { $$ = new ast_if_then_stmt($2, $4); }
  | KW_IF pred KW_THEN block KW_ELSE block    { $$ = new ast_if_then_else_stmt($2, $4, $6); }
  | KW_WHILE pred block                       { $$ = new ast_while_stmt($2, $3); }
  | KW_RETURN expr                            { $$ = new ast_return_stmt($2); }
  ;

expr
  : INT_LITERAL                  { $$ = new ast_int_literal($1); }
  | FP_LITERAL                   { $$ = new ast_fp_literal($1); }
  | KW_PI                        { $$ = new ast_pi_literal(); }
  | ID                           { $$ = new ast_id_expr($1); }
  | fun_call                     { $$ = $1; }
  | expr OP_PLUS expr            { $$ = new ast_bin_op_expr($1, $2, $3); }
  | expr OP_MINUS expr           { $$ = new ast_bin_op_expr($1, $2, $3); }
  | expr OP_MULT expr            { $$ = new ast_bin_op_expr($1, $2, $3); }
  | expr OP_DIV expr             { $$ = new ast_bin_op_expr($1, $2, $3); }
  | OP_MINUS expr %prec UMINUS   { $$ = new ast_uny_op_expr($1, $2); }
  | expr OP_EXP expr             { $$ = new ast_bin_op_expr($1, $2, $3); }
  | LPAREN expr RPAREN           { $$ = $2; }
  ;

pred
  : expr REL_LT expr             { $$ = new ast_rel_pred($1, $2, $3); }
  | expr REL_LEQ expr            { $$ = new ast_rel_pred($1, $2, $3); }
  | expr REL_EQ expr             { $$ = new ast_rel_pred($1, $2, $3); }
  | expr REL_GEQ expr            { $$ = new ast_rel_pred($1, $2, $3); }
  | expr REL_GT expr             { $$ = new ast_rel_pred($1, $2, $3); }
  | pred L_OR pred               { $$ = new ast_bin_l_pred($1, $2, $3); }
  | pred L_AND pred              { $$ = new ast_bin_l_pred($1, $2, $3); }
  | L_NOT pred                   { $$ = new ast_uny_l_pred($1, $2); }
  | LPAREN pred RPAREN           { $$ = $2; }
  ;

fun_call
  : ID LPAREN lst_expr RPAREN     { $$ = new ast_fun_call($1, $3); }
  ;

const_value
  : INT_LITERAL                   { $$ = new ast_int_literal($1); }
  | FP_LITERAL                    { $$ = new ast_fp_literal($1); }
  | KW_PI                         { $$ = new ast_pi_literal(); }
  | OP_MINUS INT_LITERAL          { $$ = new ast_neg_int_literal($2); }
  | OP_MINUS FP_LITERAL           { $$ = new ast_neg_fp_literal($2); }
  | OP_MINUS KW_PI                { $$ = new ast_neg_pi_literal(); }
  ;

seq_fun_def
  : fun_def                       { $$ = new list<ast_fun_def*>(1, $1); }
  | seq_fun_def fun_def           { $$ = $1; $$->push_back($2); }
  ;

seq_stmt
  : stmt                          { $$ = new list<ast_stmt*>(1, $1); }
  | seq_stmt stmt                 { $$ = $1; $$->push_back($2); }
  ;

lst_id
  : /* */                         { $$ = new list<id*>(); }
  | _lst_id                       { $$ = $1; }
  ;

_lst_id
  : ID                            { $$ = new list<id*>(1, $1); }
  | _lst_id COMMA ID              { $$ = $1; $$->push_back($3); }
  ;

lst_expr
  : /* */                         { $$ = new list<ast_expr*>(); }
  | _lst_expr                     { $$ = $1; }
  ;

_lst_expr
  : expr                          { $$ = new list<ast_expr*>(1, $1); }
  | _lst_expr COMMA expr          { $$ = $1; $$->push_back($3); }
  ;

%%