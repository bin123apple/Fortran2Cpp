#include <iostream>
#include <vector>

// Function Declaration
int triloc(double xp, double yp, const std::vector<double>& x, const std::vector<double>& y, const std::vector<std::vector<int>>& v, const std::vector<std::vector<int>>& e, int numtri);

// Main function to run tests
int main() {
    // Example of a simple triangle and a test point
    std::vector<double> x = {0.0, 10.0, 5.0};
    std::vector<double> y = {0.0, 0.0, 10.0};
    std::vector<std::vector<int>> v = {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}};
    std::vector<std::vector<int>> e = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    double xp = 5.0;
    double yp = 5.0;
    int numtri = 1;

    int result = triloc(xp, yp, x, y, v, e, numtri);
    if (result == 1) {
        std::cout << "Test Passed: Point is inside the triangle." << std::endl;
    } else {
        std::cout << "Test Failed: Point is not inside the triangle." << std::endl;
    }

    return 0;
}

// Function Definition
int triloc(double xp, double yp, const std::vector<double>& x, const std::vector<double>& y, const std::vector<std::vector<int>>& v, const std::vector<std::vector<int>>& e, int numtri) {
    int t = numtri;
    while (true) {
        for (int i = 0; i < 3; ++i) {
            int v1 = v[i][t - 1]; // Adjusting for 0-based indexing in C++
            int v2 = v[(i % 3) + 1 - 1][t - 1]; // Adjusting for 0-based indexing in C++
            if ((y[v1 - 1] - yp) * (x[v2 - 1] - xp) > (x[v1 - 1] - xp) * (y[v2 - 1] - yp)) { // Adjusting for 0-based indexing
                t = e[i][t - 1]; // Adjust to 0-based indexing
                break; // Replaces the GOTO 10 statement
            }
            if (i == 2) {
                // If the loop completes without changing triangles, we've found the containing triangle
                return t;
            }
        }
    }
}