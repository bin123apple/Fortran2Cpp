#include <iostream>
#include <cmath>

class dt {
public:
    float r;

    dt(float val = 0.0) : r(val) {} // Constructor with default value

    // Operator overloading for adding dt objects
    dt operator+(const dt &other) const {
        return dt(r + other.r);
    }

    // Function for custom addition, equivalent to .myadd. in Fortran
    dt myadd(const dt &other) const {
        return dt(r + other.r);
    }
};

void testAddition() {
    dt d1(5.0), d2(10.0), result;
    
    // Test using overloaded operator+
    result = d1 + d2;
    if (std::abs(result.r - 15.0) < 1e-5) {
        std::cout << "Test operator+ Passed";
    } else {
        std::cout << "Test operator+ Failed";
    }
    std::cout << std::endl;

    // Test using custom myadd function
    result = d1.myadd(d2);
    if (std::abs(result.r - 15.0) < 1e-5) {
        std::cout << "Test myadd Passed";
    } else {
        std::cout << "Test myadd Failed";
    }
    std::cout << std::endl;
}

int main() {
    testAddition();

    return 0;
}