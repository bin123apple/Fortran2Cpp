#include <iostream>
#include <cmath> // For std::abs
#include <cstdlib> // For std::abort()

// Function prototype declaration is optional in this case since the function definition is before main.
void DAXPY(int N, double DA, double DX[], double DY[]);

int main() {
    int N = 5;
    double DA = 1.0;
    double DX[9] = {-2, -1, -3, -4, 1, 2, 10, 15, 14};
    double DY[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    DAXPY(N, DA, DX, DY);

    // Expected DY after DAXPY operation: {-2, -1, -3, -4, 1}
    double expectedDY[5] = {-2, -1, -3, -4, 1};
    for (int I = 0; I < N; ++I) {
        if (std::abs(DY[I] - expectedDY[I]) > 1e-9) { // Using a small threshold for floating point comparison
            std::abort(); // Replace with more sophisticated error handling as needed
        }
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}

void DAXPY(int N, double DA, double DX[], double DY[]) {
    for (int I = 0; I < N; ++I) {
        DY[I] = DY[I] + DA * DX[I];
    }
}