#include <iostream>
#include <cassert>

// Using union for equivalence as in the original translation
union Equivalence {
    float A;
    float B;
};

void verify(float x, float y, float expected) {
    if (x == expected && y == expected) {
        std::cout << "Test Passed: A = " << x << " B = " << y << " Expected = " << expected << std::endl;
    } else {
        std::cerr << "Test Failed: A = " << x << " B = " << y << " Expected = " << expected << std::endl;
        std::abort(); // Use assert or abort to halt if this was a real unit test.
    }
}

int main() {
    Equivalence eq;

    eq.A = 0.0f; // Initialize A
    verify(eq.A, eq.B, 0.0f);

    eq.B = 5.0f; // Modify B, which also modifies A due to union
    verify(eq.A, eq.B, 5.0f);

    return 0;
}