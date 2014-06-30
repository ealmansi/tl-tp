#include <iostream>
#include <cmath>
using namespace std;

#include "mylanga_fp_t.h"
#include "mylanga_ast.h"
#include "mylanga_sem_types.h"
#include "mylanga_error.h"
#define YYSTYPE mylanga_sem_types

#include "parser.hpp"

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void symbol_table::define_fun(ptr<ast_fun_def> _fd)
{
  functions[*(_fd->_id)] = _fd;
}

void symbol_table::undefine_fun(ptr<ast_fun_def> _fd)
{
  functions.erase(*(_fd->_id));
}

ptr<ast_fun_def> symbol_table::get_fun_def(ptr<id> _id)
{
  return (functions.count(*_id) > 0) ? functions[*_id] : nullptr;
}

void symbol_table::open_scope()
{
  scopes.emplace();
}

void symbol_table::close_scope()
{
  scopes.pop();
}

void symbol_table::declare_var(ptr<id> _id)
{
  set_var(_id, 0.0);
}

bool symbol_table::var_is_declared(ptr<id> _id)
{
  return get_var(_id).is_valid;
}

void symbol_table::set_var(ptr<id> _id, fp_t value)
{
  if (scopes.empty())
  {
    MYLANGA_INTERNAL_ERROR();
  }

  auto& scope = scopes.top();
  scope[*_id] = value;
}

