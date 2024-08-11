#include <array>

// Define the size of the arrays
constexpr int n = 1000;

// Declare the arrays globally to mimic the Fortran COMMON block
std::array<int, n> a;
std::array<int, n> b;
std::array<int, n> c;

void foo(int nr) {
    for (int ii = 0; ii < nr; ++ii) {
        c[ii] = a[ii] + b[ii] + 25;
    }
}