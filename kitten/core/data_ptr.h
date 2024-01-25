#pragma once

#include <kitten/core/device_type.h>

#include <memory>

namespace kitten {

using DeletePtrFn = void (*)(void *);

class DataPtr {
public:
  DataPtr(void *data, DeviceType device, void *ctx, DeletePtrFn deleter)
      : data_(data), ctx_(ctx, deleter), device_(device) {}

private:
  void *data_;
  std::unique_ptr<void, DeletePtrFn> ctx_;
  DeviceType device_;
};
} // namespace kitten
