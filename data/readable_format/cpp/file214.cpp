#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint> // For std::int64_t
#include <cmath>   // For std::fabs

// Converts a vector of integers to a vector of floats
void INTG2REAL(int size, const std::vector<int>& intg, std::vector<float>& grid) {
    grid.resize(size);    
    for (int i = 0; i < size; ++i) {
        grid[i] = static_cast<float>(intg[i]);
    }
}

// Converts a vector of 8-byte integers (int64_t) to a vector of floats
void INT82REAL(int size, const std::vector<std::int64_t>& int8, std::vector<float>& grid) {
    grid.resize(size);    
    for (int i = 0; i < size; ++i) {
        grid[i] = static_cast<float>(int8[i]);
    }
}

void testINTG2REAL() {
    std::vector<int> intg = {1, 0, -1};
    std::vector<float> grid;
    INTG2REAL(intg.size(), intg, grid);

    assert(grid.size() == intg.size());
    assert(grid[0] == static_cast<float>(intg[0]));
    assert(grid[1] == static_cast<float>(intg[1]));
    assert(grid[2] == static_cast<float>(intg[2]));

    std::cout << "INTG2REAL tests passed." << std::endl;
}

void testINT82REAL() {
    std::vector<std::int64_t> int8 = {2147483647LL, 0LL, -2147483648LL};
    std::vector<float> grid;
    INT82REAL(int8.size(), int8, grid);

    assert(grid.size() == int8.size());
    // Use std::fabs for floating-point absolute value comparison
    assert(std::fabs(grid[0] - static_cast<float>(int8[0])) < 1e-6);
    assert(std::fabs(grid[1] - static_cast<float>(int8[1])) < 1e-6);
    assert(std::fabs(grid[2] - static_cast<float>(int8[2])) < 1e-6);

    std::cout << "INT82REAL tests passed." << std::endl;
}

int main() {
    testINTG2REAL();
    testINT82REAL();

    return 0;
}