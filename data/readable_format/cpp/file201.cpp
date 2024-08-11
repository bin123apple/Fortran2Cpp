#include <iostream>
#include <cmath>

// Equivalent of the Fortran function e1
float e1(float x) {
    return x * 3.0f;
}

// Equivalent of the Fortran subroutine e2
void e2(float& a, float b) {
    a = a + b;
}

int main() {
    // Function pointer declaration and assignment
    float (*fp)(float) = nullptr;
    fp = e1;

    // Checking the condition as in Fortran code
    if (std::abs(fp(2.5f) - 7.5f) > 0.01f) {
        std::cerr << "Error 1" << std::endl;
        return 1; // Equivalent of STOP 1 in Fortran
    }

    // Since C++ does not have a direct equivalent for Fortran's interface
    // and pointer to subroutine, we use function pointers directly.
    // In this case, we can directly use the name of the function `e2`
    // as it matches the required signature.
    void (*sp)(float&, float) = nullptr;
    sp = e2;

    float c = 1.2f;

    // Calling the subroutine through a pointer
    sp(c, 3.4f);

    if (std::abs(c - 4.6f) > 0.01f) {
        std::cerr << "Error 2" << std::endl;
        return 2; // Equivalent of STOP 2 in Fortran
    }

    return 0;
}