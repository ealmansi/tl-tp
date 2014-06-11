#ifndef MYLANGA_SEM_TYPES_H
#define MYLANGA_SEM_TYPES_H

#include "mylanga_ast.h"

#include <memory>
template <typename T>
using ptr = shared_ptr<T>;
#define mp make_shared

/* posibles tipos para el valor semántico de un elemento de la gramática */

struct mylanga_sem_types
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
  ptr<ast_literal> _lt = nullptr;
  ptr<list<ptr<ast_fun_def>>> _fds = nullptr;
  ptr<list<ptr<ast_stmt>>> _sts = nullptr;
  ptr<list<ptr<id>>> _ids = nullptr;
  ptr<list<ptr<ast_expr>>> _exs = nullptr;
};

#endif /* MYLANGA_SEM_TYPES_H */