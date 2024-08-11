#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>

std::string multiplyAndCheck() {
    long long i = 1;
    for (int j = 1; j <= 63; ++j) {
        i *= 2;
    }

    std::stringstream ss;
    ss << std::hex << i;  // Convert to hexadecimal
    return ss.str();
}

int main() {
    std::string result = multiplyAndCheck();
    if (result != "8000000000000000") {
        std::cerr << "Test failed: Expected 8000000000000000 but got " << result << std::endl;
        return 1;  // Indicate failure
    }
    std::cout << "Test passed." << std::endl;
    return 0;  // Indicate success
}