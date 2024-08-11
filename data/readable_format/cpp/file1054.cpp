#include <iostream>
#include <cstdlib> // For std::exit

// Function to mimic Fortran's dim intrinsic function
template<typename T>
T dim(T x, T y) {
    return (x > y) ? (x - y) : 0;
}

int main() {
    int i, j;
    float r, s; // float is typically 4 bytes (32 bits), equivalent to real(kind=4)
    double p, q; // double is typically 8 bytes (64 bits), equivalent to real(kind=8)

    i = 1;
    j = 4;
    if (dim(i, j) != 0) std::exit(1);
    if (dim(j, i) != 3) std::exit(2);

    r = 1.0f; // Suffix 'f' for float literals
    s = 4.0f;
    if (dim(r, s) != 0.0f) std::exit(3);
    if (dim(s, r) != 3.0f) std::exit(4);

    p = 1.0; // double literals don't need a suffix
    q = 4.0;
    if (dim(p, q) != 0.0) std::exit(5);
    if (dim(q, p) != 3.0) std::exit(6);

    return 0;
}