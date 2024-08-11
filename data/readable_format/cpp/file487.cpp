#include <iostream>
#include <vector>

// Definition of the dscal function
void dscal(int n, double da, double* dx, int incx) {
    if (n <= 0) return;

    if (incx == 1) {
        // Efficient loop unrolling for stride 1
        int m = n % 5;
        for (int i = 0; i < m; ++i) {
            dx[i] = da * dx[i];
        }
        if (n < 5) return;

        for (int i = m; i < n; i += 5) {
            dx[i] = da * dx[i];
            dx[i + 1] = da * dx[i + 1];
            dx[i + 2] = da * dx[i + 2];
            dx[i + 3] = da * dx[i + 3];
            dx[i + 4] = da * dx[i + 4];
        }
    } else {
        // Handling of non-unit stride
        int ix = 0;
        if (incx < 0) ix = (-n + 1) * incx;
        for (int i = 0; i < n; ++i) {
            dx[ix] = da * dx[ix];
            ix += incx;
        }
    }
}

// Main function with unit tests
int main() {
    // Utility lambda for printing vectors
    auto printVector = [](const std::vector<double>& vec) {
        for (double v : vec) std::cout << v << " ";
        std::cout << std::endl;
    };
    
    // Test 1: Stride of 1, size not a multiple of 5
    {
        std::vector<double> vec = {1, 2, 3, 4, 5, 6, 7};
        dscal(vec.size(), 2.0, vec.data(), 1);
        std::cout << "Test 1: ";
        printVector(vec);
    }
    
    // Test 2: Stride of 1, size a multiple of 5
    {
        std::vector<double> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        dscal(vec.size(), 2.0, vec.data(), 1);
        std::cout << "Test 2: ";
        printVector(vec);
    }
    
    // Test 3: A negative stride
    {
        std::vector<double> vec = {5, 4, 3, 2, 1}; // Reversed vector for a negative stride visualization
        dscal(vec.size(), 2.0, vec.data(), -1);
        std::cout << "Test 3: ";
        printVector(vec);
    }
    
    // Test 4: A non-unit positive stride
    {
        std::vector<double> vec = {1, 2, 3, 4, 5, 6};
        dscal(vec.size(), 2.0, vec.data(), 2);
        std::cout << "Test 4: ";
        printVector(vec);
    }
    
    // Test 5: An empty array (n = 0)
    {
        std::vector<double> vec = {};
        dscal(vec.size(), 2.0, vec.data(), 1);
        std::cout << "Test 5: No output expected" << std::endl;
    }
    
    return 0;
}