#pragma once

#include <kitten/core/alloc/cpu_allocator.h>
#include <kitten/core/meta/config.h>
#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/tensor/tensor.h>
#include <kitten/macro/assertion.h>
#include <kitten/util/array_ref.h>

#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <memory>

namespace kitten {

template <DeviceType device = DeviceType::CPU>
class Tensor {

public:
  Tensor() = default;

  Tensor(ArrayRef<int64_t> dims, DataType dtype = DataType::F32)
      : dtype_(dtype), dtype_meta_(dtype), device_(device),
        allocator_(get_allocator(device)),
        ndim_(static_cast<int>(dims.size())) {
    // memory allocation
    KITTEN_ASSERT(dtype_ == DataType::F32, "Currently only support F32");
    KITTEN_ASSERT(device_ == DeviceType::CPU, "Currently only support CPU");
    KITTEN_ASSERT_DEBUG(allocator_ != nullptr);
    KITTEN_ASSERT(ndim_ <= KITTEN_MAX_DIM);
    size_t numel = 1;
    for (int i = 0; i < ndim_; i++) {
      dims_[i] = dims[i];
      numel *= dims[i];
    }
    size_t n_bytes = dtype_meta_.size() * numel;
    auto allocated_data_ptr = allocator_->allocate(n_bytes);
    data_ptr_ = std::move(allocated_data_ptr);
  }

  Tensor(int64_t dim0, DataType dtype = DataType::F32)
      : Tensor(ArrayRef<int64_t>(dim0), dtype) {}

  int ndim() { return ndim_; }

  size_t numel() {
    size_t n = 1;
    for (int i = 0; i < ndim_; i++) {
      n *= dims_[i];
    }
    return n;
  }

protected:
  DataType dtype_;
  DeviceType device_;
  DataTypeMeta dtype_meta_;

  DataPtr data_ptr_;
  Allocator *allocator_;
  std::size_t size_bytes_;

  size_t dims_[KITTEN_MAX_DIM];
  int ndim_;
};

} // namespace kitten
