%{

#include <list>
#include <iostream>
using namespace std;

#include "mylanga_fp_t.h"
#include "mylanga_ast.h"
#include "mylanga_sem_types.h"
#include "mylanga_error.h"
#define YYSTYPE mylanga_sem_types

extern int line_num; int temp;
extern ptr<ast_program> pg;

extern int yylex();
void yyerror(const char *s) { cerr << MYLANGA_SYNTAX_ERROR(line_num) << endl; }

%}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

/* terminales de la gramática */

%token <_id> ID
%token <_str> INT_LITERAL
%token <_str> FP_LITERAL
%token <_int> KW_FOR KW_PLOT KW_IF KW_THEN KW_ELSE KW_WHILE KW_RETURN KW_FUNCTION KW_PI
%token <_int> EQUAL COMMA SEMICOLON ELLIPSIS
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
  : seq_fun_def plot_cmd          { pg = $$ = mp<ast_program>($1, $2); }

  // error handling
  | seq_fun_def                   { pg = $$ = mp<ast_program>($1, mp<ast_syntax_error>("program: seq_fun_def", line_num)); }
  | plot_cmd                      { pg = $$ = mp<ast_program>(mp<list<ptr<ast_fun_def>>>(1, mp<ast_syntax_error>("program: plot_cmd", line_num)), $1); }
  | /* */                         { pg = $$ = mp<ast_program>(mp<list<ptr<ast_fun_def>>>(1, mp<ast_syntax_error>("program: /* */", line_num)), mp<ast_syntax_error>("program: /* */", line_num)); }
  ;

fun_def
  : KW_FUNCTION ID LPAREN lst_id RPAREN block
                                  { $$ = mp<ast_fun_def>($2, $4, $6); }

  // error handling
  | KW_FUNCTION ID LPAREN lst_id RPAREN /* */
                                  { $$ = mp<ast_syntax_error>("fun_def: KW_FUNCTION ID LPAREN lst_id RPAREN /* */", line_num); }
  ;

plot_cmd
  : KW_PLOT LPAREN expr COMMA expr RPAREN
    KW_FOR ID EQUAL expr ELLIPSIS expr ELLIPSIS expr
                                  { $$ = mp<ast_plot_cmd>($3, $5, $8, $10, $12, $14); }

  // error handling
  | KW_PLOT LPAREN expr COMMA expr RPAREN /* */
                                  { $$ = mp<ast_syntax_error>("plot_cmd: KW_PLOT LPAREN expr COMMA expr RPAREN /* */", line_num); }  
  ;

block
  : stmt                          { $$ = mp<ast_block>(mp<list<ptr<ast_stmt>>>(1, $1)); }
  | LBRACE seq_stmt RBRACE        { $$ = mp<ast_block>($2); }

  // error handling
  | LBRACE RBRACE                 { $$ = mp<ast_syntax_error>("block: LBRACE RBRACE", line_num); }
  ;

stmt
  : ID EQUAL expr                             { $$ = mp<ast_var_assign_stmt>($1, $3); }
  | KW_IF pred KW_THEN block                  { $$ = mp<ast_if_then_stmt>($2, $4); }
  | KW_IF pred KW_THEN block KW_ELSE block    { $$ = mp<ast_if_then_else_stmt>($2, $4, $6); }
  | KW_WHILE pred block                       { $$ = mp<ast_while_stmt>($2, $3); }
  | KW_RETURN expr                            { $$ = mp<ast_return_stmt>($2); }

  // error handling
  | error EQUAL expr                                { $$ = mp<ast_syntax_error>("stmt: error EQUAL expr", line_num); }
  | ID EQUAL error                                  { $$ = mp<ast_syntax_error>("stmt: ID EQUAL error", line_num); }
  | KW_IF expr { temp = line_num; } KW_THEN block   { $$ = mp<ast_syntax_error>("stmt: KW_IF expr KW_THEN block", temp); }
  | KW_WHILE expr { temp = line_num; } block        { $$ = mp<ast_syntax_error>("stmt: KW_WHILE expr block", temp); }
  | KW_IF pred { temp = line_num; } block           { $$ = mp<ast_syntax_error>("stmt: KW_IF pred block", temp); }
  | KW_IF error                                     { $$ = mp<ast_syntax_error>("stmt: KW_IF error", line_num); }
  | KW_WHILE error                                  { $$ = mp<ast_syntax_error>("stmt: KW_WHILE error", line_num); }
  | KW_RETURN error                                 { $$ = mp<ast_syntax_error>("stmt: KW_RETURN error", line_num); }
  ;

