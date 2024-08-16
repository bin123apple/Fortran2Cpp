#include <iostream>

// Assuming the dimensions of the arrays are known and defined globally
extern int grid_points[3];
extern double* u; // Assuming u is a 3D array represented as a 1D array in memory
extern double* rhs; // Assuming rhs is a 3D array represented as a 1D array in memory

// Timer functions, if needed
void timer_start(int t_add);
void timer_stop(int t_add);

void add() {
    int i, j, k, m;

    if (timeron) timer_start(t_add);

    for (k = 1; k < grid_points[2] - 1; ++k) {
        for (j = 1; j < grid_points[1] - 1; ++j) {
            for (i = 1; i < grid_points[0] - 1; ++i) {
                for (m = 0; m < 5; ++m) { // Adjusted for 0-based indexing
                    u[m + 5 * (i + grid_points[0] * (j + grid_points[1] * k))] =
                        u[m + 5 * (i + grid_points[0] * (j + grid_points[1] * k))] +
                        rhs[m + 5 * (i + grid_points[0] * (j + grid_points[1] * k))];
                }
            }
        }
    }

    if (timeron) timer_stop(t_add);
}

// Example of how to define the global variables and the arrays
int grid_points[3] = {10, 10, 10}; // Example dimensions
double* u = new double[5 * grid_points[0] * grid_points[1] * grid_points[2]]; // 3D array flattened to 1D
double* rhs = new double[5 * grid_points[0] * grid_points[1] * grid_points[2]]; // 3D array flattened to 1D

int main() {
    // Example usage
    add();

    // Clean up
    delete[] u;
    delete[] rhs;

    return 0;
}
