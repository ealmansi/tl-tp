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
template <typename T>
using ptr = shared_ptr<T>;
#define mp make_shared

struct ast_expr;
struct ast_id_expr;
struct ast_bin_op_expr;
struct ast_uny_op_expr;
struct ast_pred;
struct ast_rel_pred;
struct ast_bin_l_pred;
struct ast_uny_l_pred;
struct ast_literal;
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

#define ast_program_fields               \
  ptr<list<ptr<ast_fun_def>>>, _fds,     \
  ptr<ast_plot_cmd>, _pc                 

#define ast_fun_def_fields               \
  ptr<id>, _id,                          \
  ptr<list<ptr<id>>>, _ids,              \
  ptr<ast_block>, _bl                    

#define ast_plot_cmd_fields              \
  ptr<ast_fun_call>, _fc1,               \
  ptr<ast_fun_call>, _fc2,               \
  ptr<id>, _id,                          \
  ptr<ast_literal>, _lt1,                \
  ptr<ast_literal>, _lt2,                \
  ptr<ast_literal>, _lt3                  

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

#define ast_id_expr_fields               \
  ptr<id>, _id                           

#define ast_bin_op_expr_fields           \
  ptr<ast_expr>, _ex1,                   \
  int, _op,                              \
  ptr<ast_expr>, _ex2                    

#define ast_uny_op_expr_fields           \
  int, _op,                              \
  ptr<ast_expr>, _ex                     

#define ast_literal_fields               \
  fp_t, _vl                              \

#define ast_fun_call_fields              \
  ptr<id>, _id,                          \
  ptr<list<ptr<ast_expr>>>, _exs

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct symbol_table
{
  void define_fun(ptr<ast_fun_def> _fd);
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

struct ast_expr
{
  virtual ~ast_expr() {}
  virtual bool is_valid(symbol_table& sym) = 0;
  virtual fp_t eval(symbol_table& sym) = 0;
};

struct ast_id_expr : ast_expr
{
  ast_id_expr(ctor_params(ast_id_expr_fields))
    : init_list(ast_id_expr_fields) {}
  ~ast_id_expr()  {}
  bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_id_expr_fields);
};

struct ast_bin_op_expr : ast_expr
{
  ast_bin_op_expr(ctor_params(ast_bin_op_expr_fields))
    : init_list(ast_bin_op_expr_fields) {}
  ~ast_bin_op_expr()  {}
  bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_bin_op_expr_fields);
};

struct ast_uny_op_expr : ast_expr
{
  ast_uny_op_expr(ctor_params(ast_uny_op_expr_fields))
    : init_list(ast_uny_op_expr_fields) {}
  ~ast_uny_op_expr()  {}
  bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_uny_op_expr_fields);
};

struct ast_literal : ast_expr
{
  ast_literal(ctor_params(ast_literal_fields))
    : init_list(ast_literal_fields) {}
  ~ast_literal() {}
  bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_literal_fields);
};

struct ast_fun_call : ast_expr
{
  ast_fun_call(ctor_params(ast_fun_call_fields))
    : init_list(ast_fun_call_fields) {}
  ~ast_fun_call() {}
  bool is_valid(symbol_table& sym);
  fp_t eval(symbol_table& sym);

  field_decls(ast_fun_call_fields);
};

struct ast_pred
{
  virtual ~ast_pred() {}
  virtual bool is_valid(symbol_table& sym) = 0;
  virtual bool eval(symbol_table& sym) = 0;
};

struct ast_rel_pred : ast_pred
{
  ast_rel_pred(ctor_params(ast_rel_pred_fields))
    : init_list(ast_rel_pred_fields) {}
  ~ast_rel_pred() {}
  bool is_valid(symbol_table& sym);
  bool eval(symbol_table& sym);

  field_decls(ast_rel_pred_fields);
};

struct ast_bin_l_pred : ast_pred
{
  ast_bin_l_pred(ctor_params(ast_bin_l_pred_fields))
    : init_list(ast_bin_l_pred_fields) {}
  ~ast_bin_l_pred() {}
  bool is_valid(symbol_table& sym);
  bool eval(symbol_table& sym);

  field_decls(ast_bin_l_pred_fields);
};

struct ast_uny_l_pred : ast_pred
{
  ast_uny_l_pred(ctor_params(ast_uny_l_pred_fields))
    : init_list(ast_uny_l_pred_fields) {}
  ~ast_uny_l_pred() {}
  bool is_valid(symbol_table& sym);
  bool eval(symbol_table& sym);

  field_decls(ast_uny_l_pred_fields);
};

struct ast_stmt
{
  virtual ~ast_stmt() {}
  virtual bool is_valid(symbol_table& sym) = 0;
  virtual maybe_fp_t exec(symbol_table& sym) = 0;
};

struct ast_block
{
  ast_block(ctor_params(ast_block_fields))
    : init_list(ast_block_fields) {}
  ~ast_block() {}
  bool is_valid(symbol_table& sym);
  maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_block_fields);
};

struct ast_var_assign_stmt : ast_stmt
{
  ast_var_assign_stmt(ctor_params(ast_var_assign_stmt_fields))
    : init_list(ast_var_assign_stmt_fields) {}
  ~ast_var_assign_stmt()  {}
  bool is_valid(symbol_table& sym);
  maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_var_assign_stmt_fields);
};

struct ast_if_then_stmt : ast_stmt
{
  ast_if_then_stmt(ctor_params(ast_if_then_stmt_fields))
    : init_list(ast_if_then_stmt_fields) {}
  ~ast_if_then_stmt() {}
  bool is_valid(symbol_table& sym);
  maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_if_then_stmt_fields);
};

struct ast_if_then_else_stmt : ast_stmt
{
  ast_if_then_else_stmt(ctor_params(ast_if_then_else_stmt_fields))
    : init_list(ast_if_then_else_stmt_fields) {}
  ~ast_if_then_else_stmt()  {}
  bool is_valid(symbol_table& sym);
  maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_if_then_else_stmt_fields);
};

struct ast_while_stmt : ast_stmt
{
  ast_while_stmt(ctor_params(ast_while_stmt_fields))
    : init_list(ast_while_stmt_fields) {}
  ~ast_while_stmt() {}
  bool is_valid(symbol_table& sym);
  maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_while_stmt_fields);
};

struct ast_return_stmt : ast_stmt
{
  ast_return_stmt(ctor_params(ast_return_stmt_fields))
    : init_list(ast_return_stmt_fields) {}
  ~ast_return_stmt()  {}
  bool is_valid(symbol_table& sym);
  maybe_fp_t exec(symbol_table& sym);

  field_decls(ast_return_stmt_fields);
};

struct ast_plot_cmd
{
  ast_plot_cmd(ctor_params(ast_plot_cmd_fields))
    : init_list(ast_plot_cmd_fields) {}
  ~ast_plot_cmd() {}
  bool is_valid(symbol_table& sym);
  void plot(symbol_table& sym);

  field_decls(ast_plot_cmd_fields);
};

struct ast_fun_def
{
  ast_fun_def(ctor_params(ast_fun_def_fields))
    : init_list(ast_fun_def_fields) {}
  ~ast_fun_def() {}
  bool is_valid(symbol_table& sym);

  field_decls(ast_fun_def_fields);
};

struct ast_program
{
  ast_program(ctor_params(ast_program_fields))
    : init_list(ast_program_fields) {}
  ~ast_program() {}
  bool is_valid(symbol_table& sym);
  bool run();

  field_decls(ast_program_fields);
};

#endif /* MYLANGA_AST_H */