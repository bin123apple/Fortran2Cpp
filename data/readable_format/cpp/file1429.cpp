#include <iostream>
#include <vector>
#include <algorithm> // For std::min

// Function declaration
void div1(int nx1, int ny1, std::vector<std::vector<float>>& array1,
          int nx2, int ny2, const std::vector<std::vector<float>>& array2,
          int nx3, int ny3, std::vector<std::vector<float>>& array3);

int main() {
    std::vector<std::vector<float>> array1 = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<std::vector<float>> array2 = {{1.0, 2.0, 3.0}, {4.0, 0.005, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<std::vector<float>> array3(3, std::vector<float>(3, 0.0f));

    div1(3, 3, array1, 3, 3, array2, 3, 3, array3);

    std::cout << "Result array3:" << std::endl;
    for (const auto& row : array3) {
        for (float elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// Function definition
void div1(int nx1, int ny1, std::vector<std::vector<float>>& array1,
          int nx2, int ny2, const std::vector<std::vector<float>>& array2,
          int nx3, int ny3, std::vector<std::vector<float>>& array3) {
    int min_ny = std::min({ny1, ny2, ny3});
    int min_nx = std::min({nx1, nx2, nx3});

    for (int j = 0; j < min_ny; ++j) {
        for (int i = 0; i < min_nx; ++i) {
            if (array2[i][j] > 0.01f) {
                array3[i][j] = array1[i][j] / array2[i][j];
            } else {
                array3[i][j] = 0.0f;
            }
        }
    }

    if (ny3 > min_ny) {
        for (int j = min_ny; j < ny3; ++j) {
            for (int i = 0; i < nx3; ++i) {
                array3[i][j] = 0.0f;
            }
        }
    }

    if (nx3 > min_nx) {
        for (int j = 0; j < ny3; ++j) {
            for (int i = min_nx; i < nx3; ++i) {
                array3[i][j] = 0.0f;
            }
        }
    }
}