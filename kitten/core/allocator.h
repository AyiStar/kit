#pragma once

#include <kitten/core/data_ptr.h>
#include <kitten/core/device_type.h>
#include <kitten/core/meta.h>

#include <iostream>

namespace kitten {

class Allocator {
public:
  virtual ~Allocator() = default;
  virtual DataPtr allocate(std::size_t nbytes) = 0;
};

void set_allocator(const DeviceType &device_type, Allocator *allocator);
Allocator *get_allocator(const DeviceType &device_type);

template <DeviceType t>
struct AllocatorRegisterer {
  explicit AllocatorRegisterer(Allocator *allocator) {
    set_allocator(t, allocator);
    std::cout << "Allocator for device " << static_cast<int>(t)
              << " has been set" << std::endl;
  }
};

#define REGISTER_ALLOCATOR(device, alloc)                                      \
  namespace {                                                                  \
  AllocatorRegisterer<device> g_allocator_registerer(alloc);                   \
  }

} // namespace kitten