maybe_fp_t symbol_table::get_var(ptr<id> _id)
{
  if (scopes.empty())
  {
    MYLANGA_INTERNAL_ERROR();
  }

  auto& scope = scopes.top();
  return (scope.count(*_id) > 0) ? maybe_fp_t(scope[*_id]) : maybe_fp_t();
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

fp_t ast_literal_expr::eval(symbol_table& sym)
{
  return _vl;
}

fp_t ast_id_expr::eval(symbol_table& sym)
{
  maybe_fp_t var = sym.get_var(_id);
  
  if (not var.is_valid)
  {
    // runtime error
    cerr << MYLANGA_RUNTIME_ERROR << " | " << \
      "Lectura de la variable \'" << *_id << "\' sin haberle asignado previamente un valor." << endl;
    MYLANGA_END_ABRUPTLY();
  }

  return var.value;
}

fp_t ast_bin_op_expr::eval(symbol_table& sym)
{
  switch (_op)
  {
    case OP_PLUS: return _ex1->eval(sym) + _ex2->eval(sym);
    case OP_MINUS: return _ex1->eval(sym) - _ex2->eval(sym);
    case OP_MULT: return _ex1->eval(sym) * _ex2->eval(sym);
    case OP_DIV: return _ex1->eval(sym) / _ex2->eval(sym);
    case OP_EXP: return pow(_ex1->eval(sym), _ex2->eval(sym));
  }
  
  MYLANGA_INTERNAL_ERROR();
}

fp_t ast_uny_op_expr::eval(symbol_table& sym)
{
  switch (_op)
  {
    case OP_MINUS: return - _ex->eval(sym);
  }

  MYLANGA_INTERNAL_ERROR();
}

fp_t ast_fun_call_expr::eval(symbol_table& sym)
{
  list<fp_t> args;
  for (auto _ex : *_exs)
    args.push_back(_ex->eval(sym));

  sym.open_scope();

  ptr<ast_fun_def> _fd = sym.get_fun_def(_id);
  
  auto arg_it = args.begin();
  for (auto _param_id : *(_fd->_ids))
    sym.set_var(_param_id, *arg_it++);

  maybe_fp_t ret = _fd->_bl->exec(sym);

  sym.close_scope();

  if (not ret.is_valid)
  {
    // runtime error
    cerr << MYLANGA_RUNTIME_ERROR << " | " << \
      "La función \'" << *_id << "\' se ejecutó sin retornar un valor." << endl;
    MYLANGA_END_ABRUPTLY();
  }

  return ret.value;
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool ast_rel_pred::test(symbol_table& sym)
{
  switch (_op)
  {
    case REL_LT: return _ex1->eval(sym) < _ex2->eval(sym);
    case REL_LEQ: return _ex1->eval(sym) <= _ex2->eval(sym);
    case REL_EQ: return _ex1->eval(sym) == _ex2->eval(sym);
    case REL_GEQ: return _ex1->eval(sym) >= _ex2->eval(sym);
    case REL_GT: return _ex1->eval(sym) > _ex2->eval(sym);
  }
  
  MYLANGA_INTERNAL_ERROR();
}

bool ast_bin_l_pred::test(symbol_table& sym)
{
  switch (_op)
  {
    case L_OR: return _pr1->test(sym) or _pr2->test(sym);
    case L_AND: return _pr1->test(sym) and _pr2->test(sym);
  }
  
  MYLANGA_INTERNAL_ERROR();
}

bool ast_uny_l_pred::test(symbol_table& sym)
{
  switch (_op)
  {
    case L_NOT: return not _pr->test(sym);
  }
  
  MYLANGA_INTERNAL_ERROR();
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

maybe_fp_t ast_block::exec(symbol_table& sym)
{
  maybe_fp_t ret;
  for (auto _st : *_sts)
  {
    ret = _st->exec(sym);
    if (ret.is_valid) break;
  }

  return ret;
}

maybe_fp_t ast_var_assign_stmt::exec(symbol_table& sym)
{
  sym.set_var(_id, _ex->eval(sym));

  return maybe_fp_t();
}

maybe_fp_t ast_if_then_stmt::exec(symbol_table& sym)
{
  maybe_fp_t ret;
  if (_pr->test(sym))
    ret = _bl->exec(sym);

  return ret;
}

maybe_fp_t ast_if_then_else_stmt::exec(symbol_table& sym)
{
  maybe_fp_t ret;
  if (_pr->test(sym))
    ret = _bl1->exec(sym);
  else
    ret = _bl2->exec(sym);

  return ret;
}

maybe_fp_t ast_while_stmt::exec(symbol_table& sym)
{
  maybe_fp_t ret;
  while (_pr->test(sym))
  {
    ret = _bl->exec(sym);
    if (ret.is_valid) break;
  }

  return ret;
}

maybe_fp_t ast_return_stmt::exec(symbol_table& sym)
{
  return maybe_fp_t(_ex->eval(sym));
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void ast_plot_cmd::plot(symbol_table& sym)
{
  sym.open_scope();

  fp_t range_from = _ex1->eval(sym),
  range_step = _ex2->eval(sym),
  range_to = _ex3->eval(sym);

  for (fp_t x = range_from; x <= range_to; x += range_step)
  {
    sym.set_var(_id, x);

    fp_t x_value = _ex_x->eval(sym),
    y_value = _ex_y->eval(sym);

    cout << x_value << " " << y_value << endl;

  }

  sym.close_scope();
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool ast_literal_expr::is_valid(symbol_table& sym)
{
  return true;
}

bool ast_id_expr::is_valid(symbol_table& sym)
{
  bool res = true;
  if (not sym.var_is_declared(_id))
  {
    cerr << MYLANGA_PARSE_ERROR(_ln) << " | " << \
      "La variable \'" << *_id << "\' no se encuentra previamente declarada." << endl;
    res = false;
  }

  return res;
}

bool ast_bin_op_expr::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _ex1->is_valid(sym) and res;
  res = _ex2->is_valid(sym) and res;

  return res;
}

bool ast_uny_op_expr::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _ex->is_valid(sym) and res;

  return res;
}

bool ast_fun_call_expr::is_valid(symbol_table& sym)
{
  bool res = true;

  do
  {
    ptr<ast_fun_def> _fd = sym.get_fun_def(_id);
    if (_fd == nullptr)
    {
      cerr << MYLANGA_PARSE_ERROR(_ln) << " | " << \
        "La función \'" << *_id << "\' no se encuentra definida." << endl;
      res = false; break;
    }

    if (_fd->_ids->size() != _exs->size())
    {
      cerr << MYLANGA_PARSE_ERROR(_ln) << " | " << \
        "La función " << (*(_fd->_id)) << " recibe " << to_string(_fd->_ids->size()) << \
        " parámetro(s), pero es invocada con " <<  to_string(_exs->size()) << \
        " argumento(s)." << endl;
      res = false; break;
    }
  } while (false);
  
  for (auto _ex : *_exs)
    res = _ex->is_valid(sym) and res;

  return res;
}

bool ast_rel_pred::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _ex1->is_valid(sym) and res;
  res = _ex2->is_valid(sym) and res;

  return res;
}

bool ast_bin_l_pred::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _pr1->is_valid(sym) and res;
  res = _pr2->is_valid(sym) and res;

  return res;
}

bool ast_uny_l_pred::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _pr->is_valid(sym) and res;

  return res;
}

bool ast_block::is_valid(symbol_table& sym)
{
  bool res = true;

  for (auto _st : *_sts)
    res = _st->is_valid(sym) and res;

  return res;
}

