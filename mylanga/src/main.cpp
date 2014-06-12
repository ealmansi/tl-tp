extern int yyparse();

#include "mylanga_ast.h"

ptr<ast_program> pg;

int main(int argc, char **argv)
{
  if (yyparse() != 0)
    return -1;

  if (not pg->run())
    return -1;

  return 0;
}