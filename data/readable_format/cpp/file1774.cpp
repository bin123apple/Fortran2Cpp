#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Define the Blade class directly in this file
class Blade {
public:
    std::vector<double> C;
    std::vector<double> DR;
    double R;
    int NB;

    Blade() = default;
    ~Blade() = default;

    void allocate(int sizeC, int sizeDR) {
        C.resize(sizeC);
        DR.resize(sizeDR);
    }
};

// BladeTest adapted for Google Test framework
class BladeTest : public ::testing::Test {
protected:
    Blade blade;

    void SetUp() override {
        // Allocate arrays with some test sizes
        blade.allocate(5, 5);
    }
};

TEST_F(BladeTest, ArrayAllocation) {
    // Test allocation by assigning values
    for (int i = 0; i < 5; ++i) {
        blade.C[i] = i + 1.0;  // 1.0, 2.0, ..., 5.0
        blade.DR[i] = i + 0.5;  // 0.5, 1.5, ..., 4.5
    }

    // Check if the values are correctly assigned
    for (int i = 0; i < 5; ++i) {
        EXPECT_DOUBLE_EQ(blade.C[i], i + 1.0);
        EXPECT_DOUBLE_EQ(blade.DR[i], i + 0.5);
    }
}

TEST_F(BladeTest, PrecisionAndAssignments) {
    // Assign and test the precision and assignments
    blade.R = 10.0;
    blade.NB = 5;

    EXPECT_DOUBLE_EQ(blade.R, 10.0);
    EXPECT_EQ(blade.NB, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}