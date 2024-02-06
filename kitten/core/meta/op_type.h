#include <cstdint>

namespace kitten {

#define KITTEN_FORALL_OP_TYPES(_)                                              \
  _(NONE, None)                                                                \
  _(ADD, Add)

enum class OpType : uint16_t {
#define DEFINE_OPTYPE_ENUM_VAL_(type, name) name,
  KITTEN_FORALL_OP_TYPES(DEFINE_OPTYPE_ENUM_VAL_)
#undef DEFINE_OPTYPE_ENUM_VAL_
      Undefined,
  NumTypes
};

constexpr uint16_t NumOpTypes = static_cast<uint16_t>(OpType::NumTypes);

} // namespace kitten
