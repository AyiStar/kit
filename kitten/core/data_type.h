#pragma once

#include <cstdint>

namespace kitten {
enum class DataType : uint16_t { I16, I32, F32, F16 };

// TODO: do we really need these?
// class TypeMetaData final {
// public:
//   DataType data_type();

// private:
// };

// class TypeMeta final {
// public:
// private:
//   uint16_t index_;
// };

// template <typename T>
// TypeMeta make_type_meta();

} // namespace kitten
