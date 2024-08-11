#include <gtest/gtest.h>
#include <array>

// Define the CLAENV class with IPARMS directly in this file
class CLAENV {
public:
    static std::array<int, 100>& IPARMS() {
        static std::array<int, 100> instance;
        return instance;
    }
};

// Define the XLAENV function
void XLAENV(int ISPEC, int NVALUE) {
    if (ISPEC >= 1 && ISPEC <= 8) {
        CLAENV::IPARMS()[ISPEC - 1] = NVALUE; // Array indexing starts at 0 in C++
    }
}

// Unit test code using Google Test
TEST(XLAENVTest, SetsCorrectValues) {
    XLAENV(1, 10);
    XLAENV(2, 20);
    XLAENV(9, 90); // This should not affect the array since ISPEC is out of the 1-8 range.
    
    auto& iparms = CLAENV::IPARMS();
    
    EXPECT_EQ(iparms[0], 10);
    EXPECT_EQ(iparms[1], 20);
    EXPECT_EQ(iparms[8], 0); // Checking the 9th element which should remain unaffected.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}