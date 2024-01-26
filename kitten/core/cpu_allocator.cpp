#include <kitten/core/cpu_allocator.h>

namespace kitten {

namespace {
CPUAllocator g_cpu_allocator;
// AllocatorRegisterer<DeviceType::CPU>
// g_allocator_registerer(&g_cpu_allocator);
} // namespace

Allocator *get_cpu_allocator() { return &g_cpu_allocator; }
REGISTER_ALLOCATOR(DeviceType::CPU, &g_cpu_allocator);
} // namespace kitten
