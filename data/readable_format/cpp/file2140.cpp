#include <iostream>

const int n = 800;
const int arraySize1 = 4; // 0 to 3 inclusive
const int arraySize2 = n + 1; // 1 to n inclusive

struct NormSplin {
    double x_norm[arraySize1][arraySize2];
    double y_norm[arraySize1][arraySize2];
    double dx;
};

int main() {
    // Create an instance of the NormSplin structure
    NormSplin normsplin;

    // Example of accessing the structure members
    normsplin.dx = 0.0; // Assign a value to dx, you can change this as needed

    // Accessing elements, for example:
    normsplin.x_norm[0][1] = 1.0;
    normsplin.y_norm[0][1] = 2.0;

    // Print out values to verify
    std::cout << "dx: " << normsplin.dx << std::endl;
    std::cout << "x_norm[0][1]: " << normsplin.x_norm[0][1] << std::endl;
    std::cout << "y_norm[0][1]: " << normsplin.y_norm[0][1] << std::endl;

    return 0;
}