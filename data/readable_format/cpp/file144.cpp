#include <iostream>
#include <array>
#include <cassert>

// Equivalent of Fortran module eq with equivalence and common block
namespace eq {
    struct A {
        std::array<int, 2> a;
    } common_a;

    int& n1 = common_a.a[0];
    int& n2 = common_a.a[1];
}

// Equivalent of Fortran module m
namespace m {
    struct t {
        int i;
    };
}

// Equivalent of Fortran module p
namespace p {
    int d(int h) {
        return h;
    }
}

// Equivalent of Fortran module q
namespace q {
    int d(int h) {
        return h;
    }
}

// Equivalent of Fortran module r
namespace r {
    int d(int h) {
        return h;
    }
}

// Simple testing mechanism
void runTests() {
    // Test equivalence and common block behavior
    eq::n1 = 5;
    eq::n2 = 10;
    assert(eq::common_a.a[0] == 5);
    assert(eq::common_a.a[1] == 10);
    std::cout << "Test for equivalence and common block in eq namespace passed." << std::endl;

    // Test pure functions
    assert(p::d(15) == 15);
    std::cout << "Test for pure function in p namespace passed." << std::endl;

    assert(q::d(20) == 20);
    std::cout << "Test for pure function in q namespace passed." << std::endl;

    assert(r::d(25) == 25);
    std::cout << "Test for pure function in r namespace passed." << std::endl;

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    // Run all tests
    runTests();

    return 0;
}