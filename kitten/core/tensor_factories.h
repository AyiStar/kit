#include <kitten/core/data_type.h>
#include <kitten/core/device_type.h>
#include <kitten/core/tensor.h>

#include <cstdint>

namespace kitten {

// TODO implementation of basic factories
Tensor empty(int64_t dims[], DataType dtype = DataType::F32,
             DeviceType device = DeviceType::CPU);

Tensor zeros(int64_t dims[], DataType dtype = DataType::F32,
             DeviceType device = DeviceType::CPU);

Tensor ones(int64_t dims[], DataType dtype = DataType::F32,
            DeviceType device = DeviceType::CPU);

Tensor full(int64_t dims[], float fill_value, DataType dtype = DataType::F32,
            DeviceType device = DeviceType::CPU);

Tensor eye(int64_t dims[], DataType dtype = DataType::F32,
           DeviceType device = DeviceType::CPU);

Tensor rand(int64_t dims[], DataType dtype = DataType::F32,
            DeviceType device = DeviceType::CPU);

Tensor randn(int64_t dims[], DataType dtype = DataType::F32,
             DeviceType device = DeviceType::CPU);

} // namespace kitten
