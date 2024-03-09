#pragma once

#include "ir_node.h"

namespace kitten {

template <typename T>
struct ExprNode : IRNode {
  void accept(IRVisitor *v) const override;
  ExprNode() : IRNode(T::_node_type) {}
  ~ExprNode() override = default;
};

struct Expr : IRHandle {

  Expr() = default;

  Expr(const IRNode *p) : IRHandle(p) {}
};

} // namespace kitten
