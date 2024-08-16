#include <iostream>

// Assuming the existence of these functions
void compute_rhs();
void x_solve();
void y_solve();
void z_solve();
void add();

void adi() {
    compute_rhs();
    x_solve();
    y_solve();
    z_solve();
    add();
}

int main() {
    adi();
    return 0;
}
