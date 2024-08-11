#include <iostream>
#include <vector>

// Function declaration
int findR1(float K, const std::vector<float>& list);

void testFindR1() {
    std::vector<float> list = {1.0, 2.0, 3.0, 4.0, 5.0};

    // Test finding an element at the beginning
    if (findR1(1.0, list) == 1) {
        std::cout << "Test 1 Passed." << std::endl;
    } else {
        std::cout << "Test 1 Failed." << std::endl;
    }

    // Test finding an element in the middle
    if (findR1(3.0, list) == 3) {
        std::cout << "Test 2 Passed." << std::endl;
    } else {
        std::cout << "Test 2 Failed." << std::endl;
    }

    // Test finding an element at the end
    if (findR1(5.0, list) == 5) {
        std::cout << "Test 3 Passed." << std::endl;
    } else {
        std::cout << "Test 3 Failed." << std::endl;
    }

    // Test not finding an element
    if (findR1(6.0, list) == -1) {
        std::cout << "Test 4 Passed." << std::endl;
    } else {
        std::cout << "Test 4 Failed." << std::endl;
    }
}

// Function definition
int findR1(float K, const std::vector<float>& list) {
    int lo = 0; // C++ uses 0-based indexing
    int hi = list.size() - 1;
    int m;

    while (lo <= hi) {
        m = (lo + hi) / 2;
        if (K > list[m]) {
            lo = m + 1;
        } else if (K < list[m]) {
            hi = m - 1;
        } else {
            return m + 1; // Adjusting to 1-based indexing to match Fortran output
        }
    }

    return -1; // If not found
}

int main() {
    testFindR1();
    return 0;
}