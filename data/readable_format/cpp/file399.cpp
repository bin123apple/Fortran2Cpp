#include <iostream>

// Define a struct that mimics the Fortran common block
struct CASP_WSP {
    int WSL;
    int BP;

    // Constructor to initialize members
    CASP_WSP() : WSL(-1), BP(-1) {}
};

// Declare a global instance of the struct, making it accessible throughout the program
CASP_WSP casp_wsp;

// Function to test initialization
void TestInitialization() {
    if (casp_wsp.WSL == -1 && casp_wsp.BP == -1) {
        std::cout << "Test Passed: WSL and BP are correctly initialized." << std::endl;
    } else {
        std::cout << "Test Failed: WSL or BP are not correctly initialized." << std::endl;
    }
}

int main() {
    TestInitialization();
    return 0;
}