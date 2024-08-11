#include <iostream>
#include <cstdlib> // for std::abort, std::exit

class t {
public:
    int i; // Assuming 4 bytes for int
    float r; // Assuming 4 bytes for float
};

class t2 : public t {
public:
    int j; // Assuming 4 bytes for int
};

// Simple test function to check sizes
void checkSize(const char* typeName, size_t actual, size_t expected) {
    if (actual != expected) {
        std::cerr << "Size test failed for " << typeName << ": Expected " << expected << ", got " << actual << "." << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "Size test passed for " << typeName << "." << std::endl;
    }
}

int main() {
    // Create instances for testing
    t a;
    t b[3];
    t* cp = new t2(); // Allocating t2, but pointer type is t*

    // Perform size checks
    checkSize("a", sizeof(a), 8);
    checkSize("b", sizeof(b), 24);
    checkSize("*cp (base part)", sizeof(*cp), 8); // Checking the size of the base class part of cp
    checkSize("t2", sizeof(t2), 12); // Direct check against derived class size

    delete cp; // Clean up dynamically allocated memory

    return 0;
}