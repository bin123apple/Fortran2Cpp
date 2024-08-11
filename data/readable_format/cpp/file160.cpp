#include <iostream>
#include <stdexcept>
#include <string>
#include <gtest/gtest.h>

namespace mod_alloc {

template<typename T>
void dealloc(T*& x);

template<typename T>
void alloc(T*& x, size_t n) {
    try {
        if (x != nullptr) { // Check if already allocated
            dealloc(x); // Deallocate if necessary
        }
        x = new T[n]; // Allocate new memory
    } catch (const std::bad_alloc& e) { // Catch allocation errors
        // Convert the error to a more descriptive message if necessary
        throw std::runtime_error("Allocation failed: " + std::string(e.what()));
    }
}

template<typename T>
void dealloc(T*& x) {
    if (x != nullptr) { // Check if already allocated
        delete[] x; // Deallocate memory
        x = nullptr; // Avoid dangling pointer
    }
}

} // namespace mod_alloc

// Unit tests using Google Test framework
TEST(ModAllocTests, NormalAllocationDeallocation) {
    float* myArray = nullptr;
    mod_alloc::alloc(myArray, 10);
    EXPECT_NE(myArray, nullptr);
    mod_alloc::dealloc(myArray);
    EXPECT_EQ(myArray, nullptr);
}

TEST(ModAllocTests, DoubleDeallocation) {
    float* myArray = nullptr;
    mod_alloc::alloc(myArray, 10);
    mod_alloc::dealloc(myArray);
    // This should not cause a crash or undefined behavior
    EXPECT_NO_THROW(mod_alloc::dealloc(myArray));
    EXPECT_EQ(myArray, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}