#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cassert>

std::string formatNumbers(float num1, float num2) {
    std::ostringstream oss;
    oss << std::right << std::fixed << std::setprecision(3)
        << std::setw(10) << num1
        << std::setw(10) << num2;
    return oss.str();
}

void runTests() {
    assert(formatNumbers(0.0625f, 0.1875f) == "     0.062     0.188");
    std::cout << "Test 1 passed." << std::endl;

    // Additional tests would follow the same pattern...
}

int main() {
    runTests();
    return 0;
}