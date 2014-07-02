#ifndef MYLANGA_AST_H
#define MYLANGA_AST_H

#include "mylanga_fp_t.h"
#include "mylanga_ast_meta.h"

#include <string>
#include <list>
#include <stack>
#include <map>
using namespace std;
typedef string id;

#include <memory>
#define ptr shared_ptr
#define mp make_shared

struct ast_expr;
struct ast_literal_expr;
struct ast_id_expr;
struct ast_bin_op_expr;
struct ast_uny_op_expr;
struct ast_pred;
struct ast_rel_pred;
struct ast_bin_l_pred;
struct ast_uny_l_pred;
struct ast_fun_call_expr;
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
struct ast_syntax_error;

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#define ast_node_fields                  \
  int, _ln                                                

#define ast_program_fields               \
  ptr<list<ptr<ast_fun_def>>>, _fds,     \
  ptr<ast_plot_cmd>, _pc                 

#define ast_fun_def_fields               \
  ptr<id>, _id,                          \
  ptr<list<ptr<id>>>, _ids,              \
  ptr<ast_block>, _bl                    

#define ast_plot_cmd_fields              \
  ptr<ast_expr>, _ex_x,                  \
  ptr<ast_expr>, _ex_y,                  \
  ptr<id>, _id,                          \
  ptr<ast_expr>, _ex1,                   \
  ptr<ast_expr>, _ex2,                   \
  ptr<ast_expr>, _ex3                  

#define ast_block_fields                 \
  ptr<list<ptr<ast_stmt>>>, _sts         

#define ast_var_assign_stmt_fields       \
  ptr<id>, _id,                          \
  ptr<ast_expr>, _ex                     

#define ast_if_then_stmt_fields          \
  ptr<ast_pred>, _pr,                    \
  ptr<ast_block>, _bl                    

#define ast_if_then_else_stmt_fields     \
  ptr<ast_pred>, _pr,                    \
  ptr<ast_block>, _bl1,                  \
  ptr<ast_block>, _bl2                   

#define ast_while_stmt_fields            \
  ptr<ast_pred>, _pr,                    \
  ptr<ast_block>, _bl                    

#define ast_return_stmt_fields           \
  ptr<ast_expr>, _ex                     

#define ast_rel_pred_fields              \
  ptr<ast_expr>, _ex1,                   \
  int, _op,                              \
  ptr<ast_expr>, _ex2                    

#define ast_bin_l_pred_fields            \
  ptr<ast_pred>, _pr1,                   \
  int, _op,                              \
  ptr<ast_pred>, _pr2                    

#define ast_uny_l_pred_fields            \
  int, _op,                              \
  ptr<ast_pred>, _pr                     

#define ast_literal_expr_fields          \
  fp_t, _vl

#define ast_id_expr_fields               \
  ptr<id>, _id                           

#define ast_bin_op_expr_fields           \
  ptr<ast_expr>, _ex1,                   \
  int, _op,                              \
  ptr<ast_expr>, _ex2                    

#define ast_uny_op_expr_fields           \
  int, _op,                              \
  ptr<ast_expr>, _ex                     

#define ast_fun_call_expr_fields         \
  ptr<id>, _id,                          \
  ptr<list<ptr<ast_expr>>>, _exs

#define ast_syntax_error_fields          \
  string, _str                           

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct symbol_table
{
  void define_fun(ptr<ast_fun_def> _fd);
  void undefine_fun(ptr<ast_fun_def> _fd);
  ptr<ast_fun_def> get_fun_def(ptr<id> _id);

  void open_scope();
  void close_scope();

  void declare_var(ptr<id> _id);
  bool var_is_declared(ptr<id> _id);
  void set_var(ptr<id> _id, fp_t value);
  maybe_fp_t get_var(ptr<id> _id);
  bool var_is_set(ptr<id> _id);

  map<id,ptr<ast_fun_def>> functions;
  stack<map<id,fp_t>> scopes;
};


/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct ast_node
{
  ast_node() {}
  ast_node(ctor_params(ast_node_fields))
    : init_list(ast_node_fields) {}
  virtual ~ast_node() {}
  
  field_decls(ast_node_fields);
};

