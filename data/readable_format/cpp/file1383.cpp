#include <vector>
#include <gtest/gtest.h>

namespace phs_single {

class phs_single_t {
public:
    std::vector<float> d1() const {
        return std::vector<float>(2, 1.0f); // Mimics the Fortran function returning an array initialized to 1.0
    }

    std::vector<float> d2(int n) const {
        return std::vector<float>(n, 1.0f); // Mimics the Fortran function returning an array of size n initialized to 1.0
    }
};

void func1(const std::vector<float>& p) {
    // Placeholder for functionality. For demonstration, it just prints the size of the array.
    std::cout << "func1 called with array of size: " << p.size() << std::endl;
}

void evaluate(phs_single_t& phs) {
    func1(phs.d1());
    func1(phs.d2(2));
}

} // end namespace phs_single

// Unit tests
namespace phs_single {

TEST(PhsSingleTest, D1Test) {
    phs_single_t phs;
    auto result = phs.d1();
    ASSERT_EQ(result.size(), 2);
    EXPECT_FLOAT_EQ(result[0], 1.0f);
    EXPECT_FLOAT_EQ(result[1], 1.0f);
}

TEST(PhsSingleTest, D2Test) {
    phs_single_t phs;
    auto result = phs.d2(3);
    ASSERT_EQ(result.size(), 3);
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_FLOAT_EQ(result[i], 1.0f);
    }
}

} // namespace phs_single

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}