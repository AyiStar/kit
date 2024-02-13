#pragma once

#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/tensor/tensor.h>
#include <kitten/util/array_ref.h>

#include <cstdint>

namespace kitten {

// TODO implementation of basic factories

template <DeviceType device = DeviceType::CPU, DataType dtype = DataType::F32>
Tensor<device, dtype> zeros(ArrayRef<int64_t> dims) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device = DeviceType::CPU, DataType dtype = DataType::F32>
Tensor<device, dtype> ones(ArrayRef<int64_t> dims) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device = DeviceType::CPU, DataType dtype = DataType::F32>
Tensor<device, dtype> full(ArrayRef<int64_t> dims, float fill_value) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device = DeviceType::CPU, DataType dtype = DataType::F32>
Tensor<device> eye(ArrayRef<int64_t> dims) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device, DataType dtype = DataType::F32>
Tensor<device> rand(ArrayRef<int64_t> dims) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

template <DeviceType device, DataType dtype = DataType::F32>
Tensor<device> randn(ArrayRef<int64_t> dims) {
  KITTEN_ASSERT(false, "Not implemented yet");
}

/* Implementation Prototypes */
extern template Tensor<DeviceType::CPU, DataType dtype>
zeros<DeviceType::CPU>(ArrayRef<int64_t> dims);

extern template Tensor<DeviceType::CPU>
ones<DeviceType::CPU>(ArrayRef<int64_t> dims, DataType dtype = DataType::F32);

extern template Tensor<DeviceType::CPU>
full<DeviceType::CPU>(ArrayRef<int64_t> dims, float value,
                      DataType dtype = DataType::F32);

} // namespace kitten
