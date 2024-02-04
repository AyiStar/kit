#pragma once

#include <kitten/core/allocator.h>
#include <kitten/core/device_type.h>

#include <cstdlib>
#include <iostream>

namespace kitten {
class CPUAllocator final : public Allocator {
public:
  CPUAllocator() { std::cout << "CPU Allocator constructed" << std::endl; }
  DataPtr allocate(std::size_t nbytes) {
    void *data = malloc(nbytes);
    std::cout << "data allocated" << std::endl;
    return {data, DeviceType::CPU, data, &free_data};
  }

private:
  static void free_data(void *data) {
    free(data);
    std::cout << "data freed" << std::endl;
  }
};

Allocator *get_cpu_allocator();

} // namespace kitten
