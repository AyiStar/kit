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
      NumTypes
};

constexpr uint8_t NumDataTypes = static_cast<uint8_t>(DataType::NumTypes);

template <DataType dtype>
struct dtype_to_ctype;

#define SPECIALIZE_DataTypeToCPPType(cpp_type, data_type)                      \
  template <>                                                                  \
  struct dtype_to_ctype<DataType::data_type> {                                 \
    using type = cpp_type;                                                     \
  };

KITTEN_FORALL_DATA_TYPES(SPECIALIZE_DataTypeToCPPType)
#undef SPECIALIZE_DataTypeToCPPType

template <DataType dtype>
using dtype_to_ctype_t = typename dtype_to_ctype<dtype>::type;

struct DataTypeMeta final {

  DataType dtype;

  using IndexType = uint8_t;

  DataTypeMeta() = default;
  DataTypeMeta(DataType dtype) : dtype(dtype) {}
  IndexType index();
  size_t size();
  const char *name();
};

} // namespace kitten
