#include <iostream>
#include <cstdlib>

class cx {
public:
    int re;
    int im;

    cx(int real = 0, int imag = 0) : re(real), im(imag) {}

    // Operator overloading for addition
    cx operator+(const cx& other) const {
        return cx(re + other.re, im + other.im);
    }

    // For addition with an integer (from both sides)
    cx operator+(int r) const {
        return cx(re + r, im);
    }
    friend cx operator+(int r, const cx& z) {
        return z + r;
    }

    // Operator overloading for equality
    bool operator==(const cx& other) const {
        return re == other.re && im == other.im;
    }
};

// Test functions
void testAddition() {
    cx a(1, 2), b(3, 4), expected(4, 6);
    cx result = a + b;
    if (!(result == expected)) {
        std::cerr << "Test Addition Failed" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::cout << "Test Addition Passed" << std::endl;
}

void testAdditionWithInt() {
    cx a(5, 6), expected(8, 6);
    cx result = a + 3;
    if (!(result == expected)) {
        std::cerr << "Test Addition with Int Failed" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::cout << "Test Addition with Int Passed" << std::endl;
}

void testEquality() {
    cx a(1, 2), b(1, 2);
    if (!(a == b)) {
        std::cerr << "Test Equality Failed" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::cout << "Test Equality Passed" << std::endl;
}

int main() {
    testAddition();
    testAdditionWithInt();
    testEquality();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}