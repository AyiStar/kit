#pragma once

#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/tensor/tensor.h>
#include <kitten/util/array_ref.h>

#include <cstdint>

namespace kitten {

// TODO implementation of basic factories

template <int rank, DataType dtype, DeviceType device>
Tensor<rank, dtype, device> zeros(ArrayRef<int64_t> dims) {
  KITTEN_ASSERT(false, "Factory zeros(): not implemented yet");
}

template <int rank, DataType dtype, DeviceType device>
Tensor<rank, dtype, device> ones(ArrayRef<int64_t> dims) {
  KITTEN_ASSERT(false, "Factory ones(): not implemented yet");
}

template <int rank, DataType dtype, DeviceType device>
Tensor<rank, dtype, device> full(ArrayRef<int64_t> dims, float value) {
  KITTEN_ASSERT(false, "Factory full: not implemented yet");
}

/* CPU Implementations */
template <int rank, DataType dtype, DeviceType device>
  requires(device == DeviceType::CPU)
Tensor<rank, dtype, device> zeros(ArrayRef<int64_t> dims) {
  Tensor<rank, dtype, device> t(dims);
  memset(t.raw_data(), 0, t.size_bytes());
  return t;
}

template <int rank, DataType dtype, DeviceType device>
  requires(device == DeviceType::CPU)
Tensor<rank, dtype, device> ones(ArrayRef<int64_t> dims) {
  return full<rank, dtype, device>(dims, 1);
}

template <int rank, DataType dtype, DeviceType device>
  requires(device == DeviceType::CPU)
Tensor<rank, dtype, device> full(ArrayRef<int64_t> dims, float value) {
  Tensor<rank, dtype, device> t(dims);
  auto *data = t.data();
  size_t numel = t.numel();
  for (size_t i = 0; i < numel; i++) {
    data[i] = value;
  }
  return t;
}

} // namespace kitten
