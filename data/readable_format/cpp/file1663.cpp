#include <cassert>
#include <iostream>

// Declare and define the func0 function with C linkage
extern "C" {
    void* func0() {
        return nullptr;
    }
}

int main() {
    // Call func0 and verify its behavior
    void* result = func0();
    assert(result == nullptr); // This will abort the program if the assertion fails

    std::cout << "Test passed: func0() returned a null pointer." << std::endl;

    return 0;
}