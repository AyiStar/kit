#include <kitten/core/allocator.h>
#include <kitten/core/data_ptr.h>
#include <kitten/core/data_type.h>

namespace kitten {

class TensorImpl {

  TensorImpl(int64_t ne0, DataType data_type, Allocator *allocator = nullptr);

protected:
  DataPtr data_ptr_;
  Allocator *allocator_;
  std::size_t size_bytes_;
};
} // namespace kitten
