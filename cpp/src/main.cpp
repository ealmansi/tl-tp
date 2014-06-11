extern int yyparse();

#include "mylanga_ast.h"

ptr<ast_program> pg;

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  if (yyparse() == 0)
    pg->run();

  return 0;
}