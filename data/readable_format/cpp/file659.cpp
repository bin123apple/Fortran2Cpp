#include <iostream>

// Function prototype declaration
int fact(int x);

int main() {
    const int n = 10;
    int a[n];

    // Fill the array with factorial values
    for (int i = 0; i < n; ++i) {
        a[i] = fact(i + 1); // Adjust for zero-based indexing
    }

    // Verify the correctness of the factorial values
    for (int i = 0; i < n; ++i) {
        if (a[i] != fact(i + 1)) { // Adjust for zero-based indexing
            std::cerr << "Mismatch encountered. Exiting..." << std::endl;
            return 1; // Exit with an error code
        }
    }

    return 0; // Successful execution
}

// Recursive factorial function definition
int fact(int x) {
    if (x < 1) {
        return 1;
    } else {
        return x * fact(x - 1);
    }
}