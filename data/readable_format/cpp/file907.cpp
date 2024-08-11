#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class TObjectList {
    std::vector<int> intList;
    std::vector<double> doubleList;
public:
    void Add(int item) {
        intList.push_back(item);
    }

    void Add(double item) {
        doubleList.push_back(item);
    }

    // Functions for testing
    int getIntElement(size_t index) {
        if (index >= intList.size()) throw std::out_of_range("Index out of range");
        return intList[index];
    }

    double getDoubleElement(size_t index) {
        if (index >= doubleList.size()) throw std::out_of_range("Index out of range");
        return doubleList[index];
    }
};

// Simple test utility functions
void EXPECT_EQ(int expected, int actual, const std::string& test_message) {
    if (expected != actual) {
        std::cerr << "FAIL: " << test_message << " - Expected: " << expected << ", Actual: " << actual << std::endl;
    } else {
        std::cout << "PASS: " << test_message << std::endl;
    }
}

void EXPECT_DOUBLE_EQ(double expected, double actual, const std::string& test_message) {
    if (std::fabs(expected - actual) > 1e-6) {
        std::cerr << "FAIL: " << test_message << " - Expected: " << expected << ", Actual: " << actual << std::endl;
    } else {
        std::cout << "PASS: " << test_message << std::endl;
    }
}

int main() {
    TObjectList list;

    // Test adding integers
    list.Add(1);
    EXPECT_EQ(1, list.getIntElement(0), "Add integer 1");

    // Test adding doubles
    list.Add(2.0);
    EXPECT_DOUBLE_EQ(2.0, list.getDoubleElement(0), "Add double 2.0");

    return 0;
}