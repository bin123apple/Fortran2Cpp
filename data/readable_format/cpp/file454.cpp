#include <cstdlib> // For std::abort

int main() {
    // Assuming integer*8 corresponds to a 64-bit integer in Fortran.
    // We use long long in C++ which is at least 64 bits.
    long long foo, bar;
    
    // In C++, floating-point literals are double by default. 
    // The 'e' notation works similarly as in Fortran.
    double r = 4e10;
    
    foo = static_cast<long long>(4e10);
    bar = static_cast<long long>(r);
    
    // In C++, the '!=' operator is used to test inequality.
    if (foo != bar) std::abort();
    
    return 0;
}