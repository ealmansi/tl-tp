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
  : seq_fun_def plot_cmd          { pg = $$ = mp<ast_program>($1, $2, line_num); }

  // error handling
  | seq_fun_def                   { pg = $$ = mp<ast_program>($1, mp<ast_syntax_error>("Falta definir la instrucción de plot.", line_num), line_num); }
  | plot_cmd                      { pg = $$ = mp<ast_program>(mp<list<ptr<ast_fun_def>>>(1, mp<ast_syntax_error>("No se definió ninguna función.", line_num)), $1, line_num); }
  | /* */                         { pg = $$ = mp<ast_program>(mp<list<ptr<ast_fun_def>>>(1, mp<ast_syntax_error>("No se definió ninguna función.", line_num)), mp<ast_syntax_error>("Falta definir la instrucción de plot.", line_num), line_num); }
  ;

fun_def
  : KW_FUNCTION ID LPAREN lst_id RPAREN block
                                  { $$ = mp<ast_fun_def>($2, $4, $6, line_num); }

  // error handling
  | KW_FUNCTION ID LPAREN lst_id RPAREN /* */
                                  { $$ = mp<ast_syntax_error>("La definición de la función \'" + *$2 + "\' está incompleta.", line_num); }
  ;

plot_cmd
  : KW_PLOT LPAREN expr COMMA expr RPAREN
    KW_FOR ID EQUAL expr ELLIPSIS expr ELLIPSIS expr
                                  { $$ = mp<ast_plot_cmd>($3, $5, $8, $10, $12, $14, line_num); }

  // error handling
  | KW_PLOT LPAREN expr COMMA expr RPAREN /* */
                                  { $$ = mp<ast_syntax_error>("Falta definir el rango de la instrucción de plot.", line_num); }  
  ;

block
  : stmt                          { $$ = mp<ast_block>(mp<list<ptr<ast_stmt>>>(1, $1), line_num); }
  | LBRACE seq_stmt RBRACE        { $$ = mp<ast_block>($2, line_num); }

  // error handling
  | LBRACE RBRACE                 { $$ = mp<ast_syntax_error>("Un bloque de instrucciones no puede ser vacío.", line_num); }
  ;

stmt
  : ID EQUAL expr                             { $$ = mp<ast_var_assign_stmt>($1, $3, line_num); }
  | KW_IF pred KW_THEN block                  { $$ = mp<ast_if_then_stmt>($2, $4, line_num); }
  | KW_IF pred KW_THEN block KW_ELSE block    { $$ = mp<ast_if_then_else_stmt>($2, $4, $6, line_num); }
  | KW_WHILE pred block                       { $$ = mp<ast_while_stmt>($2, $3, line_num); }
  | KW_RETURN expr                            { $$ = mp<ast_return_stmt>($2, line_num); }

  // error handling
  | error EQUAL expr                                { $$ = mp<ast_syntax_error>("Instrucción de asignación inválida.", line_num); }
  | ID EQUAL error                                  { $$ = mp<ast_syntax_error>("La expresión de lado derecho de la asignación es inválida.", line_num); }
  | KW_IF expr { temp = line_num; } KW_THEN block   { $$ = mp<ast_syntax_error>("La guarda de un if debe ser un predicado con valor booleano.", temp); }
  | KW_WHILE expr { temp = line_num; } block        { $$ = mp<ast_syntax_error>("La guarda de un while debe ser un predicado con valor booleano.", temp); }
  | KW_IF pred { temp = line_num; } block           { $$ = mp<ast_syntax_error>("Falta la palabra clave 'then' en la instrucción if.", temp); }
  | KW_IF error                                     { $$ = mp<ast_syntax_error>("La guarda del if es inválida.", line_num); }
  | KW_WHILE error                                  { $$ = mp<ast_syntax_error>("La guarda del while es inválida.", line_num); }
  | KW_RETURN error                                 { $$ = mp<ast_syntax_error>("La expresión de retorno es inválida.", line_num); }
  ;

expr
  : INT_LITERAL                   { $$ = mp<ast_literal_expr>(stofp_t(*$1), line_num); }
  | FP_LITERAL                    { $$ = mp<ast_literal_expr>(stofp_t(*$1), line_num); }
  | KW_PI                         { $$ = mp<ast_literal_expr>(FP_T_PI, line_num); }
  | ID                            { $$ = mp<ast_id_expr>($1, line_num); }
  | expr OP_PLUS expr             { $$ = mp<ast_bin_op_expr>($1, $2, $3, line_num); }
  | expr OP_MINUS expr            { $$ = mp<ast_bin_op_expr>($1, $2, $3, line_num); }
  | expr OP_MULT expr             { $$ = mp<ast_bin_op_expr>($1, $2, $3, line_num); }
  | expr OP_DIV expr              { $$ = mp<ast_bin_op_expr>($1, $2, $3, line_num); }
  | OP_MINUS expr %prec UMINUS    { $$ = mp<ast_uny_op_expr>($1, $2, line_num); }
  | expr OP_EXP expr              { $$ = mp<ast_bin_op_expr>($1, $2, $3, line_num); }
  | ID LPAREN lst_expr RPAREN     { $$ = mp<ast_fun_call_expr>($1, $3, line_num); }
  | LPAREN expr RPAREN            { $$ = $2; }

  // error handling
  | expr OP_PLUS error             { $$ = mp<ast_syntax_error>("Expresión inválida.", line_num); }
  | expr OP_MINUS error            { $$ = mp<ast_syntax_error>("Expresión inválida.", line_num); }
  | expr OP_MULT error             { $$ = mp<ast_syntax_error>("Expresión inválida.", line_num); }
  | expr OP_DIV error              { $$ = mp<ast_syntax_error>("Expresión inválida.", line_num); }
  | expr OP_EXP error              { $$ = mp<ast_syntax_error>("Expresión inválida.", line_num); }
  | LPAREN error RPAREN            { $$ = mp<ast_syntax_error>("Expresión inválida.", line_num); }
  ;

pred
  : expr REL_LT expr              { $$ = mp<ast_rel_pred>($1, $2, $3, line_num); }
  | expr REL_LEQ expr             { $$ = mp<ast_rel_pred>($1, $2, $3, line_num); }
  | expr REL_EQ expr              { $$ = mp<ast_rel_pred>($1, $2, $3, line_num); }
  | expr REL_GEQ expr             { $$ = mp<ast_rel_pred>($1, $2, $3, line_num); }
  | expr REL_GT expr              { $$ = mp<ast_rel_pred>($1, $2, $3, line_num); }
  | pred L_OR pred                { $$ = mp<ast_bin_l_pred>($1, $2, $3, line_num); }
  | pred L_AND pred               { $$ = mp<ast_bin_l_pred>($1, $2, $3, line_num); }
  | L_NOT pred                    { $$ = mp<ast_uny_l_pred>($1, $2, line_num); }
  | LPAREN pred RPAREN            { $$ = $2; }

  // error handling
  | expr REL_LT error              { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
  | expr REL_LEQ error             { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
  | expr REL_EQ error              { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
  | expr REL_GEQ error             { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
  | expr REL_GT error              { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
  | pred L_OR error                { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
  | pred L_AND error               { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
  | L_NOT error                    { $$ = mp<ast_syntax_error>("Predicado inválido", line_num); }
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