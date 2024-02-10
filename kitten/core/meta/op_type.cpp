#include <kitten/core/meta/config.h>
#include <kitten/core/meta/op_type.h>

namespace kitten {

constexpr char OpTypeNames[NumOpTypes][KITTEN_MAX_OP_TYPE_NAME_LENGTH + 1]{
#define STRINGIFY_HELPER_(x) #x
#define DEFINE_OPTYPE_NAME_CSTRING_(type, name) STRINGIFY_HELPER_(name),
    KITTEN_FORALL_OP_TYPES(DEFINE_OPTYPE_NAME_CSTRING_)
#undef DEFINE_DATATYPE_NAME_CSTRING_
#undef STRINGIFY_HELPER_
};

OpTypeMeta::IndexType OpTypeMeta::index() {
  return static_cast<IndexType>(optype);
}

const char *OpTypeMeta::name() {
  return OpTypeNames[static_cast<IndexType>(optype)];
}

} // namespace kitten
