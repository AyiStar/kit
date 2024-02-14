#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/meta/op_type.h>
#include <kitten/core/tensor/tensor.h>
#include <kitten/macro/assertion.h>

namespace kitten {
template <OpType op, int rank, DataType dtype, DeviceType device>
Tensor<rank, dtype, device>
tensorBinaryOp(const Tensor<rank, dtype, device> &a,
               const Tensor<rank, dtype, device> &b) {
  static_assert(static_cast<uint16_t>(op) < NumOpTypes, "Undefined operator");
  static_assert(static_cast<uint16_t>(dtype) < NumDataTypes,
                "Undefined data type");
  static_assert(static_cast<uint16_t>(device) < NumDeviceTypes,
                "Undefined device");
  KITTEN_ASSERT(false, "The operator ", OpTypeMeta(op).name(),
                " has not been implemented");
}

template <OpType op, int rank, DataType dtype, DeviceType device>
  requires(op == OpType::NOP)
Tensor<rank, dtype, device>
tensorBinaryOp(const Tensor<rank, dtype, device> &a,
               const Tensor<rank, dtype, device> &b) {
  int64_t zero_dims[rank] = {0};
  return Tensor<rank, dtype, device>(zero_dims);
}

} // namespace kitten
