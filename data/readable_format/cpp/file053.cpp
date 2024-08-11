#include <iostream>

int main() {
    // Declaration of variables
    int i, j;

    // Outer loop
    for (i = 1; i <= 100; ++i) {
        // Inner loop
        for (j = 1; j <= 100; ++j) {
            // Exit the nearest loop, which is the inner loop
            break;
        }
    }

    return 0;
}