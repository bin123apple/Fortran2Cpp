#include <iostream>
#include <vector>

void showAll(double*** z, int n1, int n2, int n3) {
    int m1 = std::min(n1, 18);
    int m2 = std::min(n2, 14);
    int m3 = std::min(n3, 18);

    for (int i3 = 1; i3 <= m3; ++i3) {
        for (int i1 = 1; i1 <= m1; ++i1) {
            for (int i2 = 1; i2 <= m2; ++i2) {
                std::cout << std::setw(6) << std::setprecision(3) << z[i1-1][i2-1][i3-1] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << " - - - - - - - " << std::endl;
    }
    std::cout << "  " << std::endl;
}

int main() {
    // Initialize z array (assuming 3D array of doubles)
    double*** z = new double**[18];
    for (int i = 0; i < 18; ++i) {
        z[i] = new double*[14];
        for (int j = 0; j < 14; ++j) {
            z[i][j] = new double[18];
            // Initialize z array elements
        }
    }

    // Call showAll function
    showAll(z, 18, 14, 18);

    // Clean up memory
    for (int i = 0; i < 18; ++i) {
        delete[] z[i];
    }
    delete[] z;

    return 0;
}
