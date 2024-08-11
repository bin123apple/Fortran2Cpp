#include <iostream>

void subr() {
    float a[50] = {}; // Initialize all elements to 0.0f by default
    
    // Fortran: a(1:2:3) = 0 (Every 2nd element from 1 to 3, inclusive. Only affects a(1) in Fortran, translates to no operation in C++ as it's a single element)
    
    // Fortran: a(1:2) = 0 (Every element from 1 to 2, inclusive. Affects a(1) and a(2) in Fortran)
    for (int i = 0; i < 2; i++) {
        a[i] = 0;
    }
    
    // Fortran: a(1::3) = 0 (Every 3rd element, starting from 1)
    for (int i = 0; i < 50; i += 3) {
        a[i] = 0;
    }
    
    // Fortran: a(::3) = 0 (Every 3rd element in the array)
    for (int i = 0; i < 50; i += 3) {
        a[i] = 0;
    }
    
    // Fortran: a(:2) = 0 (Every element up to the 2nd one, inclusive. Affects a(1) and a(2) in Fortran)
    for (int i = 0; i < 2; i++) {
        a[i] = 0;
    }
    
    // Fortran: a(1:) = 0 (Every element starting from the first one)
    for (int i = 0; i < 50; i++) {
        a[i] = 0;
    }
    
    // Fortran: a(:) = 0 (Every element in the array)
    for (int i = 0; i < 50; i++) {
        a[i] = 0;
    }
    
    // Fortran: a(1) = 0 (The first element, translates to the 0th element in C++)
    a[0] = 0;
}

int main() {
    subr();
    return 0;
}