bool ast_var_assign_stmt::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _ex->is_valid(sym) and res;

  sym.declare_var(_id);

  return res;
}

bool ast_if_then_stmt::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _pr->is_valid(sym) and res;
  res = _bl->is_valid(sym) and res;

  return res;
}

bool ast_if_then_else_stmt::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _pr->is_valid(sym) and res;
  res = _bl1->is_valid(sym) and res;
  res = _bl2->is_valid(sym) and res;
  
  return res;
}

bool ast_while_stmt::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _pr->is_valid(sym) and res;
  res = _bl->is_valid(sym) and res;

  return res;
}

bool ast_return_stmt::is_valid(symbol_table& sym)
{
  bool res = true;
  res = _ex->is_valid(sym) and res;

  return res;
}

bool ast_plot_cmd::is_valid(symbol_table& sym)
{
  bool res = true;

  sym.open_scope();

  do
  {
    res = _ex1->is_valid(sym) and res;
    res = _ex2->is_valid(sym) and res;
    res = _ex3->is_valid(sym) and res;
    if (not res) break;

    fp_t range_from = _ex1->eval(sym),
    range_step = _ex2->eval(sym),
    range_to = _ex3->eval(sym);

    if (not (range_from <= range_to and 0 < range_step))
    {
      cerr << MYLANGA_PARSE_ERROR(_ln) << " | " << \
        "En la instrucción de plot, el rango de evaluación es inválido; un rango válido a..d..b debe cumplir a <= b y 0 < d." << endl;
      res = false;
    }

    if (not (_ex_x->is_plottable() and _ex_y->is_plottable()))
    {
      cerr << MYLANGA_PARSE_ERROR(_ln) << " | " << \
        "En la instrucción de plot, las expresiones a evaluar deben ser de tipo llamado a función." << endl;
      res = false;
    }

    sym.declare_var(_id);

    res = _ex_x->is_valid(sym) and res;
    res = _ex_y->is_valid(sym) and res;

  } while (false);

  sym.close_scope();

  return res;
}

bool has_repeated_elements(ptr<list<ptr<id>>> _ids);
bool ast_fun_def::is_valid(symbol_table& sym)
{
  bool res = true;

  if (sym.get_fun_def(_id) != nullptr)
  {
    cerr << MYLANGA_PARSE_ERROR(_ln) << " | " << \
      "La función \'" << *_id << "\' ya está definida." << endl;
    res = false;
  }

  if (has_repeated_elements(_ids))
  {
    cerr << MYLANGA_PARSE_ERROR(_ln) << " | " << \
      "La función \'" << *_id << "\' contiene parámetros repetidos en su definición." << endl;
    res = false;
  }

  // para soportar recursión
  sym.define_fun(shared_from_this());
  sym.open_scope();

  for (auto _id : *_ids)
    sym.declare_var(_id);

  res = _bl->is_valid(sym) and res;

  sym.close_scope();
  sym.undefine_fun(shared_from_this());

  return res;
}

bool has_repeated_elements(ptr<list<ptr<id>>> _ids)
{
  for (auto _id1 : *_ids)
    for (auto _id2 : *_ids)
      if (_id1 != _id2 and *_id1 == *_id2)
        return true;
  return false;
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool ast_program::run()
{
  symbol_table sym;

  bool is_valid = true;
  for (auto _fd : *_fds)
  {
    if (not (_fd->is_valid(sym)))
    {
      is_valid = false;
      continue;
    }
    
    sym.define_fun(_fd);
  }

  is_valid = _pc->is_valid(sym) and is_valid;
  
  if (is_valid)
    _pc->plot(sym);

  return is_valid;
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool ast_syntax_error::is_valid(symbol_table& sym)
{
  cerr << MYLANGA_SYNTAX_ERROR(_ln) << " | " << _str << endl;
  return false;
}

fp_t ast_syntax_error::eval(symbol_table& sym)
{
  MYLANGA_INTERNAL_ERROR();
}

bool ast_syntax_error::test(symbol_table& sym)
{
  MYLANGA_INTERNAL_ERROR();
}

maybe_fp_t ast_syntax_error::exec(symbol_table& sym)
{
  MYLANGA_INTERNAL_ERROR();
}

void ast_syntax_error::plot(symbol_table& sym)
{
  MYLANGA_INTERNAL_ERROR();
}

bool ast_syntax_error::run()
{
  MYLANGA_INTERNAL_ERROR();
}