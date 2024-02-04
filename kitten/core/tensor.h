#pragma once

#include <kitten/core/data_type.h>
#include <kitten/core/device_type.h>
#include <kitten/core/meta.h>
#include <kitten/core/tensor_impl.h>
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

  // TODO implementation of indexing API
  /*
  Tensor index(int64_t indices[]);
  Tensor &index_put_(int64_t indices[], float value);
  */

protected:
  std::shared_ptr<TensorImpl> impl_;
};

} // namespace kitten
