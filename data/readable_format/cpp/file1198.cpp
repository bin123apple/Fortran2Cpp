#include <iostream>
#include <cmath> // For fabs

namespace SET_THETAPHI_RANGE__genmod {
    void SET_THETAPHI_RANGE(double& THETA, double& PHI, bool USE_POSITIVE_LON) {
        if (USE_POSITIVE_LON && PHI < 0) {
            PHI += 360;
        } else if (!USE_POSITIVE_LON && PHI > 0) {
            PHI -= 360;
        }
    }
} // namespace SET_THETAPHI_RANGE__genmod

namespace test_framework {
    int tests_passed = 0;
    int tests_failed = 0;

    void assert_close(double actual, double expected, double tolerance, const char* testName) {
        if (std::fabs(actual - expected) <= tolerance) {
            std::cout << testName << " Passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << testName << " Failed: Expected " << expected << ", but got " << actual << std::endl;
            tests_failed++;
        }
    }

    void report() {
        std::cout << "Tests passed: " << tests_passed << std::endl;
        std::cout << "Tests failed: " << tests_failed << std::endl;
    }
}

int main() {
    using namespace SET_THETAPHI_RANGE__genmod;
    using namespace test_framework;

    double THETA, PHI;

    // Test 1: Negative PHI with USE_POSITIVE_LON = true
    THETA = 0.0; PHI = -100.0;
    SET_THETAPHI_RANGE(THETA, PHI, true);
    assert_close(PHI, 260.0, 0.001, "Test 1");

    // Test 2: Positive PHI with USE_POSITIVE_LON = false
    THETA = 0.0; PHI = 100.0;
    SET_THETAPHI_RANGE(THETA, PHI, false);
    assert_close(PHI, -260.0, 0.001, "Test 2");

    report();

    return 0;
}