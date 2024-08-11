#include <iostream>
#include <complex>
#include <cstdlib>

// Function declarations
int tt(int* x);
int tt(float* x);
int tt(std::complex<float>* x);
int tt(std::complex<double>* x);
int tt(void* x);

// Function implementations
int tt(int* x) {
    return 1;
}

int tt(float* x) {
    return 2;
}

int tt(std::complex<float>* x) {
    return 3;
}

int tt(std::complex<double>* x) {
    return 4;
}

// This version of tt is used to simulate calling with a null pointer.
int tt(void* x) {
    return 0;
}

// Simple test function
void runTests() {
    if(tt(static_cast<bool*>(nullptr)) != 0) std::exit(1);
    if(tt(static_cast<int*>(nullptr)) != 1) std::exit(2);
    if(tt(static_cast<float*>(nullptr)) != 2) std::exit(3);
    if(tt(static_cast<std::complex<float>*>(nullptr)) != 3) std::exit(4);
    if(tt(static_cast<std::complex<double>*>(nullptr)) != 4) std::exit(5);

    std::cout << "All tests passed." << std::endl;
}

int main() {
    runTests(); // Run the tests
    return 0;
}