// File: nidentll.cpp
#include <iostream>
#include <cstdint>

void nidentll(int64_t* x, int64_t px, int n, int& id) {
    id = 0;
    if (n == 0) return;
    int n2 = n + 1;
    int m;
  
    while (true) {
        m = (n2 + id) / 2;
        if (px >= x[m-1]) {
            id = m;
        } else {
            n2 = m;
        }
        if ((n2 - id) == 1) return;
    }
}

void testNidentll(int64_t* x, int n, int64_t px, int expected, const std::string& testName) {
    int id;
    nidentll(x, px, n, id);
    std::cout << testName << ": Expected " << expected << ", Got " << id << std::endl;
}

int main() {
    int64_t x[] = {1, 3, 5, 7, 9};
    int n = sizeof(x) / sizeof(x[0]);

    testNidentll(x, n, 5, 3, "Test 1 (Element exists)");
    testNidentll(x, n, 6, 3, "Test 2 (Insert position)"); // Adjusted expectation
    testNidentll(nullptr, 0, 6, 0, "Test 3 (Empty array)");

    return 0;
}