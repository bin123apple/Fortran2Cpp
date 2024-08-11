#include <iostream>
#include <cstdint>

// Declare the function with C linkage to ensure interoperability with C.
extern "C" {
    void runFoo(int32_t ndim) {
        // Function implementation goes here.
        // For demonstration purposes, it will just print the value of ndim.
        std::cout << "Running runFoo with ndim = " << ndim << std::endl;
    }
}

int main() {
    // Test the function with a simple call.
    runFoo(5);
    return 0;
}