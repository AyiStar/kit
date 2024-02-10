#include <gtest/gtest.h>
#include <kitten/api/cpp/include/kitten.h>
#include <kitten/core/dispatch/kernel_dispatcher.h>
#include <kitten/util/array_ref.h>

#include <vector>

using namespace kitten;

TEST(DispatchTest, NotImplentedError) {
  Tensor a(10), b(10);
  auto nop_f32_cpu_func = [](Tensor x, Tensor y) -> Tensor {
    return binaryOp<OpType::NOP, DataType::F32, DeviceType::CPU>(x, y);
  };
  ASSERT_DEATH(nop_f32_cpu_func(a, b), ".*");
}
