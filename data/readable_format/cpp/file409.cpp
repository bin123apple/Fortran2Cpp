#include <gtest/gtest.h>
#include <string>

// Assuming you have a function `processGribFile` to test
std::string processGribFile(const std::string& filename) {
    // Concatenating strings correctly by breaking them into multiple lines
    std::string mockOutput = 
        "discipline=0 "
        "parameterCategory=2 "
        "parameterNumber=3";
    return mockOutput;
}

TEST(MultiTest, ProcessGribFile) {
    std::string testFilename = "mock_grib_file.grib2";
    std::string output = processGribFile(testFilename);
    
    // Checking if the output contains expected substrings
    EXPECT_NE(output.find("discipline=0"), std::string::npos);
    EXPECT_NE(output.find("parameterCategory=2"), std::string::npos);
    EXPECT_NE(output.find("parameterNumber=3"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}