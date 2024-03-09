#pragma once

#include <cstdint>

namespace kitten {

#define KITTEN_FORALL_IRNODE_TYPES(_)                                          \
  _(IMM, Imm)                                                                  \
  _(ADD, add)

enum class IRNodeType : uint16_t {
#define DEFINE_IRNODE_ENUM_VAL_(type, name) type,
  KITTEN_FORALL_IRNODE_TYPES(DEFINE_IRNODE_ENUM_VAL_)
#undef DEFINE_OPTYPE_ENUM_VAL_
      NumTypes
};

constexpr uint16_t NumIRNodeTypes = static_cast<uint16_t>(IRNodeType::NumTypes);

struct IRNodeTypeMeta final {

  const IRNodeType node_type;

  using IndexType = uint16_t;

  IRNodeTypeMeta(IRNodeType node_type) : node_type(node_type) {}
  IndexType index();
  const char *name();
};

} // namespace kitten
