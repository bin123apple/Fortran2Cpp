#include <iostream>
#include <cstring>
#include <cstdlib>

// Global variable to replace the common block
char chr[9]; // Increased size by 1 for null termination in C++

// Forward declarations for the functions
extern "C" void foobar1();
extern "C" void foobar2();

// Using extern "C" to avoid C++ name mangling issues when using function pointers

extern "C" void foobar1() {
    std::strncpy(chr, "foobar1", 8);
    chr[8] = '\0'; // Ensure null termination
}

extern "C" void foobar2() {
    std::strncpy(chr, "foobar2", 8);
    chr[8] = '\0'; // Ensure null termination
}

// Function pointer type for the external functions/subroutines
typedef void (*FuncPtr)();

// foo takes a function pointer to another function (fcn) as its argument
extern "C" void foo(FuncPtr fcn) {
    // Local function bar that calls the external function pointed by fcn
    auto bar = [&]() {
        fcn();
    };
    
    // Call the local function bar
    bar();
}

int main() {
    // Initialize chr
    chr[0] = '\0';

    // Call foo with foobar1
    foo(foobar1);
    if (std::strcmp(chr, "foobar1") != 0) std::abort();

    // Call foo with foobar2
    foo(foobar2);
    if (std::strcmp(chr, "foobar2") != 0) std::abort();

    return 0;
}