#include <iostream>
#include <cmath> // For fabs function

// Assuming you want similar functionality as described in the Fortran code, but directly in C++
class M2 {
public:
    static int func(int a) {
        return a * 8;
    }
    static float ent(int a) {
        return -a * 4.0f;
    }
};

class M3 {
public:
    static int func(int a) {
        return a * 12;
    }
    static float ent(int a) {
        return -a * 6.0f;
    }
};

bool areFloatsEqual(float a, float b) {
    return std::fabs(a - b) < 1e-6; // Adjust epsilon as necessary
}

int main() {
    // Test variables
    int testVal = 2;
    bool testPassed = true;

    // M2 Tests
    if (M2::func(testVal) != 16) {
        std::cout << "M2::func failed!" << std::endl;
        testPassed = false;
    }
    if (!areFloatsEqual(M2::ent(testVal), -8.0f)) {
        std::cout << "M2::ent failed!" << std::endl;
        testPassed = false;
    }

    // M3 Tests
    if (M3::func(testVal) != 24) {
        std::cout << "M3::func failed!" << std::endl;
        testPassed = false;
    }
    if (!areFloatsEqual(M3::ent(testVal), -12.0f)) {
        std::cout << "M3::ent failed!" << std::endl;
        testPassed = false;
    }

    if (testPassed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}