#include <iostream>

// Forward declaration of s to ensure it's known before t tries to call it
void s();

// Definition of subroutine t which calls s
void t() {
    s();
}

// Definition of subroutine s
void s() {
    // Implementation of s (empty in the given code)
}

int main() {
    // Call t from main
    t();
    return 0;
}