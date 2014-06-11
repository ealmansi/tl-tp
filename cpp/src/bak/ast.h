#ifndef MYLANGA_AST_H
#define MYLANGA_AST_H

#include "mylanga_ast_meta.h"

#include <memory>
#include <string>
#include <list>
using namespace std;

typedef string id;
template <typename T> using ptr = shared_ptr<T>;
#define mp make_shared

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */


struct ast_program;
#define ast_program_fields               \
  ptr<list<ptr<ast_fun_def>>>, _fds,     \
  ptr<ast_plot_cmd>, _pc

struct ast_fun_def;
#define ast_fun_def_fields    \
  ptr<id>, _id,               \
  ptr<list<ptr<id>>>, _ids,   \
  ptr<ast_block>, _bl

struct ast_plot_cmd;
#define ast_plot_cmd_fields    \
  ptr<ast_fun_call>, _fc1,     \
  ptr<ast_fun_call>, _fc2,     \
  ptr<id>, _id,                \
  ptr<ast_const_value>, _cv1,  \
  ptr<ast_const_value>, _cv2,  \
  ptr<ast_const_value>, _cv3

struct ast_block;
#define ast_block_fields          \
  ptr<list<ptr<ast_stmt>>>, _sts

struct ast_stmt;

struct ast_var_assign_stmt;
#define ast_var_assign_stmt_fields  \
  ptr<id>, _id,                     \
  ptr<ast_expr>, _ex

struct ast_if_then_stmt;
#define ast_if_then_stmt_fields \
  ptr<ast_pred>, _pr,           \
  ptr<ast_block>, _bl

struct ast_if_then_else_stmt;
#define ast_if_then_else_stmt_fields  \
  ptr<ast_pred>, _pr,                 \
  ptr<ast_block>, _bl1,               \
  ptr<ast_block>, _bl2

struct ast_while_stmt;
#define ast_while_stmt_fields \
  ptr<ast_pred>, _pr,         \
  ptr<ast_block>, _bl

struct ast_return_stmt;
#define ast_return_stmt_fields  \
  ptr<ast_expr>, _ex

struct ast_pred;

struct ast_rel_pred;
#define ast_rel_pred_fields     \
  ptr<ast_expr>, _ex1,          \
  int, _op,                     \
  ptr<ast_expr>, _ex2

struct ast_bin_l_pred;
#define ast_bin_l_pred_fields     \
  ptr<ast_pred>, _pr1,            \
  int, _op,                       \
  ptr<ast_pred>, _pr2

struct ast_uny_l_pred;
#define ast_uny_l_pred_fields     \
  int, _op,                       \
  ptr<ast_pred>, _pr

struct ast_expr;

struct ast_id_expr;
#define ast_id_expr_fields \
  ptr<id>, _id

struct ast_bin_op_expr;
#define ast_bin_op_expr_fields \
  ptr<ast_expr>, _ex1,         \
  int, _op,                    \
  ptr<ast_expr>, _ex2

struct ast_uny_op_expr;
#define ast_uny_op_expr_fields \
  int, _op,                    \
  ptr<ast_expr>, _ex

struct ast_const_value;
#define ast_const_value_fields \
  bool, _neg

struct ast_int_literal;
#define ast_int_literal_fields \
  ptr<string>, _str

struct ast_fp_literal;
#define ast_fp_literal_fields \
  ptr<string>, _str

struct ast_pi_literal;

struct ast_neg_int_literal;
#define ast_neg_int_literal_fields \
  ptr<string>, _str

struct ast_neg_fp_literal;
#define ast_neg_fp_literal_fields \
  ptr<string>, _str

struct ast_neg_pi_literal;

struct ast_fun_call;
#define ast_fun_call_fields \
  ptr<id>, _id,             \
  ptr<list<ptr<ast_expr>>>, _args

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct ast_program
{
  ast_program(ctor_params(ast_program_fields))
    : init_list(ast_program_fields) {}

  field_decls(ast_program_fields);
};

struct ast_fun_def
{
  ast_fun_def(ctor_params(ast_fun_def_fields))
    : init_list(ast_fun_def_fields) {}

  field_decls(ast_fun_def_fields);
};

struct ast_plot_cmd
{
  ast_plot_cmd(ctor_params(ast_plot_cmd_fields))
    : init_list(ast_plot_cmd_fields) {}

  field_decls(ast_plot_cmd_fields);
};

struct ast_block
{
  ast_block(ctor_params(ast_block_fields))
    : init_list(ast_block_fields) {}

  field_decls(ast_block_fields);
};

struct ast_stmt
{

};

