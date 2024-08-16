#include <iostream>
#include <vector>

// Define the data type
using DATA_TYPE = double;

// Function to initialize the arrays
void init_array(int maxgrid, std::vector<std::vector<DATA_TYPE>>& sumTang, std::vector<std::vector<DATA_TYPE>>& mean, std::vector<std::vector<DATA_TYPE>>& path) {
    // Resize the arrays to match the dimensions (maxgrid x maxgrid)
    sumTang.resize(maxgrid, std::vector<DATA_TYPE>(maxgrid));
    mean.resize(maxgrid, std::vector<DATA_TYPE>(maxgrid));
    path.resize(maxgrid, std::vector<DATA_TYPE>(maxgrid));

    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            sumTang[j][i] = (i + 1) * (j + 1); // Note: Fortran arrays are 1-based, C++ arrays are 0-based
            mean[j][i] = (i - j) / static_cast<DATA_TYPE>(maxgrid);
            path[j][i] = ((i - 1) * (j - 2)) / static_cast<DATA_TYPE>(maxgrid);
        }
    }
}

int main() {
    int maxgrid = 5; // Example value
    std::vector<std::vector<DATA_TYPE>> sumTang;
    std::vector<std::vector<DATA_TYPE>> mean;
    std::vector<std::vector<DATA_TYPE>> path;

    init_array(maxgrid, sumTang, mean, path);

    // Optional: Print the arrays to verify the initialization
    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            std::cout << "sumTang[" << i << "][" << j << "] = " << sumTang[i][j] << ", ";
            std::cout << "mean[" << i << "][" << j << "] = " << mean[i][j] << ", ";
            std::cout << "path[" << i << "][" << j << "] = " << path[i][j] << std::endl;
        }
    }

    return 0;
}
