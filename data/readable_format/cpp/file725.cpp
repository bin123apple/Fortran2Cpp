#include <iostream>

// Assuming the precision module sets real numbers to double precision.
// C++ uses double for double precision floating-point numbers by default.

void Mouv(double& oper0, double oper1, double& resul) {
    // oper0 is passed by reference and modified.
    // oper1 is passed by value (default in C++), so it's not modified outside this function.
    // resul is passed by reference and is intended to carry the result out.
    resul = oper0 + oper1;
    oper0 = 8.0; // This modifies oper0 in the caller's scope.
}

void Pas_1() {
    double oper0 = 3.0;
    double oper1 = 4.0;
    double resul; // Uninitialized, but will be set before it's used.

    std::cout << "--- Avant --- oper0: " << oper0 << " oper1: " << oper1 << " resul: " << resul << std::endl;

    Mouv(oper0, oper1, resul);

    std::cout << "--- Apres --- oper0: " << oper0 << " oper1: " << oper1 << " resul: " << resul << std::endl;
}

int main() {
    Pas_1();
    return 0;
}