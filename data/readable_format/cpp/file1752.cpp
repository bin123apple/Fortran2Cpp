#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // For std::abort

struct Obj {
    float array[10][10];
    std::vector<std::vector<float>> array2;

    // Constructor to initialize array2 with specific dimensions
    Obj(int dim1, int dim2) : array2(dim1, std::vector<float>(dim2)) {}
};

int main() {
    // Create an instance of Obj, initializing array2 with dimensions 10x10
    Obj obj1(10, 10);

    // Initialize obj1.array with values 1 through 100
    int val = 1;
    for (auto& row : obj1.array) {
        std::generate(std::begin(row), std::end(row), [&val]() { return val++; });
    }

    // Initialize obj1.array2 with values 1 through 100
    val = 1;
    for (auto& row : obj1.array2) {
        std::generate(row.begin(), row.end(), [&val]() { return val++; });
    }

    // Interfacing with C: Demonstrating address manipulation
    // Direct pointer to the first element of obj1.array
    float* arrayPtr = &obj1.array[0][0];
    // Check if the contents are as expected
    for (int i = 1; i <= 100; ++i) {
        if (arrayPtr[i-1] != static_cast<float>(i)) {
            std::abort();
        }
    }

    // For obj1.array2, since it's a vector of vectors, we need a contiguous memory block for C-like manipulation
    // Assuming you want to demonstrate similar memory address manipulation, but with dynamic allocation
    std::vector<float> flatArray2;
    for (const auto& row : obj1.array2) {
        flatArray2.insert(flatArray2.end(), row.begin(), row.end());
    }
    // Pointer to the first element of the flattened array2
    float* array2Ptr = flatArray2.data();
    // Check if the contents are as expected
    for (int i = 1; i <= 100; ++i) {
        if (array2Ptr[i-1] != static_cast<float>(i)) {
            std::abort();
        }
    }

    return 0;
}