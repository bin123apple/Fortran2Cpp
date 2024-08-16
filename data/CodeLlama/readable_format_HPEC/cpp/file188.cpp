#include <iostream>
#include <iomanip>
#include <algorithm>

void showall(double*** z, int n1, int n2, int n3) {
    int m1, m2, m3;
    m1 = std::min(n1, 18);
    m2 = std::min(n2, 14);
    m3 = std::min(n3, 18);

    std::cout << std::endl;
    for (int i3 = 0; i3 < m3; ++i3) {
        for (int i1 = 0; i1 < m1; ++i1) {
            for (int i2 = 0; i2 < m2; ++i2) {
                std::cout << std::setw(6) << std::setprecision(3) << std::fixed << z[i1][i2][i3] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << " - - - - - - - " << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n1 = 20, n2 = 15, n3 = 20;
    double*** z = new double**[n1];
    for (int i = 0; i < n1; ++i) {
        z[i] = new double*[n2];
        for (int j = 0; j < n2; ++j) {
            z[i][j] = new double[n3];
            // Initialize z with some values for demonstration
            for (int k = 0; k < n3; ++k) {
                z[i][j][k] = i + j + k;
            }
        }
    }

    showall(z, n1, n2, n3);

    // Clean up
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            delete[] z[i][j];
        }
        delete[] z[i];
    }
    delete[] z;

    return 0;
}
