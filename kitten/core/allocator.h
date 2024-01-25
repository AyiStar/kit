#pragma once

#include <kitten/core/data_ptr.h>
#include <kitten/core/device_type.h>
#include <kitten/core/meta.h>

namespace kitten {

class Allocator {
public:
  virtual ~Allocator() = default;
  virtual DataPtr allocate(std::size_t nbytes) = 0;
};

void set_allocator(const DeviceType &device_type, Allocator *allocator);
Allocator *get_allocator(const DeviceType &device_type);

} // namespace kitten
