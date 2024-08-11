#include <iostream>
#include <vector>
#include <cassert> // For assert()

// Function to calculate the median of an array
double getMedian(std::vector<double>& input) {
    int n = input.size();
    double temp;
    
    // Manual sorting (Bubble Sort)
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(input[j] > input[i]) {
                // Swap elements
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
    
    // Calculate median
    if(n % 2 == 0) {
        // If even, return the average of the two middle numbers
        return (input[n / 2] + input[(n / 2) - 1]) / 2.0;
    } else {
        // If odd, return the middle element
        return input[n / 2];
    }
}

// Main function with test cases
int main() {
    // Test case 1: Odd length array
    std::vector<double> oddArray = {3.0, 1.0, 2.0, 5.0, 4.0};
    double expectedMedianOdd = 3.0; // After sorting: 1, 2, 3, 4, 5
    assert(getMedian(oddArray) == expectedMedianOdd);
    std::cout << "Test case 1 passed: Median of odd length array is correct." << std::endl;

    // Test case 2: Even length array
    std::vector<double> evenArray = {6.0, 1.0, 5.0, 2.0, 4.0, 3.0};
    double expectedMedianEven = 3.5; // After sorting: 1, 2, 3, 4, 5, 6
    assert(getMedian(evenArray) == expectedMedianEven);
    std::cout << "Test case 2 passed: Median of even length array is correct." << std::endl;

    // Feel free to add more test cases here to test other scenarios

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}