#ifndef MYLANGA_SEMANTIC_TYPES_H
#define MYLANGA_SEMANTIC_TYPES_H

#include <memory>
#include <string>
#include <list>
#include "mylanga_ast.h"
using namespace std;

typedef string id;
template <typename T> using ptr = shared_ptr<T>;
#define mp make_shared

struct mylanga_semantic_types
{
  int _int;
  ptr<id> _id = nullptr;
  ptr<string> _str = nullptr;
  ptr<ast_program> _pg = nullptr;
  ptr<ast_fun_def> _fd = nullptr;
  ptr<ast_plot_cmd> _pc = nullptr;
  ptr<ast_block> _bl = nullptr;
  ptr<ast_stmt> _st = nullptr;
  ptr<ast_pred> _pr = nullptr;
  ptr<ast_fun_call> _fc = nullptr;
  ptr<ast_expr> _ex = nullptr;
  ptr<ast_const_value> _cv = nullptr;
  ptr<list<ptr<ast_fun_def>>> _fds = nullptr;
  ptr<list<ptr<ast_stmt>>> _sts = nullptr;
  ptr<list<ptr<id>>> _ids = nullptr;
  ptr<list<ptr<ast_expr>>> _exs = nullptr;
};


#endif /* MYLANGA_SEMANTIC_TYPES_H */