#pragma once

#include <kitten/core/meta/data_type.h>
#include <kitten/core/meta/device_type.h>
#include <kitten/core/meta/op_type.h>
#include <kitten/macro/assertion.h>

#include <memory>

namespace kitten {

class OpRegistry final {
public:
  OpRegistry &&op(OpType op);
  OpRegistry &&dtype(DataType dtype);
  OpRegistry &&device(DeviceType device);
}

} // namespace kitten
