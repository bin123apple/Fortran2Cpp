#include <iostream>
#include <iomanip> // For std::setprecision

// Function prototype declaration
void inv3x3(float a[3][3], float ainv[3][3]);

int main() {
    float a[3][3] = {
        {1, 2, 3},
        {0, 4, 5},
        {1, 0, 6}
    };

    float ainv[3][3];

    inv3x3(a, ainv);

    std::cout << "Inverse Matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // Use std::setprecision for better output formatting
            std::cout << std::setprecision(3) << ainv[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// Function definition
void inv3x3(float a[3][3], float ainv[3][3]) {
    float det;

    det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        + a[0][1] * (a[1][2] * a[2][0] - a[1][0] * a[2][2])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    ainv[0][0] = (a[1][1] * a[2][2] - a[1][2] * a[2][1]) / det;
    ainv[1][0] = (a[1][2] * a[2][0] - a[1][0] * a[2][2]) / det;
    ainv[2][0] = (a[1][0] * a[2][1] - a[1][1] * a[2][0]) / det;
    ainv[0][1] = (a[0][2] * a[2][1] - a[0][1] * a[2][2]) / det;
    ainv[1][1] = (a[0][0] * a[2][2] - a[0][2] * a[2][0]) / det;
    ainv[2][1] = (a[0][1] * a[2][0] - a[0][0] * a[2][1]) / det;
    ainv[0][2] = (a[0][1] * a[1][2] - a[0][2] * a[1][1]) / det;
    ainv[1][2] = (a[0][2] * a[1][0] - a[0][0] * a[1][2]) / det;
    ainv[2][2] = (a[0][0] * a[1][1] - a[0][1] * a[1][0]) / det;
}