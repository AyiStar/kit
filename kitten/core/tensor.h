#include <kitten/core/data_type.h>
#include <kitten/core/tensor_impl.h>

#include <memory>

namespace kitten {

class Tensor {

public:
  Tensor(DataType dtype, int ndim, int ne) {}

protected:
  std::shared_ptr<TensorImpl> impl_;
  bool is_param_;
  DataType data_type_;
};

} // namespace kitten
