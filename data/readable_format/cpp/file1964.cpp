#include <iostream>
#include <vector>

// Function to calculate the sum of elements in an array
int calculateSum(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// Function to test the calculateSum function
void testCalculateSum() {
    // Test case 1
    {
        std::vector<int> testArray = {1, 2, 3, 4, 5}; // Expected sum is 15
        int expectedSum = 15;
        int actualSum = calculateSum(testArray);
        if (actualSum == expectedSum) {
            std::cout << "Test case 1 passed." << std::endl;
        } else {
            std::cout << "Test case 1 failed. Expected " << expectedSum << ", but got " << actualSum << "." << std::endl;
        }
    }

    // Add more test cases as needed
    // Test case 2, Test case 3, etc.
}

int main() {
    // Call the test function
    testCalculateSum();

    // Optionally, add any additional logic or manual testing
    return 0;
}