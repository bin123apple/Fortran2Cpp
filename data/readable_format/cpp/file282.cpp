#include <iostream>

// Function prototype declaration
double REF(double A);

int main() {
    double X;
    X = REF(2.0);
    std::cout << X << std::endl;
    return 0;
}

// Function definition
double REF(double A) {
    double B;
    B = A + A;
    return B;
}