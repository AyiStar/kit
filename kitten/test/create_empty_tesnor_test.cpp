#include <gtest/gtest.h>
#include <kitten/core/cpu_allocator.h>
#include <kitten/core/tensor.h>

using namespace kitten;

TEST(EmptyTensorTest, 1DTest) { Tensor t(10); }
