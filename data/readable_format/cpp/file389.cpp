#include <iostream>

// Forward declaration with a default parameter value
void sub(float& a, int i = -1);

int main() {
    float a;
    // Calling sub with a single argument
    sub(a);
    return 0;
}

// Definition of sub
void sub(float& a, int i) {
    // In this translated version, 'a' is passed by reference.
    // 'i' is an optional parameter with a default value to indicate it wasn't provided.
    // The body of the subroutine would go here.
}