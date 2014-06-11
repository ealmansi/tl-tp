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
  ptr<id> _id;
  ptr<string> _str;
  ptr<ast_program> _pg;
  ptr<ast_fun_def> _fd;
  ptr<ast_plot_cmd> _pc;
  ptr<ast_block> _bl;
  ptr<ast_stmt> _st;
  ptr<ast_pred> _pr;
  ptr<ast_fun_call> _fc;
  ptr<ast_expr> _ex;
  ptr<ast_const_value> _cv;
  ptr<list<ptr<ast_fun_def>>> _fds;
  ptr<list<ptr<ast_stmt>>> _sts;
  ptr<list<ptr<id>>> _ids;
  ptr<list<ptr<ast_expr>>> _exs;
};

#endif /* MYLANGA_SEM_TYPES_H */