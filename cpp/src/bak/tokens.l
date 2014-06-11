%{

#include "mylanga_semantic_types.h"

#include <string>
#include <iostream>
using namespace std;

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
"for"                     yylval.val->_int = KW_FOR; return KW_FOR;
"plot"                    yylval.val->_int = KW_PLOT; return KW_PLOT;
"if"                      yylval.val->_int = KW_IF; return KW_IF;
"then"                    yylval.val->_int = KW_THEN; return KW_THEN;
"else"                    yylval.val->_int = KW_ELSE; return KW_ELSE;
"while"                   yylval.val->_int = KW_WHILE; return KW_WHILE;
"return"                  yylval.val->_int = KW_RETURN; return KW_RETURN;
"function"                yylval.val->_int = KW_FUNCTION; return KW_FUNCTION;
"pi"                      yylval.val->_int = KW_PI; return KW_PI;
[a-zA-Z][a-zA-Z0-9_]*     yylval.val->_id = mp<id>(yytext, yyleng); return ID;
[0-9]+                    yylval.val->_str = mp<string>(yytext, yyleng); return INT_LITERAL;
[0-9]+\.[0-9]+            yylval.val->_str = mp<string>(yytext, yyleng); return FP_LITERAL;
"+"                       yylval.val->_int = OP_PLUS; return OP_PLUS;
"-"                       yylval.val->_int = OP_MINUS; return OP_MINUS;
"*"                       yylval.val->_int = OP_MULT; return OP_MULT;
"/"                       yylval.val->_int = OP_DIV; return OP_DIV;
"^"                       yylval.val->_int = OP_EXP; return OP_EXP;
","                       yylval.val->_int = COMMA; return COMMA;
".."                      yylval.val->_int = ELLIPSIS; return ELLIPSIS;
"="                       yylval.val->_int = EQUAL; return EQUAL;
"||"                      yylval.val->_int = L_OR; return L_OR;
"&&"                      yylval.val->_int = L_AND; return L_AND;
"!"                       yylval.val->_int = L_NOT; return L_NOT;
"<"                       yylval.val->_int = REL_LT; return REL_LT;
"<="                      yylval.val->_int = REL_LEQ; return REL_LEQ;
"=="                      yylval.val->_int = REL_EQ; return REL_EQ;
">="                      yylval.val->_int = REL_GEQ; return REL_GEQ;
">"                       yylval.val->_int = REL_GT; return REL_GT;
"("                       yylval.val->_int = LPAREN; return LPAREN;
")"                       yylval.val->_int = RPAREN; return RPAREN;
"{"                       yylval.val->_int = LBRACE; return LBRACE;
"}"                       yylval.val->_int = RBRACE; return RBRACE;
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