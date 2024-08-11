#include <gtest/gtest.h>
#include <complex>

class ComplexCreator {
public:
    std::complex<double> operator()(int a, int b) const {
        return std::complex<double>(b, a);
    }
};

// Test fixture for ComplexCreator tests
class ComplexCreatorTest : public ::testing::Test {
protected:
    ComplexCreator hoge;
};

TEST_F(ComplexCreatorTest, CreatesComplexNumber) {
    std::complex<double> expected(4, 5); // Expected result is 4 + 5i

    auto result = hoge(5, 4); // Correct usage based on the corrected design
    EXPECT_EQ(expected, result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}