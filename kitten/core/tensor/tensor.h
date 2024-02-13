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

template <DeviceType device_type = DeviceType::CPU,
          DataType data_type = DataType::F32>
class Tensor {

public:
  Tensor() = default;

  Tensor(ArrayRef<int64_t> dims)
      : dtype_(data_type), dtype_meta_(data_type), device_(device_type),
        allocator_(get_allocator(device_type)),
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
    size_bytes_ = dtype_meta_.size() * numel;
    auto allocated_data_ptr = allocator_->allocate(size_bytes_);
    data_ptr_ = std::move(allocated_data_ptr);
  }

  Tensor(int64_t dim0) : Tensor(ArrayRef<int64_t>(dim0)) {}

  int ndim() { return ndim_; }

  size_t numel() {
    size_t n = 1;
    for (int i = 0; i < ndim_; i++) {
      n *= dims_[i];
    }
    return n;
  }

  DataType dtype() { return dtype_; }

  DeviceType device() { return device_; }

  void *raw_data() { return data_ptr_.raw_data(); }

  template <DataType data_type>
  dtype_to_ctype_t<data_type> *data() {
    return data_ptr_.data<data_type>();
  }

  size_t size_bytes() { return size_bytes_; }

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
