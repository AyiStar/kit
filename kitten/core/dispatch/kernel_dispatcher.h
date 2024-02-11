#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/meta/op_type.h>
#include <kitten/core/tensor/tensor.h>
#include <kitten/macro/assertion.h>

namespace kitten {
template <OpType op, DeviceType device>
Tensor<device> binaryOp(const Tensor<device> &a, const Tensor<device> &b) {
  static_assert(static_cast<uint16_t>(op) < NumOpTypes, "Undefined operator");
  static_assert(static_cast<uint16_t>(device) < NumDeviceTypes,
                "Undefined device");
  KITTEN_ASSERT(false, "The operator ", OpTypeMeta(op).name(),
                " has not been implemented");
}

template <OpType op, DeviceType device>
  requires(op == OpType::NOP)
Tensor<device> binaryOp(const Tensor<device> &a, const Tensor<device> &b) {
  return {};
}

} // namespace kitten
