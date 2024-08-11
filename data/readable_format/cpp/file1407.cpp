#include <iostream>

int main() {
    int i;
    float r;

    // This loop will not run because the condition is never true.
    for (i = 1; i <= 0; ++i) {
    }

    // This loop's condition is never true, so it will also not run.
    for (i = 1; i <= -1; i += 1) {
    }

    // This loop's condition is never true because step is negative and start < end.
    for (i = 1; i >= 2; i -= 1) {
    }

    // Loops with step 0 are undefined in Fortran, translating such loops to C++ is not straightforward.
    // An equivalent C++ loop would not terminate. A direct translation is not practical or safe.
    // for (i = 1; i <= 2; /* step of 0 is undefined behavior */) {
    // }

    // These loops with a floating-point counter are similar to their integer counterparts.
    for (r = 1; r <= 0; ++r) {
    }

    for (r = 1; r <= -1; r += 1) {
    }

    for (r = 1; r >= 2; r -= 1) {
    }

    // Again, a loop with a step of 0 is undefined. Not directly translatable to safe C++ code.
    // for (r = 1; r <= 2; /* step of 0 is undefined behavior */) {
    // }

    return 0;
}