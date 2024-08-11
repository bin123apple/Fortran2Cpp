#include <iostream>
#include <cmath>
#include <vector>
#include <utility> // For std::pair

int main() {
    std::vector<std::pair<int, double>> tests = {
        {-4, 1.2345678901234567e-04},
        {0, 1.2345678901234567e+00},
        {4, 1.2345678901234567e+04}
    };

    bool all_tests_passed = true;
    for (auto& test : tests) {
        int ie = test.first;
        double expected = test.second;
        double val = 1.2345678901234567 * std::pow(10.0, ie);
        if (std::abs(val - expected) > 1.0e-15) {
            std::cerr << "Test failed at ie = " << ie << std::endl;
            all_tests_passed = false;
            break;
        }
    }

    if (all_tests_passed) {
        std::cout << "All tests passed." << std::endl;
    }

    return 0;
}