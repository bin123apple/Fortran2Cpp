#include <gtest/gtest.h>
#include <iostream>

// Define your class directly in this file
class HApply {
public:
    HApply() {}
    // Example method
    bool enableOpenMP(bool enable) {
        // Placeholder functionality
        return enable;
    }

    // Another example method
    int setPerturbation(int level) {
        // Placeholder functionality
        return level;
    }
};

// Unit Tests
TEST(HApplyTests, TestOpenMPEnable) {
    HApply hApply;
    bool result = hApply.enableOpenMP(true);
    ASSERT_TRUE(result); // Assuming the method returns true if OpenMP is enabled
}

TEST(HApplyTests, TestPerturbationSetting) {
    HApply hApply;
    int level = 5; // Example test level
    ASSERT_EQ(hApply.setPerturbation(level), level); // Assuming the method returns the level set
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}