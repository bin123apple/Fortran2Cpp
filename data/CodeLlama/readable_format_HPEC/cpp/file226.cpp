#include <iostream>
#include <vector>
#include <cmath>

const double M_PI = 3.14159265358979323846;

template<typename T>
void init_array(std::vector<std::vector<T>>& a, std::vector<T>& x, int nx, int ny) {
    for (int i = 0; i < ny; ++i) {
        x[i] = static_cast<T>(i) * M_PI;
        for (int j = 0; j < ny; ++j) {
            a[j][i] = static_cast<T>((i * (j + 1))) / nx;
        }
    }
}

int main() {
    int nx = 10; // Example size
    int ny = 10; // Example size

    std::vector<std::vector<double>> a(ny, std::vector<double>(nx));
    std::vector<double> x(ny);

    init_array(a, x, nx, ny);

    // Example: Print the first and last elements to verify the initialization
    std::cout << "First element of x: " << x[0] << std::endl;
    std::cout << "Last element of x: " << x[ny - 1] << std::endl;
    std::cout << "First element of a[0]: " << a[0][0] << std::endl;
    std::cout << "Last element of a[ny-1]: " << a[ny - 1][nx - 1] << std::endl;

    return 0;
}
