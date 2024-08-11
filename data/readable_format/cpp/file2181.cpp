#include <iostream>
#include <vector>
#include <cmath>

// Define namespace and variables directly in this file
namespace HartreeVariables {
    double E_hartree = 0.0; // Initialization is optional here
    std::vector<double> Vh;
}

// Function prototypes if needed
void test();

int main() {
    // Initialize the variables
    HartreeVariables::E_hartree = 1.234;
    HartreeVariables::Vh = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Call the test function
    test();

    return 0;
}

void test() {
    // Print the values for verification
    std::cout << "E_hartree = " << HartreeVariables::E_hartree << std::endl;
    std::cout << "Vh = ";
    for (const auto& v : HartreeVariables::Vh) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Test for correctness
    bool passed = true;
    double expectedE_hartree = 1.234;
    std::vector<double> expectedVh = {1.1, 2.2, 3.3, 4.4, 5.5};

    if (std::abs(HartreeVariables::E_hartree - expectedE_hartree) > 1.0e-12) {
        std::cout << "E_hartree test failed" << std::endl;
        passed = false;
    } else {
        std::cout << "E_hartree test passed" << std::endl;
    }

    if (HartreeVariables::Vh != expectedVh) {
        std::cout << "Vh test failed" << std::endl;
        passed = false;
    } else {
        std::cout << "Vh test passed" << std::endl;
    }

    if (passed) {
        std::cout << "All tests passed" << std::endl;
    }
}