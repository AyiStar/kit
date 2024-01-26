#include <gtest/gtest.h>
#include <kitten/core/cpu_allocator.h>
#include <kitten/core/tensor.h>

using namespace kitten;

TEST(EmptyTensorTest, 1DTest) {
  // TODO for now, hack the allocator registry
  Allocator *alloc = get_cpu_allocator();
  // set_allocator(DeviceType::CPU, alloc);
  // g_cpu_allocator.allocate(100);
  // &g_allocator_registerer;
  Tensor t(10);
}
