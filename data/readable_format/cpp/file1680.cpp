#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

typedef std::vector<std::vector<std::vector<double>>> ThreeDVector;

// Function to create a 3D vector initialized with a given value
ThreeDVector create3DVector(double value) {
    return ThreeDVector(2, std::vector<std::vector<double>>(2, std::vector<double>(2, value)));
}

// Function to extract a 2D slice from a 3D vector
std::vector<std::vector<double>> slice2D(const ThreeDVector& vec, int z) {
    std::vector<std::vector<double>> slice;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::vector<double> row;
        for (size_t j = 0; j < vec[i].size(); ++j) {
            row.push_back(vec[i][j][z]);
        }
        slice.push_back(row);
    }
    return slice;
}

// Function to find the min value in a 2D vector slice
double findMin(const std::vector<std::vector<double>>& slice) {
    double minVal = std::numeric_limits<double>::max();
    for (const auto& row : slice) {
        for (double val : row) {
            minVal = std::min(minVal, val);
        }
    }
    return minVal;
}

// Function to find the max value in a 2D vector slice
double findMax(const std::vector<std::vector<double>>& slice) {
    double maxVal = std::numeric_limits<double>::lowest();
    for (const auto& row : slice) {
        for (double val : row) {
            maxVal = std::max(maxVal, val);
        }
    }
    return maxVal;
}

void testInitialization(const ThreeDVector& x) {
    for (const auto& plane : x) {
        for (const auto& row : plane) {
            for (double val : row) {
                assert(val == 1.0);
            }
        }
    }
}

void testSliceMinMax(const ThreeDVector& x) {
    auto slice = slice2D(x, 0); 
    assert(findMin(slice) == 1.0);
    assert(findMax(slice) == 1.0);
}

int main() {
    ThreeDVector x = create3DVector(1.0);

    try {
        testInitialization(x);
        testSliceMinMax(x);
        std::cout << "All C++ tests passed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}