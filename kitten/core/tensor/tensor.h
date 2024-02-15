#pragma once

#include <kitten/core/alloc/cpu_allocator.h>
#include <kitten/core/alloc/data_ptr.h>
#include <kitten/core/meta/config.h>
#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/tensor/tensor.h>
#include <kitten/macro/assertion.h>
#include <kitten/util/array_ref.h>

#include <array>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <memory>

namespace kitten {

template <int rank, DataType data_type = DataType::F32,
          DeviceType device_type = DeviceType::CPU>
class Tensor {

public:
  Tensor(ArrayRef<int64_t> dims)
      : dtype_(data_type), dtype_meta_(data_type), device_(device_type),
        allocator_(get_allocator(device_type)), ndim_(rank) {
    // memory allocation
    KITTEN_ASSERT(rank == static_cast<int>(dims.size()));
    KITTEN_ASSERT_DEBUG(allocator_ != nullptr);
    size_t numel = 1;
    for (int i = 0; i < ndim_; i++) {
      dims_[i] = dims[i];
      numel *= dims[i];
    }
    size_bytes_ = dtype_meta_.size() * numel;
    auto allocated_data_ptr = allocator_->allocate(size_bytes_);
    data_ptr_ = std::move(allocated_data_ptr);
  }

  consteval int ndim() { return rank; }

  consteval DataType dtype() { return data_type; }

  consteval DeviceType device() { return device_type; }

  size_t numel() {
    size_t n = 1;
    for (int i = 0; i < ndim_; i++) {
      n *= dims_[i];
    }
    return n;
  }

  void *raw_data() { return data_ptr_.raw_data(); }

  ctype *data() { return data_ptr_.data<data_type>(); }

  size_t size_bytes() { return size_bytes_; }

  ctype &at(std::array<size_t, rank> indices) {
    auto *data = data();
    size_t flat_index = 0;
    for (int i = 0; i < rank; i++) {
      // TODO: layout?
    }
    return *(data + flat_index);
  }

public:
  using ctype = dtype_to_ctype_t<data_type>;

protected:
  const int ndim_;
  const DataType dtype_;
  const DeviceType device_;
  DataTypeMeta dtype_meta_;

  DataPtr data_ptr_;
  Allocator *allocator_;
  std::size_t size_bytes_;
  size_t dims_[rank];
};

} // namespace kitten
