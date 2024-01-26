#include <kitten/core/cpu_allocator.h>

namespace kitten {

namespace {
CPUAllocator g_cpu_allocator;
}
REGISTER_ALLOCATOR(DeviceType::CPU, &g_cpu_allocator);
} // namespace kitten
