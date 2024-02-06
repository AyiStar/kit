#pragma once

#include <kitten/core/alloc/data_ptr.h>
#include <kitten/core/meta/config.h>
#include <kitten/core/meta/device_type.h>

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
  }
};

// TODO use global variables for registration mechanism in static library will
// cause problem. See https://sillycross.github.io/2022/10/02/2022-10-02/
#define REGISTER_ALLOCATOR(device, alloc)                                      \
  namespace {                                                                  \
  AllocatorRegisterer<device> g_allocator_registerer(alloc);                   \
  } // namespace kitten

} // namespace kitten