struct ast_expr : virtual ast_node
{
  ast_expr() {}
  virtual ~ast_expr() {}
  virtual bool is_valid(symbol_table& sym) = 0;
  virtual fp_t eval(symbol_table& sym) = 0;
  virtual bool is_plottable() { return false; };
};

struct ast_literal_expr : virtual ast_node, ast_expr
{
  ast_literal_expr() {}
  ast_literal_expr(ctor_params(ast_literal_expr_fields), int _ln)
    : init_list(ast_literal_expr_fields), ast_node(_ln) {}
  ~ast_literal_expr() {}
  virtual bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_literal_expr_fields);
};

struct ast_id_expr : virtual ast_node, ast_expr
{
  ast_id_expr() {}
  ast_id_expr(ctor_params(ast_id_expr_fields), int _ln)
    : init_list(ast_id_expr_fields), ast_node(_ln) {}
  ~ast_id_expr()  {}
  virtual bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_id_expr_fields);
};

struct ast_bin_op_expr : virtual ast_node, ast_expr
{
  ast_bin_op_expr() {}
  ast_bin_op_expr(ctor_params(ast_bin_op_expr_fields), int _ln)
    : init_list(ast_bin_op_expr_fields), ast_node(_ln) {}
  ~ast_bin_op_expr()  {}
  virtual bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_bin_op_expr_fields);
};

struct ast_uny_op_expr : virtual ast_node, ast_expr
{
  ast_uny_op_expr() {}
  ast_uny_op_expr(ctor_params(ast_uny_op_expr_fields), int _ln)
    : init_list(ast_uny_op_expr_fields), ast_node(_ln) {}
  ~ast_uny_op_expr()  {}
  virtual bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_uny_op_expr_fields);
};

struct ast_fun_call_expr : virtual ast_node, ast_expr
{
  ast_fun_call_expr() {}
  ast_fun_call_expr(ctor_params(ast_fun_call_expr_fields), int _ln)
    : init_list(ast_fun_call_expr_fields), ast_node(_ln) {}
  ~ast_fun_call_expr() {}
  virtual bool is_valid(symbol_table& sym);
  virtual fp_t eval(symbol_table& sym);
  virtual bool is_plottable() { return true; };

  field_decls(ast_fun_call_expr_fields);
};

struct ast_pred : virtual ast_node
{
  ast_pred() {}
  virtual ~ast_pred() {}
  virtual bool is_valid(symbol_table& sym) = 0;
  virtual bool test(symbol_table& sym) = 0;
};

struct ast_rel_pred : virtual ast_node, ast_pred
{
  ast_rel_pred() {}
  ast_rel_pred(ctor_params(ast_rel_pred_fields), int _ln)
    : init_list(ast_rel_pred_fields), ast_node(_ln) {}
  ~ast_rel_pred() {}
  virtual bool is_valid(symbol_table& sym);
  virtual bool test(symbol_table& sym);

  field_decls(ast_rel_pred_fields);
};

struct ast_bin_l_pred : virtual ast_node, ast_pred
{
  ast_bin_l_pred() {}
  ast_bin_l_pred(ctor_params(ast_bin_l_pred_fields), int _ln)
    : init_list(ast_bin_l_pred_fields), ast_node(_ln) {}
  ~ast_bin_l_pred() {}
  virtual bool is_valid(symbol_table& sym);
  virtual bool test(symbol_table& sym);

  field_decls(ast_bin_l_pred_fields);
};

struct ast_uny_l_pred : virtual ast_node, ast_pred
{
  ast_uny_l_pred() {}
  ast_uny_l_pred(ctor_params(ast_uny_l_pred_fields), int _ln)
    : init_list(ast_uny_l_pred_fields), ast_node(_ln) {}
  ~ast_uny_l_pred() {}
  virtual bool is_valid(symbol_table& sym);
  virtual bool test(symbol_table& sym);

  field_decls(ast_uny_l_pred_fields);
};

struct ast_stmt : virtual ast_node
{
  ast_stmt() {}
  virtual ~ast_stmt() {}
  virtual bool is_valid(symbol_table& sym) = 0;
  virtual maybe_fp_t exec(symbol_table& sym) = 0;
};

struct ast_block : virtual ast_node
{
  ast_block() {}
  ast_block(ctor_params(ast_block_fields), int _ln)
    : init_list(ast_block_fields), ast_node(_ln) {}
  ~ast_block() {}
  virtual bool is_valid(symbol_table& sym);
  virtual maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_block_fields);
};

