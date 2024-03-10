#pragma once

#include "node.h"

namespace kitten {

template <typename T>
struct FuncNode : IRNode {
  void accept(IRVisitor *v) const override;
  FuncNode() : IRNode(T::_node_type) {}
  ~FuncNode() override = default;
};

struct Func : IRHandle {

  Func() = default;

  Func(const IRNode *p) : IRHandle(p) {}
};

} // namespace kitten
