#include <iostream>
#include <vector>

// Define the ADGRD template function directly in this file
template<typename T>
void ADGRD(int nvals, int start, int incr, T cellwt, const std::vector<T>& data, std::vector<T>& grid, std::vector<T>& weight) {
    int offset = 0;
    for (int j = 1; j < 2 * nvals; j += 2) { // Adjusted loop to start from 1 for 0-based indexing
        if (data[j] >= static_cast<T>(0.0)) {
            T totwt = cellwt * data[j];
            int k = start + offset - 1; // Adjust for 0-based indexing and Fortran's start
            grid[k] = grid[k] + data[j - 1] * totwt;
            weight[k] = weight[k] + totwt;
        }
        offset = offset + incr;
    }
}

// Define the runTest function template
template<typename T>
void runTest(int nvals, int start, int incr, T cellwt, const std::vector<T>& data) {
    std::vector<T> grid(nvals, static_cast<T>(0));
    std::vector<T> weight(nvals, static_cast<T>(0));

    ADGRD<T>(nvals, start, incr, cellwt, data, grid, weight);

    std::cout << "Results:" << std::endl;
    for (size_t i = 0; i < grid.size(); ++i) {
        std::cout << "Grid: " << grid[i] << ", Weight: " << weight[i] << std::endl;
    }
}

// Main function
int main() {
    // Single precision test
    std::vector<float> dataF = {1.0f, 2.0f, 3.0f, -1.0f, 5.0f, 4.0f};
    runTest<float>(3, 1, 1, 0.5f, dataF);

    // Double precision test
    std::vector<double> dataD = {1.0, 2.0, 3.0, -1.0, 5.0, 4.0};
    runTest<double>(3, 1, 1, 0.5, dataD);

    return 0;
}