struct ast_var_assign_stmt : virtual ast_node, ast_stmt
{
  ast_var_assign_stmt() {}
  ast_var_assign_stmt(ctor_params(ast_var_assign_stmt_fields), int _ln)
    : init_list(ast_var_assign_stmt_fields), ast_node(_ln) {}
  ~ast_var_assign_stmt()  {}
  virtual bool is_valid(symbol_table& sym);
  virtual maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_var_assign_stmt_fields);
};

struct ast_if_then_stmt : virtual ast_node, ast_stmt
{
  ast_if_then_stmt() {}
  ast_if_then_stmt(ctor_params(ast_if_then_stmt_fields), int _ln)
    : init_list(ast_if_then_stmt_fields), ast_node(_ln) {}
  ~ast_if_then_stmt() {}
  virtual bool is_valid(symbol_table& sym);
  virtual maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_if_then_stmt_fields);
};

struct ast_if_then_else_stmt : virtual ast_node, ast_stmt
{
  ast_if_then_else_stmt() {}
  ast_if_then_else_stmt(ctor_params(ast_if_then_else_stmt_fields), int _ln)
    : init_list(ast_if_then_else_stmt_fields), ast_node(_ln) {}
  ~ast_if_then_else_stmt()  {}
  virtual bool is_valid(symbol_table& sym);
  virtual maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_if_then_else_stmt_fields);
};

struct ast_while_stmt : virtual ast_node, ast_stmt
{
  ast_while_stmt() {}
  ast_while_stmt(ctor_params(ast_while_stmt_fields), int _ln)
    : init_list(ast_while_stmt_fields), ast_node(_ln) {}
  ~ast_while_stmt() {}
  virtual bool is_valid(symbol_table& sym);
  virtual maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_while_stmt_fields);
};

struct ast_return_stmt : virtual ast_node, ast_stmt
{
  ast_return_stmt() {}
  ast_return_stmt(ctor_params(ast_return_stmt_fields), int _ln)
    : init_list(ast_return_stmt_fields), ast_node(_ln) {}
  ~ast_return_stmt()  {}
  virtual bool is_valid(symbol_table& sym);
  virtual maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_return_stmt_fields);
};

struct ast_plot_cmd : virtual ast_node
{
  ast_plot_cmd() {}
  ast_plot_cmd(ctor_params(ast_plot_cmd_fields), int _ln)
    : init_list(ast_plot_cmd_fields), ast_node(_ln) {}
  ~ast_plot_cmd() {}
  virtual bool is_valid(symbol_table& sym);
  virtual void plot(symbol_table& sym);

  field_decls(ast_plot_cmd_fields);
};

struct ast_fun_def : virtual ast_node, enable_shared_from_this<ast_fun_def>
{
  ast_fun_def() {}
  ast_fun_def(ctor_params(ast_fun_def_fields), int _ln)
    : init_list(ast_fun_def_fields), ast_node(_ln) {}
  ~ast_fun_def() {}
  virtual bool is_valid(symbol_table& sym);

  field_decls(ast_fun_def_fields);
};

struct ast_program : virtual ast_node
{
  ast_program() {}
  ast_program(ctor_params(ast_program_fields), int _ln)
    : init_list(ast_program_fields), ast_node(_ln) {}
  ~ast_program() {}
  virtual bool run();

  field_decls(ast_program_fields);
};

struct ast_syntax_error : virtual ast_node, ast_program, ast_fun_def,
  ast_plot_cmd, ast_block, ast_stmt, ast_pred, ast_expr
{
  ast_syntax_error() {}
  ast_syntax_error(ctor_params(ast_syntax_error_fields), int _ln)
    : init_list(ast_syntax_error_fields), ast_node(_ln) {}
  ~ast_syntax_error()  {}
  virtual bool is_valid(symbol_table& sym);
  virtual fp_t eval(symbol_table& sym);
  virtual bool test(symbol_table& sym);
  virtual maybe_fp_t exec(symbol_table& sym);
  virtual void plot(symbol_table& sym);
  virtual bool run();

  field_decls(ast_syntax_error_fields);
};


#endif /* MYLANGA_AST_H */