#include "mylanga_ast.h"

#include <iostream>
using namespace std;

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

const fp_t FP_T_PI = 3.14159265358979323846264338327950288419716939937510L;

fp_t stofp_t(const string& str)
{
  return stold(str);
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool symbol_table::fun_is_defined(ptr<id> _id)
{
  // todo
  return true;
}

void symbol_table::define_fun(ptr<id> _id, ptr<list<ptr<id>>> _ids, ptr<ast_block>)
{
  // todo
  return;
}

ptr<list<ptr<id>>> symbol_table::get_fun_params(ptr<id> _id)
{
  // todo
  return mp<list<ptr<id>>>();
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void context_data::push_scope()
{
  // todo
  return;
}

void context_data::pop_scope()
{
  // todo
  return;
}

void context_data::set_var(ptr<id> _id, fp_t x)
{
  // todo
  return;
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

fp_t ast_id_expr::eval(symbol_table& sym, context_data& cd)
{
  // todo
  return 0.0;
}

fp_t ast_bin_op_expr::eval(symbol_table& sym, context_data& cd)
{
  // todo
  return 0.0;
}

fp_t ast_uny_op_expr::eval(symbol_table& sym, context_data& cd)
{
  // todo
  return 0.0;
}

fp_t ast_literal::eval(symbol_table& sym, context_data& cd)
{
  return _vl;
}

fp_t ast_fun_call::eval(symbol_table& sym, context_data& cd)
{
  if (not sym.fun_is_defined(_id))
  {
    // error
    return 0.0;
  }
  
  ptr<list<ptr<id>>> _ids = sym.get_fun_params(_id);
  if (_ids->size() != _exs->size())
  {
    // error
    return 0.0;
  }

  list<fp_t> args;
  for (auto _ex : *_exs)
    args.push_back(_ex->eval(sym, cd));

  cd.push_scope();
  auto _id_it = _ids->begin();
  auto arg_it = args.begin();
  for (;_id_it != _ids->end() and arg_it != args.end(); ++_id_it, ++arg_it)
    cd.set_var(*_id_it, *arg_it);

  // ejecuto el block

  cd.pop_scope();
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool ast_rel_pred::eval(symbol_table& sym, context_data& cd)
{
  // todo
  return true;
}

bool ast_bin_l_pred::eval(symbol_table& sym, context_data& cd)
{
  // todo
  return true;
}

bool ast_uny_l_pred::eval(symbol_table& sym, context_data& cd)
{
  // todo
  return true;
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void ast_plot_cmd::plot(symbol_table& sym)
{
  fp_t range_from = _lt1->_vl,
  range_step = _lt2->_vl,
  range_to = _lt3->_vl;

  if (not (range_from <= range_to) or range_step < 0)
  {
    // error
    return;
  }

  for (fp_t x = range_from; x <= range_to; x += range_step)
  {
    context_data cd;
    cd.push_scope();
    cd.set_var(_id, x);

    fp_t x_value = _fc1->eval(sym, cd),
    y_value = _fc2->eval(sym, cd);

    // guardar (x_value, y_value)

    cd.pop_scope();
  }
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool has_repeated_elements(ptr<list<ptr<id>>> _ids)
{
  for (auto _id1 : *_ids)
    for (auto _id2 : *_ids)
      if (_id1 != _id2 and *_id1 == *_id2)
        return true;
  return false;
}

void ast_fun_def::load(symbol_table& sym)
{
  if (sym.fun_is_defined(_id))
  {
    // error
    return;
  }

  if (has_repeated_elements(_ids))
  {
    // error
    return;
  }

  sym.define_fun(_id, _ids, _bl);
}

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void ast_program::run()
{
  symbol_table sym;

  for (auto _fd : *_fds)
    _fd->load(sym);
  _pc->plot(sym);
}