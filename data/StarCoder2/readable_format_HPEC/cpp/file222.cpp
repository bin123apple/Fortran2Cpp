#include <cmath> // For M_PI and pow function

// Assuming DATA_TYPE is double for this translation
void init_array(double** a, double* x, int nx, int ny) {
    const double M_PI = 3.14159265358979323846;

    // Initialize x array
    for (int i = 0; i < ny; ++i) {
        x[i] = static_cast<double>(i) * M_PI;
    }

    // Initialize a array
    for (int i = 0; i < ny; ++i) {
        for (int j = 0; j < ny; ++j) {
            a[j][i] = (static_cast<double>((i) * (j + 1))) / nx;
        }
    }
}
