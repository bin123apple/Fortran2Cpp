#include <iostream>
#include <cassert> // Include the cassert header for assert()

class volmod {
public:
    static volatile int a;
    static volatile bool b; // Made volatile as per Fortran code
    static bool c;

    static void sample() {
        a = 33;
        if(a != 432) std::cout << "aPresent" << std::endl;

        b = false;
        if(b) std::cout << "bPresent" << std::endl;

        c = false;
        if(c) std::cout << "cPresent" << std::endl;
    }
};

// Define static members outside the class
volatile int volmod::a;
volatile bool volmod::b;
bool volmod::c;

void test_volmod() {
    // Initial state checks
    volmod::a = 432;
    assert(volmod::a == 432);
    volmod::b = false;
    assert(!volmod::b);
    volmod::c = false;
    assert(!volmod::c);

    // Call the sample and check effects
    volmod::sample();
    assert(volmod::a == 33);
    assert(!volmod::b);
    assert(!volmod::c);

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_volmod();
    return 0;
}