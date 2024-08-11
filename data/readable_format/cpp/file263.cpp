#include <iostream>
#include <cmath> // For std::abs in case of floating-point comparisons

// Namespace for xmod
namespace xmod {
    int x = -666;

    int foo() {
        return 42;
    }

    int bar(int a) {
        return a;
    }
}

// Namespace for ymod
namespace ymod {
    int y = -666;

    int foo() {
        return 42;
    }

    int bar(int a) {
        return a;
    }
}

// Simple testing framework
namespace test {
    void assertEqual(int expected, int actual, const std::string& testName) {
        if (expected != actual) {
            std::cerr << "Test failed: " << testName << " - Expected: " << expected << ", Actual: " << actual << std::endl;
        } else {
            std::cout << "Test passed: " << testName << std::endl;
        }
    }
}

int main() {
    // Adjusting the values as per the original logic
    xmod::x = 666;
    ymod::y = 666;

    // Running tests
    test::assertEqual(666, xmod::x, "xmod::x assignment");
    test::assertEqual(666, ymod::y, "ymod::y assignment");

    test::assertEqual(42, xmod::foo(), "xmod::foo()");
    test::assertEqual(100, xmod::bar(100), "xmod::bar(100)");

    test::assertEqual(42, ymod::foo(), "ymod::foo()");
    test::assertEqual(50, ymod::bar(50), "ymod::bar(50)");

    return 0;
}