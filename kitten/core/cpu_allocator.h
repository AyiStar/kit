#pragma once

#include <kitten/core/allocator.h>
#include <kitten/core/device_type.h>

#include <cstdlib>

namespace kitten {
class CPUAllocator final : Allocator {
public:
  DataPtr allocate(std::size_t nbytes) {
    void *data = malloc(nbytes);
    return {data, DeviceType::CPU, data, &free_data};
  }

  static CPUAllocator &get_cpu_allocator() {
    static CPUAllocator allocator;
    return allocator;
  }

private:
  // Meyer's singleton
  CPUAllocator() = default;
  ~CPUAllocator() = default;
  static void free_data(void *data) { free(data); }
};

} // namespace kitten
