#pragma once

#include <kitten/core/meta/config.h>
#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/tensor/tensor_impl.h>
#include <kitten/util/array_ref.h>

#include <cstdint>
#include <memory>

namespace kitten {

class Tensor {

public:
  Tensor(int64_t dim0, DataType dtype = DataType::F32,
         DeviceType device_type = DeviceType::CPU)
      : impl_(std::make_shared<TensorImpl>(dim0, dtype, device_type)) {}

  Tensor(ArrayRef<int64_t> dims, DataType dtype = DataType::F32,
         DeviceType device_type = DeviceType::CPU)
      : impl_(std::make_shared<TensorImpl>(dims, dtype, device_type)) {}

  int ndim() { return impl_->ndim(); }

  size_t numel() { return impl_->numel(); }

protected:
  std::shared_ptr<TensorImpl> impl_;
};

} // namespace kitten
