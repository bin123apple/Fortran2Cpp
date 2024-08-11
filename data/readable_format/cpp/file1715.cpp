#include <iostream>

int main() {
    int a; // Declare 'a'

    // Since the original if condition is always true but does nothing,
    // we can directly translate it; however, it's more conventional to use
    // the else block for cases that are not the main path of execution.
    if (true) {
        // Intentionally left blank, as in the Fortran code.
    } else {
        a = 1;
    }

    // Assuming you might want to see the result of 'a'.
    // This line is not a direct translation but helps demonstrate the effect.
    std::cout << "Value of a: " << a << std::endl;

    return 0;
}