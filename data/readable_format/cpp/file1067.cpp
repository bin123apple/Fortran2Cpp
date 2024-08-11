#include <vector>
#include <cstdint>
#include <gtest/gtest.h>

class GsbpMod {
public:
    // Example member variables
    int nclx1, ncly1;
    std::vector<int> lstpl, lstpm;
    
    // Constructor
    GsbpMod(int x1, int y1) : nclx1(x1), ncly1(y1) {
        lstpl.resize(nclx1, 1); // Initialize lstpl with 1s
        lstpm.resize(ncly1, 2); // Initialize lstpm with 2s
    }
    
    // Example member function
    void incrementArrays() {
        for (auto& el : lstpl) el += 1;
        for (auto& el : lstpm) el += 1;
    }
};

TEST(GsbpModTest, ArrayInitializationAndIncrement) {
    GsbpMod gsbp(10, 20); // Initialize with sizes for lstpl and lstpm
    
    // Check initial values
    for (const auto& el : gsbp.lstpl) {
        EXPECT_EQ(el, 1);
    }
    for (const auto& el : gsbp.lstpm) {
        EXPECT_EQ(el, 2);
    }

    // Increment arrays
    gsbp.incrementArrays();

    // Check incremented values
    for (const auto& el : gsbp.lstpl) {
        EXPECT_EQ(el, 2);
    }
    for (const auto& el : gsbp.lstpm) {
        EXPECT_EQ(el, 3);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}