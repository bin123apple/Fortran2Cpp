#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <exception>

// Custom exception class to handle deallocation errors
class DeallocationException : public std::exception {
private:
    std::string message;
public:
    DeallocationException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Function to mimic Fortran's deallocate with error handling
template<typename T>
void safe_deallocate(T*& ptr, std::string& errmsg) {
    if(ptr != nullptr) {
        delete ptr;
        ptr = nullptr;
    } else {
        if(errmsg != "Attempt to deallocate an unallocated object") {
            throw DeallocationException(errmsg);
        }
    }
}

// Unit tests
TEST(SafeDeallocateTest, DeallocateUnallocatedScalar) {
    int* A = nullptr; // Unallocated initially
    std::string errmsg = "Attempt to deallocate an unallocated object";
    EXPECT_NO_THROW(safe_deallocate(A, errmsg));
    EXPECT_EQ(A, nullptr); // Ensure A is still nullptr after deallocation attempt
}

TEST(SafeDeallocateTest, DeallocateAllocatedArray) {
    int* B = new int[10]; // Allocated array
    std::string errmsg = "Y"; // The error message is irrelevant in this scenario
    EXPECT_NO_THROW(safe_deallocate(B, errmsg));
    EXPECT_EQ(B, nullptr); // Ensure B is nullptr after successful deallocation
}

TEST(SafeDeallocateTest, DeallocateWithWrongErrorMessage) {
    int* B = nullptr; // Already deallocated
    std::string errmsg = "Some error message";
    EXPECT_THROW(safe_deallocate(B, errmsg), DeallocationException);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}