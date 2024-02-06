#pragma once

#include <kitten/core/meta/config.h>

#include <cstddef>
#include <cstdint>

namespace kitten {

#define KITTEN_FORALL_DATA_TYPES(_)                                            \
  _(uint8_t, U8)                                                               \
  _(uint16_t, U16)                                                             \
  _(uint32_t, U32)                                                             \
  _(uint64_t, U64)                                                             \
  _(int8_t, I8)                                                                \
  _(int16_t, I16)                                                              \
  _(int32_t, I32)                                                              \
  _(int64_t, I64)                                                              \
  _(float, F32)                                                                \
  _(double, F64)

enum class DataType : uint8_t {
#define DEFINE_DATATYPE_ENUM_VAL_(type, name) name,
  KITTEN_FORALL_DATA_TYPES(DEFINE_DATATYPE_ENUM_VAL_)
#undef DEFINE_DATATYPE_ENUM_VAL_
      Undefined,
  NumTypes
};

constexpr uint8_t NumDataTypes = static_cast<uint8_t>(DataType::NumTypes);
constexpr size_t DataTypeSizes[NumDataTypes]{
#define DEFINE_DATATYPE_SIZE_VAL_(type, name) sizeof(type),
    KITTEN_FORALL_DATA_TYPES(DEFINE_DATATYPE_SIZE_VAL_)
#undef DEFINE_DATATYPE_ENUM_VAL_
};
constexpr char
    DataTypeNames[NumDataTypes][KITTEN_MAX_DATA_TYPE_NAME_LENGTH + 1]{
#define STRINGIFY_HELPER_(x) #x
#define DEFINE_DATATYPE_NAME_CSTRING_(type, name) STRINGIFY_HELPER_(name),
        KITTEN_FORALL_DATA_TYPES(DEFINE_DATATYPE_NAME_CSTRING_)
#undef DEFINE_DATATYPE_NAME_CSTRING_
#undef STRINGIFY_HELPER_
    };

struct DataTypeMeta final {

  const DataType dtype;

  using IndexType = uint8_t;

  DataTypeMeta(DataType dtype) : dtype(dtype) {}
  constexpr IndexType index() { return static_cast<IndexType>(dtype); }
  constexpr size_t size() {
    return DataTypeSizes[static_cast<IndexType>(dtype)];
  }
  constexpr const char *name() {
    return DataTypeNames[static_cast<IndexType>(dtype)];
  }
};

} // namespace kitten
