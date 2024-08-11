#include <iostream>

void s1() {
    // First loop, equivalent of `cycle` is `continue` in C++
    for (int i = 1; i <= 10; ++i) {
        continue;
    }

    // Second loop, equivalent of `exit` is `break` in C++
    for (int i = 1; i <= 10; ++i) {
        break;
    }

    // Third compound loop with labels 'outer' and 'inner'
    for (int i = 1; i <= 10; ++i) {
        continue; // This would skip the rest of the loop body, equivalent of `cycle` in Fortran
        for (int j = 1; j <= 10; ++j) {
            continue; // This would only affect the inner loop, equivalent of `cycle` in the 'inner' loop in Fortran
        }
        continue; // This would skip back to the start of the outer loop, equivalent of `cycle` in the 'outer' loop in Fortran
    }

    // These are outside any loop and thus do not translate directly to C++.
    // In Fortran, 'cycle' and 'exit' outside of a loop context refer to named loop constructs.
    // C++ does not support this directly, so we'll omit these as their inclusion would be syntactically incorrect.

    // Conditional statements with 'cycle' and 'exit', which would be continue and break.
    // However, since they're not inside a loop here, they don't directly translate.
    // In actual code, 'continue' and 'break' must be used inside loops.
    if (true) {} // Equivalent of `if(.true.) cycle` but does nothing outside a loop
    if (true) {} // Equivalent of `if(.true.) exit` but does nothing outside a loop
}

int main() {
    s1();
    return 0;
}