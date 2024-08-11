// single_file_example.cpp
#include <iostream>

// Assuming "wp" corresponds to "double" precision
using wp = double;

// Definition of the "dis" structure within the same file
struct dis {
    wp x, y, z;
    wp mag, mag2;
    wp riy, rjy, yim;
    wp magim, mag2im;
    wp rjx, rjz;
    wp rix, riz;

    // Constructor to initialize members to zero
    dis() : x(0), y(0), z(0), mag(0), mag2(0), riy(0), rjy(0), yim(0),
            magim(0), mag2im(0), rjx(0), rjz(0), rix(0), riz(0) {}
};

// Function prototypes for unit tests
bool test_instantiation_and_defaults();
bool test_modification();

int main() {
    std::cout << "Testing instantiation and default values..." << std::endl;
    if (test_instantiation_and_defaults()) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    std::cout << "Testing modification..." << std::endl;
    if (test_modification()) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}

// Implementations of the unit tests
bool test_instantiation_and_defaults() {
    dis test_var;
    return test_var.x == 0.0 && test_var.y == 0.0 && test_var.z == 0.0;
}

bool test_modification() {
    dis test_var;
    test_var.x = 1.0;
    test_var.y = 2.0;
    test_var.z = 3.0;
    return test_var.x == 1.0 && test_var.y == 2.0 && test_var.z == 3.0;
}