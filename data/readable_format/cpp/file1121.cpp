#include <cstdint>
#include <cstdio>

int main() {
    // Assuming int64_t can hold at least 18 decimal digits, which it can (19 digits).
    int64_t t = -123456;

    // For double precision, normally provides at least 15 decimal digits precision.
    double x = 1.7;

    // For extended precision, precision and range depend on the compiler and architecture.
    // It might provide at least 33 decimal digits precision, but this is not guaranteed.
    long double y = 1.9;

    printf("t = %ld\n", t);
    printf("x = %.17g\n", x); // Using .17g to potentially print all significant digits of a double
    printf("y = %.35Lg\n", y); // Attempting to print more digits for long double, but precision is platform-dependent

    return 0;
}