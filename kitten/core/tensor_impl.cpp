#include <kitten/core/cpu_allocator.h>
#include <kitten/core/meta.h>
#include <kitten/core/tensor_impl.h>

#include <cassert>
#include <cstddef>
#include <initializer_list>

namespace kitten {

TensorImpl::TensorImpl(ArrayRef<int64_t> dims, DataType data_type,
                       DeviceType device_type)
    : data_type_(data_type), dtype_meta_(data_type), device_type_(device_type),
      allocator_(get_allocator(device_type)),
      ndim_(static_cast<int>(dims.size())) {
  // memory allocation
  assert(data_type == DataType::F32);
  assert(device_type == DeviceType::CPU);
  assert(allocator_ != nullptr);
  assert(ndim_ <= KITTEN_MAX_DIM);
  size_t numel = 1;
  for (int i = 0; i < ndim_; i++) {
    dims_[i] = dims[i];
    numel *= dims[i];
  }
  size_t n_bytes = dtype_meta_.size() * numel;
  auto allocated_data_ptr = allocator_->allocate(n_bytes);
  data_ptr_ = std::move(allocated_data_ptr);
}

TensorImpl::TensorImpl(int64_t dim0, DataType data_type, DeviceType device_type)
    : TensorImpl(ArrayRef<int64_t>(dim0), data_type, device_type) {}

int TensorImpl::ndim() { return ndim_; }

size_t TensorImpl::numel() {
  size_t n = 1;
  for (int i = 0; i < ndim_; i++) {
    n *= dims_[i];
  }
  return n;
}

} // namespace kitten
