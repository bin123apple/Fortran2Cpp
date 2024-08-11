#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <gtest/gtest.h>
#include <sstream>

// Directly include the checksum function in this file
void checksum(const std::string& sTag, const std::vector<double>& a) {
    double sm = 0.0;
    double nm = 0.0;

    for (double item : a) {
        sm += item;
        nm += item * item;
    }

    std::cout << "@CHECKSUM: " << sTag << " " 
              << std::scientific << sm << " " 
              << std::sqrt(nm) << std::endl;
}

// Unit tests using Google Test
TEST(ChecksumTest, HandlesPositiveNumbers) {
    std::vector<double> array = {1.0, 2.0, 3.0};
    std::string tag = "Test 1";
    std::stringstream buffer;
    
    // Redirect cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    
    checksum(tag, array);
    
    // Reset cout to standard output
    std::cout.rdbuf(prevcoutbuf);
    
    std::string output = buffer.str();
    EXPECT_NE(output.find("Test 1"), std::string::npos);
    EXPECT_NE(output.find("6.000000"), std::string::npos); // Check sum
}

TEST(ChecksumTest, HandlesMixedNumbers) {
    std::vector<double> array = {0.5, 1.5, -2.0, 0.0};
    std::string tag = "Test 2";
    std::stringstream buffer;
    
    // Redirect cout to buffer
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    
    checksum(tag, array);
    
    // Reset cout to standard output
    std::cout.rdbuf(prevcoutbuf);
    
    std::string output = buffer.str();
    EXPECT_NE(output.find("Test 2"), std::string::npos);
    EXPECT_NE(output.find("0.000000"), std::string::npos); // Check sum
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}