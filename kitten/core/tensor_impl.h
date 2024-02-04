#pragma once

#include <kitten/core/allocator.h>
#include <kitten/core/data_ptr.h>
#include <kitten/core/data_type.h>
#include <kitten/core/device_type.h>
#include <kitten/util/array_ref.h>

#include <cstdint>

namespace kitten {

class TensorImpl {
public:
  TensorImpl(int64_t dim0, DataType data_type, DeviceType device_type);
  TensorImpl(ArrayRef<int64_t> dims, DataType data_type,
             DeviceType device_type);

  int ndim() { return ndim_; }

  size_t numel() {
    size_t n = 1;
    for (int i = 0; i < ndim_; i++) {
      n *= dims_[i];
    }
    return n;
  }

protected:
  DataPtr data_ptr_;
  Allocator *allocator_;
  DataType data_type_;
  DataTypeMeta dtype_meta_;
  DeviceType device_type_;
  std::size_t size_bytes_;

  size_t dims_[KITTEN_MAX_DIM];
  int ndim_;
};
} // namespace kitten
