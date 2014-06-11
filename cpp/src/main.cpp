extern int yyparse();

#include "mylanga_ast.h"

ptr<ast_program> pg;

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  yyparse();
  // pg->run();

  return 0;
}