#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/tensor/tensor.h>
#include <kitten/util/array_ref.h>

#include <cstdint>

namespace kitten {

// TODO implementation of basic factories

template <DeviceType device>
Tensor<device> zeros(ArrayRef<int64_t> dims[], DataType dtype = DataType::F32) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device>
Tensor<device> ones(ArrayRef<int64_t> dims[], DataType dtype = DataType::F32) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device>
Tensor<device> full(ArrayRef<int64_t> dims[], float fill_value,
                    DataType dtype = DataType::F32) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device>
Tensor<device> eye(ArrayRef<int64_t> dims[], DataType dtype = DataType::F32) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device>
Tensor<device> rand(ArrayRef<int64_t> dims[], DataType dtype = DataType::F32) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device>
Tensor<device> randn(ArrayRef<int64_t> dims[], DataType dtype = DataType::F32) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

} // namespace kitten