struct ast_var_assign_stmt : ast_stmt
{
  ast_var_assign_stmt(ctor_params(ast_var_assign_stmt_fields))
    : init_list(ast_var_assign_stmt_fields) {}

  field_decls(ast_var_assign_stmt_fields);
};

struct ast_if_then_stmt : ast_stmt
{
  ast_if_then_stmt(ctor_params(ast_if_then_stmt_fields))
    : init_list(ast_if_then_stmt_fields) {}

  field_decls(ast_if_then_stmt_fields);
};

struct ast_if_then_else_stmt : ast_stmt
{
  ast_if_then_else_stmt(ctor_params(ast_if_then_else_stmt_fields))
    : init_list(ast_if_then_else_stmt_fields) {}

  field_decls(ast_if_then_else_stmt_fields);
};

struct ast_while_stmt : ast_stmt
{
  ast_while_stmt(ctor_params(ast_while_stmt_fields))
    : init_list(ast_while_stmt_fields) {}

  field_decls(ast_while_stmt_fields);
};

struct ast_return_stmt : ast_stmt
{
  ast_return_stmt(ctor_params(ast_return_stmt_fields))
    : init_list(ast_return_stmt_fields) {}

  field_decls(ast_return_stmt_fields);
};

struct ast_pred
{

};

struct ast_rel_pred : ast_pred
{
  ast_rel_pred(ctor_params(ast_rel_pred_fields))
    : init_list(ast_rel_pred_fields) {}

  field_decls(ast_rel_pred_fields);
};

struct ast_bin_l_pred : ast_pred
{
  ast_bin_l_pred(ctor_params(ast_bin_l_pred_fields))
    : init_list(ast_bin_l_pred_fields) {}

  field_decls(ast_bin_l_pred_fields);
};

struct ast_uny_l_pred : ast_pred
{
  ast_uny_l_pred(ctor_params(ast_uny_l_pred_fields))
    : init_list(ast_uny_l_pred_fields) {}

  field_decls(ast_uny_l_pred_fields);
};

struct ast_expr
{

};

struct ast_id_expr : ast_expr
{
  ast_id_expr(ctor_params(ast_id_expr_fields))
    : init_list(ast_id_expr_fields) {}

  field_decls(ast_id_expr_fields);
};

struct ast_bin_op_expr : ast_expr
{
  ast_bin_op_expr(ctor_params(ast_bin_op_expr_fields))
    : init_list(ast_bin_op_expr_fields) {}

  field_decls(ast_bin_op_expr_fields);
};

struct ast_uny_op_expr : ast_expr
{
  ast_uny_op_expr(ctor_params(ast_uny_op_expr_fields))
    : init_list(ast_uny_op_expr_fields) {}

  field_decls(ast_uny_op_expr_fields);
};

struct ast_const_value
{
  ast_const_value(ctor_params(ast_const_value_fields))
    : init_list(ast_const_value_fields) {}

  field_decls(ast_const_value_fields);
};

struct ast_int_literal : ast_expr, ast_const_value
{
  ast_int_literal(ctor_params(ast_int_literal_fields))
    : init_list(ast_int_literal_fields), ast_const_value(false) {}

  field_decls(ast_int_literal_fields);
};

struct ast_fp_literal : ast_expr, ast_const_value
{
  ast_fp_literal(ctor_params(ast_fp_literal_fields))
    : init_list(ast_fp_literal_fields), ast_const_value(false) {}

  field_decls(ast_fp_literal_fields);
};

struct ast_pi_literal : ast_expr, ast_const_value
{
  ast_pi_literal()
    : ast_const_value(false) {}
};

struct ast_neg_int_literal : ast_const_value
{
  ast_neg_int_literal(ctor_params(ast_neg_int_literal_fields))
    : init_list(ast_neg_int_literal_fields), ast_const_value(true) {}

  field_decls(ast_neg_int_literal_fields);
};

struct ast_neg_fp_literal : ast_const_value
{
  ast_neg_fp_literal(ctor_params(ast_neg_fp_literal_fields))
    : init_list(ast_neg_fp_literal_fields), ast_const_value(true) {}

  field_decls(ast_neg_fp_literal_fields);
};

struct ast_neg_pi_literal : ast_const_value
{
  ast_neg_pi_literal()
    : ast_const_value(true) {}
};

struct ast_fun_call : ast_expr
{
  ast_fun_call(ctor_params(ast_fun_call_fields))
    : init_list(ast_fun_call_fields) {}

  field_decls(ast_fun_call_fields);
};

#endif /* MYLANGA_AST_H */