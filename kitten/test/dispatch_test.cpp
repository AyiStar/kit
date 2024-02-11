#include <gtest/gtest.h>
#include <kitten/api/cpp/include/kitten.h>
#include <kitten/core/dispatch/kernel_dispatcher.h>
#include <kitten/util/array_ref.h>

#include <vector>

using namespace kitten;

TEST(DispatchTest, NotImplentedError) {
  Tensor a(10), b(10);
  auto add_f32_cpu_func = [](const auto &x, const auto &y) {
    return binaryOp<OpType::ADD, DeviceType::CPU>(x, y);
  };
  ASSERT_DEATH(add_f32_cpu_func(a, b), ".*");
}

TEST(DispatchTest, NOPSpecialization) {
  Tensor a(10), b(10);
  Tensor c = binaryOp<OpType::NOP, DeviceType::CPU>(a, b);
  Tensor d = binaryOp<OpType::NOP, DeviceType::CPU>(a, b);
}
