#include <iostream>

// Assuming DATA_TYPE is int for this example
void print_array(int n, int** a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[j][i] << " "; // Adjusted for 0-based indexing
            if ((i * n + j + 1) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
}

// Example usage
int main() {
    const int n = 4;
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = i * n + j + 1; // Example initialization
        }
    }

    print_array(n, a);

    // Clean up
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
