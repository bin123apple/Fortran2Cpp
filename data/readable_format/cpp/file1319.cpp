#include <iostream>
#include <cstdint>

std::int64_t specific__dim_i8(std::int64_t p1, std::int64_t p2) {
    return (p1 > p2) ? (p1 - p2) : 0;
}

void test_specific__dim_i8(std::int64_t p1, std::int64_t p2, std::int64_t expected, const std::string& test_name) {
    std::int64_t result = specific__dim_i8(p1, p2);
    if (result == expected) {
        std::cout << test_name << ": PASS" << std::endl;
    } else {
        std::cout << test_name << ": FAIL - Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    std::cout << "Starting tests..." << std::endl;

    // Add test cases here
    test_specific__dim_i8(10, 5, 5, "Test 1: p1 > p2");
    test_specific__dim_i8(2, 3, 0, "Test 2: p1 < p2");
    test_specific__dim_i8(7, 7, 0, "Test 3: p1 == p2");

    std::cout << "Tests completed." << std::endl;

    return 0;
}