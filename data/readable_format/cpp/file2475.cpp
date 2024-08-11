#include <iostream>
#include <cstddef> // For std::nullptr_t

// Function declaration and definition
extern "C" std::nullptr_t func0() {
    return nullptr;
}

int main() {
    // Call the function
    auto result = func0();

    // Check if the result is nullptr
    if (result == nullptr) {
        std::cout << "Test passed: func0 returned nullptr" << std::endl;
    } else {
        std::cout << "Test failed: func0 did not return nullptr" << std::endl;
    }

    return 0;
}