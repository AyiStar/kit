#pragma once

#include <kitten/core/meta/device_type.h>

#include <memory>

namespace kitten {

using DeletePtrFn = void (*)(void *);
namespace {
void deleteNothing(void *) {}
} // namespace

class DataPtr {
public:
  DataPtr()
      : data_(nullptr), ctx_(nullptr, &deleteNothing),
        device_(DeviceType::CPU){};

  DataPtr(void *data, DeviceType device, void *ctx, DeletePtrFn deleter)
      : data_(data), ctx_(ctx, deleter), device_(device) {}

  template <typename T>
  T *raw_data() {
    return reinterpret_cast<T *>(data_);
  }

  template <DataType dtype>
  dtype_to_ctype_t<dtype> *data() {
    return raw_data<dtype_to_ctype_t<dtype>>();
  }

private:
  void *data_;
  std::unique_ptr<void, DeletePtrFn> ctx_;
  DeviceType device_;
};
} // namespace kitten
