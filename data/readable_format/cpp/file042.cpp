#include <iostream>

// Translated rswitch subroutine for float (real*4 in Fortran)
void rswitch(float& x, float& y) {
    float z = x;
    x = y;
    y = z;
}

// Translated dswitch subroutine for double (real*8 in Fortran)
void dswitch(double& x, double& y) {
    double z = x;
    x = y;
    y = z;
}

// Translated iswitch subroutine for integers
void iswitch(int& i, int& j) {
    int k = j;
    j = i;
    i = k;
}

int main() {
    // Example usage
    float rf = 1.2f, rf2 = 3.4f;
    double rd = 1.234, rd2 = 5.678;
    int ri = 1, ri2 = 2;

    std::cout << "Before rswitch: " << rf << ", " << rf2 << std::endl;
    rswitch(rf, rf2);
    std::cout << "After rswitch: " << rf << ", " << rf2 << std::endl;

    std::cout << "Before dswitch: " << rd << ", " << rd2 << std::endl;
    dswitch(rd, rd2);
    std::cout << "After dswitch: " << rd << ", " << rd2 << std::endl;

    std::cout << "Before iswitch: " << ri << ", " << ri2 << std::endl;
    iswitch(ri, ri2);
    std::cout << "After iswitch: " << ri << ", " << ri2 << std::endl;

    return 0;
}