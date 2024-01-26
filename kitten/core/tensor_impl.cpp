#include <kitten/core/cpu_allocator.h>
#include <kitten/core/tensor_impl.h>

#include <cassert>
#include <cstddef>
#include <iostream>

namespace kitten {
TensorImpl::TensorImpl(int64_t ne0, DataType data_type, DeviceType device_type)
    : data_type_(data_type), device_type_(device_type),
      allocator_(get_allocator(device_type)) {
  // memory allocation
  std::cout << "Creating TensorImpl" << std::endl;
  assert(data_type == DataType::F32);
  assert(device_type == DeviceType::CPU);
  assert(allocator_ != nullptr);
  size_t n_bytes = sizeof(float) * ne0;
  auto allocated_data_ptr = allocator_->allocate(n_bytes);
  data_ptr_ = std::move(allocated_data_ptr);

  // meta info
  ndim_ = 1;
  dims_[0] = ne0;
}
} // namespace kitten
