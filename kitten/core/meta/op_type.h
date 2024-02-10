#pragma once

#include <cstdint>

namespace kitten {

#define KITTEN_FORALL_OP_TYPES(_)                                              \
  _(NOP, nop)                                                                  \
  _(ADD, add)

enum class OpType : uint16_t {
#define DEFINE_OPTYPE_ENUM_VAL_(type, name) type,
  KITTEN_FORALL_OP_TYPES(DEFINE_OPTYPE_ENUM_VAL_)
#undef DEFINE_OPTYPE_ENUM_VAL_
      NumTypes
};

constexpr uint16_t NumOpTypes = static_cast<uint16_t>(OpType::NumTypes);

struct OpTypeMeta final {

  const OpType optype;

  using IndexType = uint16_t;

  OpTypeMeta(OpType optype) : optype(optype) {}
  IndexType index();
  const char *name();
};

} // namespace kitten
