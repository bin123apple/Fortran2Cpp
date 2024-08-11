// main_with_tests.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Particles {
    std::vector<float> x;

    Particles(float value = 0.0f) : x(2, value) {}
};

bool checkParticles(const Particles& p, const std::vector<float>& expectedValues) {
    return std::equal(p.x.begin(), p.x.end(), expectedValues.begin());
}

void testCondition(const Particles& p, const std::vector<float>& expectedValues, const std::string& testName) {
    if (checkParticles(p, expectedValues)) {
        std::cout << testName << ": Passed" << std::endl;
    } else {
        std::cout << testName << ": Failed" << std::endl;
    }
}

int main() {
    // Test 1: Particles initialized with 1.0 should pass
    Particles p1(1.0);
    testCondition(p1, {1.0, 1.0}, "Test 1 - Initialization with 1.0");

    // Test 2: Particles not matching the condition should fail
    Particles p2(0.0);
    p2.x[1] = 1.0; // Intentionally make it not match
    testCondition(p2, {1.0, 1.0}, "Test 2 - Mismatch condition");

    return 0;
}