#include <iostream>

int main() {
    int hx[6][6]; // Array indices start from 0 in C++
    int ps, e2;

    for(ps = 0; ps < 6; ++ps) { // Loop indices start from 0 to 5 to correspond to Fortran's 1 to 6
        for(e2 = 0; e2 < 6; ++e2) {
            hx[e2][ps] = 0;
            if (ps >= 4 && e2 >= 4) { // Adjusted indices to match Fortran's logic (Fortran indices start from 1)
                hx[e2][ps] = hx[0][0]; // Adjusted to 0-based indexing
            }
        }
    }

    return 0;
}