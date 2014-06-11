extern int yyparse();

#include "mylanga_ast.h"

ast_program* pg;

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  yyparse();
  // pg->run();
  delete pg;

  return 0;
}