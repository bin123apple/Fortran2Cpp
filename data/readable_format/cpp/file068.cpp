#include <array>

struct t {
    bool valid; // logical in Fortran is similar to bool in C++
    int x, y;   // integer in Fortran is similar to int in C++
};

int main() {
    std::array<t, 5> s; // Define an array 's' of 5 elements of type 't'
    std::array<t, 5> d; // Define another array 'd' of 5 elements of type 't'

    // Copy the elements from 's' to 'd'
    // In C++, you can use std::copy for this purpose
    std::copy(s.begin(), s.end(), d.begin());

    return 0;
}