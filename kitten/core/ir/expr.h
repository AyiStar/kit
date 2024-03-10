#pragma once

#include <kitten/core/meta/data_type.h>

#include "node.h"

namespace kitten {

template <typename T>
struct ExprNode : public IRNode {
  void accept(IRVisitor *v) const override;
  ExprNode() : IRNode(T::_node_type) {}
  ~ExprNode() override = default;
};

struct Expr : IRHandle {

  Expr() = default;

  Expr(const IRNode *p) : IRHandle(p) {}
};

template <DataType dtype>
struct ImmNode : public ExprNode<ImmNode> {
  using dtype_t = dtype_to_ctype<dtype>;
  dtype_t value;

  explicit ImmNode(dtype_t value) : value(value) {}

  static Expr make(dtype_t value);

  static const IRNodeType _node_type = IRNodeType::Imm;
};

struct AddExprNode : public ExprNode<AddExprNode> {
  Expr lhs, rhs;

  explicit AddExprNode(Expr a, Expr b) : lhs(a), rhs(b) {}

  static Expr make(Expr a, Expr b);

  static const IRNodeType _node_type = IRNodeType::Add;
};

} // namespace kitten
