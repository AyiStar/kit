#pragma once

#include <kitten/core/meta/ir_node_type.h>

#include <memory>

namespace kitten {

class IRVisitor;

struct IRNode {

  virtual void accept(IRVisitor *v) const = 0;

  virtual ~IRNode() = default;

  IRNodeType node_type;

  IRNode(IRNodeType node_type) : node_type(node_type) {}
};

struct IRHandle {

  IRHandle() = default;

  IRHandle(const IRNode *p) : ptr_(std::shared_ptr<const IRNode>(p)) {}

  void accept(IRVisitor *v) const { ptr_->accept(v); }

  template <typename T>
  const T *as() const {
    if (ptr_ && ptr_->node_type == T::_node_type) {
      return ptr_.get();
    }
    return nullptr;
  }

  IRNodeType node_type() const { return ptr_->node_type; }

private:
  std::shared_ptr<const IRNode> ptr_;
};

} // namespace kitten
