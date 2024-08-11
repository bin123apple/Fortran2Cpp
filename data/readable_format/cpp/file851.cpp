#include <iostream>
#include <vector>
#include <algorithm>

// Assuming the translated functions are as follows:
class Test1 {
public:
    static void valid(int& lhs, const std::vector<int>& rhs) {
        lhs = rhs[0]; // Note: 0-based indexing in C++
    }

    static void valid2(std::vector<int>& lhs, const std::vector<std::vector<int>>& rhs) {
        for (size_t i = 0; i < lhs.size(); ++i) {
            lhs[i] = rhs[i][0]; // Accessing the first column of each row
        }
    }
};

class Test2 {
public:
    static void invalid(int& lhs, int rhs) {
        lhs = rhs;
    }
};

// ... other classes Test3 and Test4 with their methods ...

// Function prototypes for tests
void testValid();
void testValid2();
void testInvalid();
// ... prototypes for other test functions ...

int main() {
    // Run tests
    testValid();
    testValid2();
    testInvalid();
    // ... call other test functions ...

    return 0;
}

// Implement test functions
void testValid() {
    int lhs;
    std::vector<int> rhs = {1, 2, 3};
    Test1::valid(lhs, rhs);
    if (lhs == 1) {
        std::cout << "testValid passed." << std::endl;
    } else {
        std::cout << "testValid failed." << std::endl;
    }
}

void testValid2() {
    std::vector<int> lhs(3);
    std::vector<std::vector<int>> rhs = {{1, 2}, {3, 4}, {5, 6}};
    Test1::valid2(lhs, rhs);
    if (lhs == std::vector<int>{1, 3, 5}) {
        std::cout << "testValid2 passed." << std::endl;
    } else {
        std::cout << "testValid2 failed." << std::endl;
    }
}

void testInvalid() {
    int lhs;
    int rhs = 10;
    Test2::invalid(lhs, rhs);
    if (lhs == 10) {
        std::cout << "testInvalid passed." << std::endl;
    } else {
        std::cout << "testInvalid failed." << std::endl;
    }
}

// Implement other test functions similarly...