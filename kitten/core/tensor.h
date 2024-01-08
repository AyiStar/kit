#include <memory>

#include <core/tensor_impl.h>

namespace kt {

class Tensor {

protected:
  std::shared_ptr<TensorImpl> impl_;
};

} // namespace kt
