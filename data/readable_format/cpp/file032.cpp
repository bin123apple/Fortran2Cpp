#include <iostream>
#include <vector>
#include <string>

// Function to be tested
std::vector<int> w3reddat() {
    const std::vector<int> itd = {1, 24, 1440, 86400, 86400000};
    std::vector<int> itm(4);

    for (size_t i = 0; i < itm.size(); ++i) {
        itm[i] = itd[4] / itd[i];
    }
    return itm;
}

// A simple test for the function
void test_w3reddat() {
    std::vector<int> expected = {86400000, 3600000, 60000, 1000};
    std::vector<int> result = w3reddat();

    bool test_passed = true;
    for (size_t i = 0; i < expected.size(); ++i) {
        if (result[i] != expected[i]) {
            test_passed = false;
            break;
        }
    }

    if (test_passed) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

// Main function to run the test
int main() {
    test_w3reddat();
    return 0;
}