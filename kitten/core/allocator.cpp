#include <kitten/core/allocator.h>
#include <kitten/core/meta.h>

namespace kitten {

Allocator *allocator_array[KITTEN_MAX_NUM_DEVICE_TYPES];

void set_allocator(const DeviceType &device_type, Allocator *allocator) {
  allocator_array[static_cast<int>(device_type)] = allocator;
}

Allocator *get_allocator(const DeviceType &device_type) {
  return allocator_array[static_cast<int>(device_type)];
}

} // namespace kitten