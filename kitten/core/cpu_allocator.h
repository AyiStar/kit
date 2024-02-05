#pragma once

#include <kitten/core/allocator.h>
#include <kitten/core/device_type.h>

#include <cstdlib>

namespace kitten {
class CPUAllocator final : public Allocator {
public:
  DataPtr allocate(std::size_t nbytes) {
    void *data = malloc(nbytes);
    return {data, DeviceType::CPU, data, &free_data};
  }

private:
  static void free_data(void *data) { free(data); }
};

Allocator *get_cpu_allocator();

} // namespace kitten
