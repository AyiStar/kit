#pragma once

#include <kitten/core/data_type.h>
#include <kitten/core/device_type.h>
#include <kitten/core/tensor_impl.h>

#include <memory>

namespace kitten {

class Tensor {

public:
  Tensor(int ne, DataType dtype, DeviceType device_type) {}

protected:
  std::shared_ptr<TensorImpl> impl_;
  bool is_param_;
  DataType data_type_;
};

} // namespace kitten
