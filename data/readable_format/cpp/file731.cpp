#include <iostream>
#include <complex>
#include <cstdlib>

// Assuming the functions are in global scope for simplicity

// Simulating f1 and e1 from Fortran
int f1(int a) {
    return 15 + a;
}

double e1(int b) {
    return 42 + b;
}

// Simulating f2 from Fortran
std::complex<double> f2(int a) {
    if (a > 0) {
        return std::complex<double>(45, 0); // Assuming a complex representation for the 'else' part
    } else {
        return std::complex<double>(45, 0);
    }
}

bool e2(int a) {
    if (a > 0) {
        return a < 46;
    } else {
        return false;
    }
}

// Simulating f3, e3, and g3 from Fortran
float f3(int a) {
    return 15 + a;
}

bool e3(int b) {
    return b == 42;
}

std::complex<double> g3(int b) {
    return std::complex<double>(b + 11, 0);
}

// Simulating f4, e4, and g4 from Fortran
bool f4(int a) {
    return a < 0;
}

int e4(int a) {
    if (a == 0) return 16 + a;
    return 0; // Need to handle the case when `a` is not 0
}

double g4(int a) {
    if (a > 0) return 17 + a;
    return 0; // Need to handle the case when `a` is not positive
}

int main() {
    if (f1(6) != 21) std::abort();
    if (e1(7) != 49) std::abort();
    if (f2(0).real() != 45) std::abort();
    if (!e2(45)) std::abort();
    if (e2(46)) std::abort();
    if (f3(17) != 32) std::abort();
    if (!e3(42)) std::abort();
    if (e3(41)) std::abort();
    if (g3(12).real() != 23) std::abort();
    if (!f4(-5)) std::abort();
    if (e4(0) != 16) std::abort();
    if (g4(2) != 19) std::abort();

    return 0;
}