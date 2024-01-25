#pragma once

namespace kitten {
enum class DataType : uint16_t { INT16, INT32, FLOAT32, FLOAT16 };

class TypeMetaData final {
public:
  DataType data_type();

private:
};

class TypeMeta final {
public:
private:
  uint16_t index_;
};

template <typename T> TypeMeta make_type_meta();

} // namespace kitten
