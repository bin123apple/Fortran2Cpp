#include <iostream>
#include <cstdlib> // For std::abort()

const int size = 100;

// Function declarations
void kernels(int* array, int n);
void kernels_default_present(int* array, int n);
void parallel(int* array, int n);
void parallel_default_present(int* array, int n);

// Simple test function declaration
void test(const char* testName, int* array, int n, int (*testFunction)(int*, int));

int main() {
    int array[size];

    // Running tests
    test("kernels", array, size, [](int* arr, int n) -> int {
        kernels(arr, n);
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1) return 0; // Test failed
        }
        return 1; // Test passed
    });

    // Add more tests for other functions following the same pattern

    return 0;
}

// Function definitions
void kernels(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }
}

void kernels_default_present(int* array, int n) {
    // Function implementation
}

void parallel(int* array, int n) {
    // Function implementation
}

void parallel_default_present(int* array, int n) {
    // Function implementation
}

// Simple test function definition
void test(const char* testName, int* array, int n, int (*testFunction)(int*, int)) {
    std::cout << "Testing " << testName << "... ";
    if (testFunction(array, n)) {
        std::cout << "PASSED";
    } else {
        std::cout << "FAILED";
    }
    std::cout << std::endl; // Properly handle new line
}