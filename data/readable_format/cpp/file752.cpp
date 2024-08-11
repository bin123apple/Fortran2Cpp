// Make sure you're compiling with a standard that supports the features used.
// For GCC or Clang: g++ -std=c++17 -o test_name_database test_name_database.cpp -lgtest -lgtest_main -pthread
// If you're using GCC < 9.1, you might also need to link against the filesystem library: -lstdc++fs

#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

constexpr size_t MAX_STRING_LEN = 256;

void createNameDatabase(std::string& prname, int iproc, int iregionCode, const std::string& localPath) {
    std::ostringstream procnameStream;
    procnameStream << "/proc" << std::setw(6) << std::setfill('0') << iproc << "_reg" << iregionCode << "_";
    prname = localPath + procnameStream.str(); // Using string concatenation for path manipulation
    if (prname.size() > MAX_STRING_LEN) {
        throw std::runtime_error("Resulting path exceeds maximum allowed length.");
    }
}

void createNameDatabaseAdios(std::string& prname, int iregionCode, const std::string& localPath) {
    std::ostringstream procnameStream;
    procnameStream << "/reg" << iregionCode << "_";
    prname = localPath + procnameStream.str(); // Using string concatenation for path manipulation
    if (prname.size() > MAX_STRING_LEN) {
        throw std::runtime_error("Resulting path exceeds maximum allowed length.");
    }
}

TEST(NameDatabaseTest, CreateNameDatabase) {
    std::string prname;
    int iproc = 123456;
    int iregionCode = 7;
    std::string localPath = "/example/path";

    createNameDatabase(prname, iproc, iregionCode, localPath);
    std::string expected = "/example/path/proc123456_reg7_";
    EXPECT_EQ(prname, expected);
}

TEST(NameDatabaseTest, CreateNameDatabaseAdios) {
    std::string prname;
    int iregionCode = 7;
    std::string localPath = "/example/path";

    createNameDatabaseAdios(prname, iregionCode, localPath);
    std::string expected = "/example/path/reg7_";
    EXPECT_EQ(prname, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}