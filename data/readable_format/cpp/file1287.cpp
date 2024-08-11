#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

// Function to compute average
int avg(const std::vector<int>& a) {
    if (a.empty()) {
        return 0; // Return 0 for an empty vector
    }
    int sum = std::accumulate(a.begin(), a.end(), 0);
    return sum / a.size();
}

// Function to test the avg function
void test_avg(const std::vector<int>& test_vector, int expected) {
    int result = avg(test_vector);
    std::cout << "Test ";
    if (result == expected) {
        std::cout << "PASSED. ";
    } else {
        std::cout << "FAILED. ";
    }
    std::cout << "Expected: " << expected << ", got: " << result << std::endl;
}

// Main function
int main() {
    // Run some tests
    test_avg({1, 2, 3, 4, 5}, 3); // Should pass
    test_avg({10, 20, 30, 40, 50}, 30); // Should pass
    test_avg({-5, 0, 5}, 0); // Should pass
    test_avg({}, 0); // Should pass - empty vector test
    return 0;
}