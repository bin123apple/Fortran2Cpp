#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // For std::fixed and std::setprecision

// Definition of the ranstd function
void ranstd(std::vector<double>& x) {
    int n = x.size();
    if (n <= 1) return;
    
    double sum1 = 0.0;
    double sum2 = 0.0;
    
    // Calculate the sums of the elements and the squares of the elements
    for (int i = 0; i < n; ++i) {
        sum1 += x[i];
        sum2 += x[i] * x[i];
    }
    
    sum1 /= n;
    sum2 /= n;
    
    // Check if standard deviation can be standardized
    if (sum2 > 0) {
        sum2 = 1.0 / sqrt(sum2 - sum1 * sum1);
    } else {
        // Correctly concatenate the string across lines
        std::cerr << "ranstd: n,sum2=" << n << "," << sum2 << " cannot standardize variance";
        sum2 = 1.0;
    }
    
    sum1 = -sum1 * sum2;
    
    // Standardize the array
    for (int i = 0; i < n; ++i) {
        x[i] = sum1 + sum2 * x[i];
    }
}

// Function to print a vector
void printVector(const std::vector<double>& vec) {
    for (const auto& val : vec) {
        std::cout << std::fixed << std::setprecision(4) << val << " ";
    }
    std::cout << std::endl;
}

// Function for testing the ranstd function
void testRanstd(std::vector<double> vec) {
    std::cout << "Original Vector: ";
    printVector(vec);
    
    ranstd(vec);

    std::cout << "After ranstd: ";
    printVector(vec);
    std::cout << std::endl;
}

int main() {
    // Test Case 1
    std::cout << "Test Case 1" << std::endl;
    testRanstd({2.0, 4.0, 4.0, 4.0, 5.0});

    // Test Case 2
    std::cout << "Test Case 2" << std::endl;
    testRanstd({1.0, 2.0, 3.0});

    return 0;
}