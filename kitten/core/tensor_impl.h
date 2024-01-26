#pragma once

#include <kitten/core/allocator.h>
#include <kitten/core/data_ptr.h>
#include <kitten/core/data_type.h>
#include <kitten/core/device_type.h>

namespace kitten {

class TensorImpl {
public:
  TensorImpl(int64_t ne0, DataType data_type, DeviceType device_type);

protected:
  DataPtr data_ptr_;
  Allocator *allocator_;
  DataType data_type_;
  DeviceType device_type_;
  std::size_t size_bytes_;

  size_t dims_[KITTEN_MAX_DIM];
  int ndim_;
};
} // namespace kitten
