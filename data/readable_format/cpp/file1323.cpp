#include <iostream>

void insertsortd(double* dx, int n) {
    double xtmp;
    int j;
    for (int i = 1; i < n; i++) { // Adjusted for zero-based indexing
        xtmp = dx[i];
        for (j = i - 1; j >= 0; j--) { // Adjusted loop to start from i - 1
            if (xtmp < dx[j]) {
                dx[j + 1] = dx[j];
            } else {
                break; // Replaces the 'exit' in Fortran
            }
        }
        dx[j + 1] = xtmp; // Adjusted for zero-based indexing
    }
}

int main() {
    // Example usage
    double dx[] = {5.5, 2.2, 9.1, 3.3, 4.4};
    int n = sizeof(dx) / sizeof(dx[0]);

    insertsortd(dx, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        std::cout << dx[i] << " ";
    }

    return 0;
}