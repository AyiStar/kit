#include <gtest/gtest.h>
#include <kitten/api/cpp/include/kitten.h>
#include <kitten/util/array_ref.h>

#include <vector>

using namespace kitten;

TEST(TensorFactoryTest, Zeros) {
  int64_t dims[2] = {10, 20};
  Tensor t = zeros<2, DataType::F32, DeviceType::CPU>(dims);
  EXPECT_EQ(t.device(), DeviceType::CPU);
  EXPECT_EQ(t.size_bytes(), 10 * 20 * sizeof(float));
  EXPECT_EQ(*t.data(), 0);
}

TEST(TensorFactoryTest, Ones) {
  int64_t dims[2] = {10, 20};
  Tensor t = ones<2, DataType::F32, DeviceType::CPU>(dims);
  EXPECT_EQ(t.device(), DeviceType::CPU);
  EXPECT_EQ(t.size_bytes(), 10 * 20 * sizeof(float));
  EXPECT_EQ(*t.data(), 1);
}
