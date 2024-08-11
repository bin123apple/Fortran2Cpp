#include <iostream>
#include <string>
#include <utility> // For std::pair

// Function that mimics the Fortran example's behavior
std::pair<size_t, std::string> getLengthAndString() {
    std::string tgt = "lmnopq"; // Target string
    std::string* ptr = nullptr; // Pointer initialized to nullptr

    ptr = &tgt; // Pointer points to tgt

    // Return the length and content of the string pointed by ptr
    return {ptr->length(), *ptr};
}

// Simple test function
void testGetLengthAndString() {
    auto [length, str] = getLengthAndString();
    if (length == 6 && str == "lmnopq") {
        std::cout << "Test Passed: Length is 6 and string is 'lmnopq'" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }
}

int main() {
    // Run the test
    testGetLengthAndString();

    return 0;
}