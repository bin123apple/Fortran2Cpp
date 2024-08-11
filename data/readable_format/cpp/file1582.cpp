#include <gtest/gtest.h>
#include <vector>

// Assuming a value for MAX_OUTPUT_FILES for demonstration purposes
const int MAX_OUTPUT_FILES = 10;

// Mock function vector to track calls
std::vector<int> closed_units;

// Mock version of ofh_close_unit to track calls
void ofh_close_unit(int unit) {
    closed_units.push_back(unit);
}

// Function to close all units
void ofh_close_all_units() {
    for (int i = 2; i <= MAX_OUTPUT_FILES; ++i) {
        ofh_close_unit(i);
    }
}

// Unit Test
TEST(CloseAllUnitsTest, CallsCloseUnitWithCorrectParams) {
    closed_units.clear(); // Clear previous test state
    ofh_close_all_units();

    ASSERT_EQ(closed_units.size(), MAX_OUTPUT_FILES - 1);
    for (int i = 0; i < MAX_OUTPUT_FILES - 1; ++i) {
        EXPECT_EQ(closed_units[i], i + 2) << "Units did not match for index " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}