// bug468_corrected.cpp
#include <iostream>
#include <vector>
#include <cmath> // For std::abs

bool testLogic() {
    std::vector<float> hoge(10, 100.0f); // Initialize all elements to 100.0f
    float tmp = 100.0f;
    float eps = 0.00001f;
    int nerr = 0;

    std::vector<float> pon = hoge; // Copy hoge to pon

    for (size_t i = 0; i < pon.size(); ++i) {
        if (std::abs(pon[i] - tmp) > eps) { // Corrected comparison
            nerr++;
        }
    }

    // Expecting nerr to be 0 because pon[i] should equal tmp for all i
    return nerr == 0;
}

int main() {
    if (testLogic()) {
        std::cout << "C++ Test Passed." << std::endl;
    } else {
        std::cout << "C++ Test Failed." << std::endl;
    }

    return 0;
}