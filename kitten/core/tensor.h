#pragma once

#include <kitten/core/data_type.h>
#include <kitten/core/device_type.h>
#include <kitten/core/meta.h>
#include <kitten/core/tensor_impl.h>

#include <memory>

namespace kitten {

class Tensor {

public:
  Tensor(int ne, DataType dtype = DataType::F32,
         DeviceType device_type = DeviceType::CPU)
      : impl_(std::make_shared<TensorImpl>(ne, dtype, device_type)) {}

  // TODO implementation of indexing API
  Tensor index(int64_t indices[]);
  Tensor &index_put_(int64_t indices[], float value);

protected:
  std::shared_ptr<TensorImpl> impl_;
};

} // namespace kitten
