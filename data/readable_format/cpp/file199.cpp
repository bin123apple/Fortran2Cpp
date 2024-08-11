#include <iostream>
#include <vector>
#include <cassert> // For basic assertions

struct t {
    std::vector<std::vector<int>>* n;
    t() : n(nullptr) {}
};

// Test function to verify equivalence
void testPointerAssociation() {
    t left;
    std::vector<std::vector<int>> right(4, std::vector<int>(4, 4));
    left.n = &right;

    // Simple test to verify the pointer association
    bool test_passed = true;
    for (size_t i = 0; i < right.size(); ++i) {
        for (size_t j = 0; j < right[i].size(); ++j) {
            if ((*left.n)[i][j] != right[i][j]) {
                test_passed = false;
                break;
            }
        }
        if (!test_passed) break;
    }

    assert(test_passed); // Using assert for a simple pass/fail indication
    if(test_passed) {
        std::cout << "Test passed: left.n points to right and has correct values." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    testPointerAssociation();
    return 0;
}