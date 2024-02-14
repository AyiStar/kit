#include <gtest/gtest.h>
#include <kitten/api/cpp/include/kitten.h>
#include <kitten/core/dispatch/kernel_dispatcher.h>
#include <kitten/util/array_ref.h>

#include <vector>

using namespace kitten;

TEST(DispatchTest, NotImplentedError) {
  Tensor<1> a({10}), b({10});
  auto add_f32_cpu_func = [](const auto &x, const auto &y) {
    return tensorBinaryOp<OpType::ADD>(x, y);
  };
  ASSERT_DEATH(add_f32_cpu_func(a, b), ".*");
}

TEST(DispatchTest, NOPSpecialization) {
  Tensor<1> a({10}), b({10});
  auto c = tensorBinaryOp<OpType::NOP>(a, b);
}
