#ifndef MYLANGA_AST_H
#define MYLANGA_AST_H

#include "mylanga_ast_meta.h"

#include <string>
#include <list>
using namespace std;
typedef string id;

struct ast_expr;
struct ast_id_expr;
struct ast_bin_op_expr;
struct ast_uny_op_expr;
struct ast_pred;
struct ast_rel_pred;
struct ast_bin_l_pred;
struct ast_uny_l_pred;
struct ast_const_value;
struct ast_int_literal;
struct ast_fp_literal;
struct ast_pi_literal;
struct ast_neg_int_literal;
struct ast_neg_fp_literal;
struct ast_neg_pi_literal;
struct ast_fun_call;
struct ast_stmt;
struct ast_block;
struct ast_var_assign_stmt;
struct ast_if_then_stmt;
struct ast_if_then_else_stmt;
struct ast_while_stmt;
struct ast_return_stmt;
struct ast_plot_cmd;
struct ast_fun_def;
struct ast_program;

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

typedef long double fp_t;

struct symbol_table
{
  bool fun_is_defined(id* _id);
  void define_fun(id* _id, list<id*>* _ids, ast_block*);
  list<id*>* get_fun_params(id* _id);
};

struct context_data
{
  void push_scope();
  void pop_scope();
  void set_var(id* _id, fp_t x);
};

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#define ast_program_fields    \
  list<ast_fun_def*>*, _fds,  \
  ast_plot_cmd*, _pc

#define ast_fun_def_fields    \
  id*, _id,                   \
  list<id*>*, _ids,           \
  ast_block*, _bl

#define ast_plot_cmd_fields   \
  ast_fun_call*, _fc1,        \
  ast_fun_call*, _fc2,        \
  id*, _id,                   \
  ast_const_value*, _cv1,     \
  ast_const_value*, _cv2,     \
  ast_const_value*, _cv3

#define ast_block_fields      \
  list<ast_stmt*>*, _sts

#define ast_var_assign_stmt_fields       \
  id*, _id,                              \
  ast_expr*, _ex

#define ast_if_then_stmt_fields        \
  ast_pred*, _pr,                      \
  ast_block*, _bl

#define ast_if_then_else_stmt_fields    \
  ast_pred*, _pr,                       \
  ast_block*, _bl1,                     \
  ast_block*, _bl2

#define ast_while_stmt_fields           \
  ast_pred*, _pr,                       \
  ast_block*, _bl

#define ast_return_stmt_fields          \
  ast_expr*, _ex

#define ast_rel_pred_fields    \
  ast_expr*, _ex1,             \
  int, _op,                    \
  ast_expr*, _ex2

#define ast_bin_l_pred_fields     \
  ast_pred*, _pr1,                \
  int, _op,                       \
  ast_pred*, _pr2

#define ast_uny_l_pred_fields     \
  int, _op,                       \
  ast_pred*, _pr

#define ast_id_expr_fields        \
  id*, _id

#define ast_bin_op_expr_fields    \
  ast_expr*, _ex1,                \
  int, _op,                       \
  ast_expr*, _ex2

#define ast_uny_op_expr_fields   \
  int, _op,                      \
  ast_expr*, _ex

#define ast_int_literal_fields    \
  string*, _str

#define ast_fp_literal_fields     \
  string*, _str

#define ast_neg_int_literal_fields  \
  string*, _str

#define ast_neg_fp_literal_fields   \
  string*, _str

#define ast_fun_call_fields    \
  id*, _id,                    \
  list<ast_expr*>*, _exs

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct ast_expr
{
  virtual ~ast_expr() {}
  virtual fp_t eval(symbol_table& sym, context_data& cd) = 0;
};

struct ast_id_expr : ast_expr
{
  ast_id_expr(ctor_params(ast_id_expr_fields))
    : init_list(ast_id_expr_fields) {}
  virtual ~ast_id_expr() { delete_fields(ast_id_expr_fields); }
  virtual fp_t eval(symbol_table& sym, context_data& cd);

  field_decls(ast_id_expr_fields);
};

struct ast_bin_op_expr : ast_expr
{
  ast_bin_op_expr(ctor_params(ast_bin_op_expr_fields))
    : init_list(ast_bin_op_expr_fields) {}
  virtual ~ast_bin_op_expr() { delete_each(_ex1, _ex2); }
  virtual fp_t eval(symbol_table& sym, context_data& cd);

  field_decls(ast_bin_op_expr_fields);
};

struct ast_uny_op_expr : ast_expr
{
  ast_uny_op_expr(ctor_params(ast_uny_op_expr_fields))
    : init_list(ast_uny_op_expr_fields) {}
  virtual ~ast_uny_op_expr() { delete_each(_ex); }
  virtual fp_t eval(symbol_table& sym, context_data& cd);

  field_decls(ast_uny_op_expr_fields);
};

struct ast_pred
{
  virtual ~ast_pred() {}
};

struct ast_rel_pred : ast_pred
{
  ast_rel_pred(ctor_params(ast_rel_pred_fields))
    : init_list(ast_rel_pred_fields) {}
  virtual ~ast_rel_pred() { delete_each(_ex1, _ex2); }

  field_decls(ast_rel_pred_fields);
};

struct ast_bin_l_pred : ast_pred
{
  ast_bin_l_pred(ctor_params(ast_bin_l_pred_fields))
    : init_list(ast_bin_l_pred_fields) {}
  virtual ~ast_bin_l_pred() { delete_each(_pr1, _pr2); }

  field_decls(ast_bin_l_pred_fields);
};

