#include <gtest/gtest.h>
#include "CDS_Arr.h"

// Test fixture for CDS_Arr class
template <typename T, int N>
class CDS_ArrTest : public ::testing::Test {
protected:
    CDS_Arr<T, N> arr;
};

using MyTypes = ::testing::Types<int, float, double>;
TYPED_TEST_SUITE(CDS_ArrTest, MyTypes);

TYPED_TEST(CDS_ArrTest, GetSizeTest) {
    EXPECT_EQ(this->arr.GetSize(), N);
}

TYPED_TEST(CDS_ArrTest, GetDataTest) {
    TypeParam* data = this->arr.GetData();
    ASSERT_NE(data, nullptr);
    for (int i = 0; i < N; ++i) {
        EXPECT_EQ(data[i], TypeParam());
    }
}

TYPED_TEST(CDS_ArrTest, GetDataConstTest) {
    const CDS_Arr<TypeParam, N>& constArr = this->arr;
    const TypeParam* data = constArr.GetData();
    ASSERT_NE(data, nullptr);
    for (int i = 0; i < N; ++i) {
        EXPECT_EQ(data[i], TypeParam());
    }
}

TYPED_TEST(CDS_ArrTest, SwapTest) {
    if (N > 1) {
        this->arr[0] = TypeParam(1);
        this->arr[1] = TypeParam(2);
        this->arr.Swap(0, 1);
        EXPECT_EQ(this->arr[0], TypeParam(2));
        EXPECT_EQ(this->arr[1], TypeParam(1));
    }
}

TYPED_TEST(CDS_ArrTest, FillTest) {
    TypeParam value = TypeParam(5);
    this->arr.Fill(value);
    for (int i = 0; i < N; ++i) {
        EXPECT_EQ(this->arr[i], value);
    }
}

TYPED_TEST(CDS_ArrTest, OperatorIndexTest) {
    this->arr[0] = TypeParam(3);
    EXPECT_EQ(this->arr[0], TypeParam(3));
    const CDS_Arr<TypeParam, N>& constArr = this->arr;
    EXPECT_EQ(constArr[0], TypeParam(3));
}

TYPED_TEST(CDS_ArrTest, StreamOutputTest) {
    TypeParam value = TypeParam(7);
    this->arr.Fill(value);
    std::stringstream ss;
    ss << this->arr;
    std::string expectedOutput;
    for (int i = 0; i < N; ++i) {
        expectedOutput += std::to_string(value) + " ";
    }
    EXPECT_EQ(ss.str(), expectedOutput);
}
