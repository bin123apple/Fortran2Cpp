#include <iostream>
#include <cmath>
#include <type_traits>
#include <cassert>

constexpr float pi32 = 4.0f * std::atan(1.0f);
constexpr double pi64 = 4.0 * std::atan(1.0);

template <typename T>
void timestwo(T& a) {
    static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
    a *= 2;
}

// Basic unit tests without an external framework
void run_tests() {
    {
        float a32 = 1.0f;
        timestwo(a32);
        assert(a32 == 2.0f && "Test failed for real32");
    }
    {
        double a64 = 1.0;
        timestwo(a64);
        assert(a64 == 2.0 && "Test failed for real64");
    }
    {
        int a_int = 1;
        timestwo(a_int);
        assert(a_int == 2 && "Test failed for integer");
    }
    std::cout << "All tests passed." << std::endl; // Corrected line
}

int main() {
    // Run the unit tests to verify correctness
    run_tests();

    // Your main program logic here

    return 0;
}