#include <kitten/core/tensor/tensor.h>
// #include <kitten/core/tensor/tensor_factories.h>

#include <cstring>

namespace kitten {

template <DeviceType device>
Tensor<device> zeros(ArrayRef<int64_t> dims, DataType dtype = DataType::F32);

template <DeviceType device>
Tensor<device> ones(ArrayRef<int64_t> dims, DataType dtype = DataType::F32);

template <DeviceType device>
Tensor<device> full(ArrayRef<int64_t> dims, float value,
                    DataType dtype = DataType::F32);

template <>
Tensor<DeviceType::CPU> zeros<DeviceType::CPU>(ArrayRef<int64_t> dims,
                                               DataType dtype) {
  Tensor<DeviceType::CPU> t(dims, dtype);
  memset(t.raw_data(), 0, t.size_bytes());
  return t;
}

template <>
Tensor<DeviceType::CPU> ones<DeviceType::CPU>(ArrayRef<int64_t> dims,
                                              DataType dtype) {
  return full<DeviceType::CPU>(dims, 1, dtype);
}

template <>
Tensor<DeviceType::CPU> full<DeviceType::CPU>(ArrayRef<int64_t> dims,
                                              float value, DataType dtype) {
  Tensor<DeviceType::CPU> t(dims, dtype);
  return t;
}

} // namespace kitten
