#include <gtest/gtest.h>
#include <kitten/core/cpu_allocator.h>
#include <kitten/core/tensor.h>

#include <vector>

using namespace kitten;

TEST(EmptyTensorTest, 1DTest) {
  Tensor t(10);
  EXPECT_EQ(t.ndim(), 1) << "The created tensor has ndim = " << t.ndim();
  EXPECT_EQ(t.numel(), 10) << "The created tensor has numel = " << t.numel();
}

TEST(EmptyTensorTest, 2DTest) {
  int64_t dims[2] = {2, 3};
  Tensor t(dims);
  EXPECT_EQ(t.numel(), 6) << "The created tensor has numel = " << t.numel();
  EXPECT_EQ(t.ndim(), 2) << "The created tensor has ndim = " << t.ndim();
}
