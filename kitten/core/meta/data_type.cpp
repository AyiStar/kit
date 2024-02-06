#include <kitten/core/meta/data_type.h>

namespace kitten {

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

constexpr DataTypeMeta::IndexType DataTypeMeta::index() {
  return static_cast<IndexType>(dtype);
}

constexpr size_t DataTypeMeta::size() {
  return DataTypeSizes[static_cast<IndexType>(dtype)];
}

constexpr const char *DataTypeMeta::name() {
  return DataTypeNames[static_cast<IndexType>(dtype)];
}

} // namespace kitten