expr
  : INT_LITERAL                   { $$ = mp<ast_literal_expr>(stofp_t(*$1)); }
  | FP_LITERAL                    { $$ = mp<ast_literal_expr>(stofp_t(*$1)); }
  | KW_PI                         { $$ = mp<ast_literal_expr>(FP_T_PI); }
  | ID                            { $$ = mp<ast_id_expr>($1); }
  | expr OP_PLUS expr             { $$ = mp<ast_bin_op_expr>($1, $2, $3); }
  | expr OP_MINUS expr            { $$ = mp<ast_bin_op_expr>($1, $2, $3); }
  | expr OP_MULT expr             { $$ = mp<ast_bin_op_expr>($1, $2, $3); }
  | expr OP_DIV expr              { $$ = mp<ast_bin_op_expr>($1, $2, $3); }
  | OP_MINUS expr %prec UMINUS    { $$ = mp<ast_uny_op_expr>($1, $2); }
  | expr OP_EXP expr              { $$ = mp<ast_bin_op_expr>($1, $2, $3); }
  | ID LPAREN lst_expr RPAREN     { $$ = mp<ast_fun_call_expr>($1, $3); }
  | LPAREN expr RPAREN            { $$ = $2; }

  // error handling
  | expr OP_PLUS error             { $$ = mp<ast_syntax_error>("expr: expr OP_PLUS error", line_num); }
  | expr OP_MINUS error            { $$ = mp<ast_syntax_error>("expr: expr OP_MINUS error", line_num); }
  | expr OP_MULT error             { $$ = mp<ast_syntax_error>("expr: expr OP_MULT error", line_num); }
  | expr OP_DIV error              { $$ = mp<ast_syntax_error>("expr: expr OP_DIV error", line_num); }
  | expr OP_EXP error              { $$ = mp<ast_syntax_error>("expr: expr OP_EXP error", line_num); }
  | LPAREN error RPAREN            { $$ = mp<ast_syntax_error>("expr: LPAREN error RPAREN", line_num); }
  ;

pred
  : expr REL_LT expr              { $$ = mp<ast_rel_pred>($1, $2, $3); }
  | expr REL_LEQ expr             { $$ = mp<ast_rel_pred>($1, $2, $3); }
  | expr REL_EQ expr              { $$ = mp<ast_rel_pred>($1, $2, $3); }
  | expr REL_GEQ expr             { $$ = mp<ast_rel_pred>($1, $2, $3); }
  | expr REL_GT expr              { $$ = mp<ast_rel_pred>($1, $2, $3); }
  | pred L_OR pred                { $$ = mp<ast_bin_l_pred>($1, $2, $3); }
  | pred L_AND pred               { $$ = mp<ast_bin_l_pred>($1, $2, $3); }
  | L_NOT pred                    { $$ = mp<ast_uny_l_pred>($1, $2); }
  | LPAREN pred RPAREN            { $$ = $2; }

  // error handling
  | expr REL_LT error              { $$ = mp<ast_syntax_error>("pred: expr REL_LT error", line_num); }
  | expr REL_LEQ error             { $$ = mp<ast_syntax_error>("pred: expr REL_LEQ error", line_num); }
  | expr REL_EQ error              { $$ = mp<ast_syntax_error>("pred: expr REL_EQ error", line_num); }
  | expr REL_GEQ error             { $$ = mp<ast_syntax_error>("pred: expr REL_GEQ error", line_num); }
  | expr REL_GT error              { $$ = mp<ast_syntax_error>("pred: expr REL_GT error", line_num); }
  | pred L_OR error                { $$ = mp<ast_syntax_error>("pred: pred L_OR error", line_num); }
  | pred L_AND error               { $$ = mp<ast_syntax_error>("pred: pred L_AND error", line_num); }
  | L_NOT error                    { $$ = mp<ast_syntax_error>("pred: L_NOT error", line_num); }
  ;

seq_fun_def
  : fun_def                       { $$ = mp<list<ptr<ast_fun_def>>>(1, $1); }
  | seq_fun_def fun_def           { $$ = $1; $$->push_back($2); }
  ;

seq_stmt
  : stmt                          { $$ = mp<list<ptr<ast_stmt>>>(1, $1); }
  | seq_stmt stmt                 { $$ = $1; $$->push_back($2); }
  ;

lst_id
  : /* */                         { $$ = mp<list<ptr<id>>>(); }
  | _lst_id                       { $$ = $1; }
  ;

_lst_id
  : ID                            { $$ = mp<list<ptr<id>>>(1, $1); }
  | _lst_id COMMA ID              { $$ = $1; $$->push_back($3); }
  ;

lst_expr
  : /* */                         { $$ = mp<list<ptr<ast_expr>>>(); }
  | _lst_expr                     { $$ = $1; }
  ;

_lst_expr
  : expr                          { $$ = mp<list<ptr<ast_expr>>>(1, $1); }
  | _lst_expr COMMA expr          { $$ = $1; $$->push_back($3); }
  ;

%%