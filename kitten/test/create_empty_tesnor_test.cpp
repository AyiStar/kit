#include <gtest/gtest.h>
#include <kitten/api/cpp/include/kitten.h>
#include <kitten/util/array_ref.h>

#include <vector>

using namespace kitten;

TEST(EmptyTensorTest, 1DTest) {
  Tensor t(10);
  EXPECT_EQ(t.ndim(), 1) << "The created tensor has ndim = " << t.ndim();
  EXPECT_EQ(t.numel(), 10) << "The created tensor has numel = " << t.numel();
}

TEST(EmptyTensorTest, 2DTest) {
  int64_t dims[2]{2, 3};
  // ArrayRef<int64_t>(dims, 2);
  Tensor t(dims);
  EXPECT_EQ(t.numel(), 6) << "The created tensor has numel = " << t.numel();
  EXPECT_EQ(t.ndim(), 2) << "The created tensor has ndim = " << t.ndim();
}

TEST(EmptyTensorTest, DimToLarge) {
  int64_t dims[6]{2, 3, 4, 5, 6};
  ASSERT_DEATH(Tensor t(dims), ".*");
}

TEST(ArrayRefTest, Conversion) {
  int64_t dims[2]{2, 3};
  ArrayRef<int64_t> arr(dims, 2);
  EXPECT_EQ(arr.size(), 2);
  EXPECT_EQ(arr[0], 2);
  EXPECT_EQ(arr[1], 3);
}
