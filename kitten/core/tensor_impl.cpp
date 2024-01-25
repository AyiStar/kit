#include <kitten/core/cpu_allocator.h>
#include <kitten/core/tensor_impl.h>

namespace kitten {
TensorImpl::TensorImpl(int64_t ne0, DataType data_type, DeviceType device_type)
    : data_ptr_(get_allocator(device_type)->allocate()) {}
} // namespace kitten
