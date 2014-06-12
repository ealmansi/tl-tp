%{

#include <string>
#include <iostream>
using namespace std;

#include "mylanga_ast.h"
#include "mylanga_sem_types.h"
#define YYSTYPE mylanga_sem_types

#include "parser.hpp"

extern "C" int yywrap() { }

%}

%x IN_SINGL_COMMENT
%x IN_MULTI_COMMENT

%%

<INITIAL>{
"//"                      BEGIN(IN_SINGL_COMMENT);
"/*"                      BEGIN(IN_MULTI_COMMENT);
[ \t\n]                   ;
"for"                     yylval._int = KW_FOR; return KW_FOR;
"plot"                    yylval._int = KW_PLOT; return KW_PLOT;
"if"                      yylval._int = KW_IF; return KW_IF;
"then"                    yylval._int = KW_THEN; return KW_THEN;
"else"                    yylval._int = KW_ELSE; return KW_ELSE;
"while"                   yylval._int = KW_WHILE; return KW_WHILE;
"return"                  yylval._int = KW_RETURN; return KW_RETURN;
"function"                yylval._int = KW_FUNCTION; return KW_FUNCTION;
"pi"                      yylval._int = KW_PI; return KW_PI;
[a-zA-Z][a-zA-Z0-9_]*     yylval._id = mp<id>(yytext, yyleng); return ID;
[0-9]+                    yylval._str = mp<string>(yytext, yyleng); return INT_LITERAL;
[0-9]+\.[0-9]+            yylval._str = mp<string>(yytext, yyleng); return FP_LITERAL;
"+"                       yylval._int = OP_PLUS; return OP_PLUS;
"-"                       yylval._int = OP_MINUS; return OP_MINUS;
"*"                       yylval._int = OP_MULT; return OP_MULT;
"/"                       yylval._int = OP_DIV; return OP_DIV;
"^"                       yylval._int = OP_EXP; return OP_EXP;
";"                       yylval._int = SEMICOLON; return SEMICOLON;
","                       yylval._int = COMMA; return COMMA;
".."                      yylval._int = ELLIPSIS; return ELLIPSIS;
"="                       yylval._int = EQUAL; return EQUAL;
"||"                      yylval._int = L_OR; return L_OR;
"&&"                      yylval._int = L_AND; return L_AND;
"!"                       yylval._int = L_NOT; return L_NOT;
"<"                       yylval._int = REL_LT; return REL_LT;
"<="                      yylval._int = REL_LEQ; return REL_LEQ;
"=="                      yylval._int = REL_EQ; return REL_EQ;
">="                      yylval._int = REL_GEQ; return REL_GEQ;
">"                       yylval._int = REL_GT; return REL_GT;
"("                       yylval._int = LPAREN; return LPAREN;
")"                       yylval._int = RPAREN; return RPAREN;
"{"                       yylval._int = LBRACE; return LBRACE;
"}"                       yylval._int = RBRACE; return RBRACE;
.                         cout << "Lexer error: Token inesperado \"" << string(yytext, yyleng) << "\"" << endl; yyterminate();
}

<IN_SINGL_COMMENT>{
\n                        BEGIN(INITIAL);
.                         ;
}

<IN_MULTI_COMMENT>{
"*/"                      BEGIN(INITIAL);
.                         ;
}

%%