struct ast_uny_l_pred : ast_pred
{
  ast_uny_l_pred(ctor_params(ast_uny_l_pred_fields))
    : init_list(ast_uny_l_pred_fields) {}
  virtual ~ast_uny_l_pred() { delete_each(_pr); }

  field_decls(ast_uny_l_pred_fields);
};

struct ast_const_value
{
  virtual ~ast_const_value() {}
  virtual fp_t get_value() = 0;
};

struct ast_int_literal : ast_expr, ast_const_value
{
  ast_int_literal(ctor_params(ast_int_literal_fields))
    : init_list(ast_int_literal_fields) {}
  ~ast_int_literal() { delete_fields(ast_int_literal_fields); }
  virtual fp_t get_value();
  virtual fp_t eval(symbol_table& sym, context_data& cd);

  field_decls(ast_int_literal_fields);
};

struct ast_fp_literal : ast_expr, ast_const_value
{
  ast_fp_literal(ctor_params(ast_fp_literal_fields))
    : init_list(ast_fp_literal_fields) {}
  ~ast_fp_literal() { delete_fields(ast_fp_literal_fields); }
  virtual fp_t get_value();
  virtual fp_t eval(symbol_table& sym, context_data& cd);

  field_decls(ast_fp_literal_fields);
};

struct ast_pi_literal : ast_expr, ast_const_value
{
  virtual fp_t get_value();
  virtual fp_t eval(symbol_table& sym, context_data& cd);
};

struct ast_neg_int_literal : ast_const_value
{
  ast_neg_int_literal(ctor_params(ast_neg_int_literal_fields))
    : init_list(ast_neg_int_literal_fields) {}
  ~ast_neg_int_literal() { delete_fields(ast_neg_int_literal_fields); }
  virtual fp_t get_value();

  field_decls(ast_neg_int_literal_fields);
};

struct ast_neg_fp_literal : ast_const_value
{
  ast_neg_fp_literal(ctor_params(ast_neg_fp_literal_fields))
    : init_list(ast_neg_fp_literal_fields) {}
  ~ast_neg_fp_literal() { delete_fields(ast_neg_fp_literal_fields); }
  virtual fp_t get_value();

  field_decls(ast_neg_fp_literal_fields);
};

struct ast_neg_pi_literal : ast_const_value
{
  virtual fp_t get_value();
};

struct ast_fun_call : ast_expr
{
  ast_fun_call(ctor_params(ast_fun_call_fields))
    : init_list(ast_fun_call_fields) {}
  virtual ~ast_fun_call() { delete_elems(_exs); delete_fields(ast_fun_call_fields); }
  virtual fp_t eval(symbol_table& sym, context_data& cd);

  field_decls(ast_fun_call_fields);
};

struct ast_stmt
{
  virtual ~ast_stmt() {}
};

struct ast_block
{
  ast_block(ctor_params(ast_block_fields))
    : init_list(ast_block_fields) {}
  ~ast_block() { delete_elems(_sts); delete_fields(ast_block_fields); }

  field_decls(ast_block_fields);
};

struct ast_var_assign_stmt : ast_stmt
{
  ast_var_assign_stmt(ctor_params(ast_var_assign_stmt_fields))
    : init_list(ast_var_assign_stmt_fields) {}
  virtual ~ast_var_assign_stmt() { delete_fields(ast_var_assign_stmt_fields); }

  field_decls(ast_var_assign_stmt_fields);
};

struct ast_if_then_stmt : ast_stmt
{
  ast_if_then_stmt(ctor_params(ast_if_then_stmt_fields))
    : init_list(ast_if_then_stmt_fields) {}
  virtual ~ast_if_then_stmt() { delete_fields(ast_if_then_stmt_fields); }

  field_decls(ast_if_then_stmt_fields);
};

struct ast_if_then_else_stmt : ast_stmt
{
  ast_if_then_else_stmt(ctor_params(ast_if_then_else_stmt_fields))
    : init_list(ast_if_then_else_stmt_fields) {}
  virtual ~ast_if_then_else_stmt() { delete_fields(ast_if_then_else_stmt_fields); }

  field_decls(ast_if_then_else_stmt_fields);
};

struct ast_while_stmt : ast_stmt
{
  ast_while_stmt(ctor_params(ast_while_stmt_fields))
    : init_list(ast_while_stmt_fields) {}
  virtual ~ast_while_stmt() { delete_fields(ast_while_stmt_fields); }

  field_decls(ast_while_stmt_fields);
};

struct ast_return_stmt : ast_stmt
{
  ast_return_stmt(ctor_params(ast_return_stmt_fields))
    : init_list(ast_return_stmt_fields) {}
  virtual ~ast_return_stmt() { delete_fields(ast_return_stmt_fields); }

  field_decls(ast_return_stmt_fields);
};

struct ast_plot_cmd
{
  ast_plot_cmd(ctor_params(ast_plot_cmd_fields))
    : init_list(ast_plot_cmd_fields) {}
  ~ast_plot_cmd() { delete_fields(ast_plot_cmd_fields); }

  void plot(symbol_table& sym);

  field_decls(ast_plot_cmd_fields);
};

struct ast_fun_def
{
  ast_fun_def(ctor_params(ast_fun_def_fields))
    : init_list(ast_fun_def_fields) {}
  ~ast_fun_def() { delete_elems(_ids); delete_fields(ast_fun_def_fields); }

  void load(symbol_table& sym);

  field_decls(ast_fun_def_fields);
};

struct ast_program
{
  ast_program(ctor_params(ast_program_fields))
    : init_list(ast_program_fields) {}
  ~ast_program() { delete_elems(_fds); delete_fields(ast_program_fields); }

  void run();

  field_decls(ast_program_fields);
};

#endif /* MYLANGA_AST_H */