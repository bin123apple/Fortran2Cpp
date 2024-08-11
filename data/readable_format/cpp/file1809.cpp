#include <iostream>
#include <string>

// Define the custom type `tt` equivalent to the Fortran type
struct tt {
    int a;
    double b;
    std::string c;

    // A constructor matching the Fortran initialization
    tt(int a, double b, std::string c) : a(a), b(b), c(c) {}
};

int main() {
    // Initialize an instance of the `tt` type
    tt a(1, 20.0, "ccc");

    // Print the instance's members
    std::cout << a.a << " " << a.b << " " << a.c << std::endl;

    return 0;
}