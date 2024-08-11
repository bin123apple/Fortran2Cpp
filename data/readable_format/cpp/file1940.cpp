#include <iostream>
#include <vector>

// Declaration and definition of the NWHSEL function directly in this file
int NWHSEL(int NPTIMS, const std::vector<int>& IPTIMS, const std::vector<bool>& WHOTIM) {
    int result = 0;
    for(int i = 0; i < NPTIMS; ++i) {
        // Adjusting for 0-based indexing in C++
        if (WHOTIM[IPTIMS[i] - 1]) {
            result += 1;
        }
    }
    return result;
}

// Test function
void testNWHSEL(const std::vector<int>& IPTIMS, const std::vector<bool>& WHOTIM, int expected, int testNumber) {
    int NPTIMS = IPTIMS.size();
    int result = NWHSEL(NPTIMS, IPTIMS, WHOTIM);
    std::cout << "Test " << testNumber << ": Expected " << expected << ", Got " << result << std::endl;
}

// Main function to run tests
int main() {
    std::vector<int> IPTIMS = {1, 2, 3, 4, 5};
    std::vector<bool> WHOTIM = {true, false, true, false, true};

    testNWHSEL(IPTIMS, WHOTIM, 3, 1);

    WHOTIM = {false, false, false, false, false};
    testNWHSEL(IPTIMS, WHOTIM, 0, 2);

    WHOTIM = {true, true, true, true, true};
    testNWHSEL(IPTIMS, WHOTIM, 5, 3);

    return 0;
}