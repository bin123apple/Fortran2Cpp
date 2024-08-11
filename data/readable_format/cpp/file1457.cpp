#include <gtest/gtest.h>
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <sstream> // For std::stringstream

template<typename T>
void checkVectorSize(const std::vector<T>& vector, size_t nsize, const std::string& subname, const std::string& vecname) {
    if (vector.size() != nsize) {
        std::stringstream ss;
        ss << "FATAL ERROR: Size problem incompatibility!"
           << "  Inside Procedure: " << subname
           << "  Vector Name:      " << vecname
           << "  Expected size:    " << nsize
           << "  Actual size:      " << vector.size();
        throw std::runtime_error(ss.str());
    }
}

TEST(CheckVectorSizeTest, HandlesCorrectSize) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::string subname = "TestProcedure";
    std::string vecname = "TestVector";
    size_t expectedSize = 5;
    EXPECT_NO_THROW(checkVectorSize(vec, expectedSize, subname, vecname));
}

TEST(CheckVectorSizeTest, HandlesIncorrectSize) {
    std::vector<int> vec = {1, 2, 3, 4};
    std::string subname = "TestProcedure";
    std::string vecname = "TestVector";
    size_t expectedSize = 5;
    EXPECT_THROW(checkVectorSize(vec, expectedSize, subname, vecname), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}