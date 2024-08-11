#include <cmath>
#include <iostream>
#include <stdexcept>

float plgndr_s(int l, int m, float x) {
    float pmm = 1.0f;
    if (m > 0) {
        float somx2 = std::sqrt((1.0f - x) * (1.0f + x));
        pmm = 1.0f;
        for (int i = 1; i <= m; ++i) {
            pmm *= 2.0f * i * somx2;
        }
        if (m % 2 == 1) pmm = -pmm;
    }
    if (l == m) {
        return pmm;
    } else {
        float pmmp1 = x * (2.0f * m + 1.0f) * pmm;
        float pll = 0.0f;
        if (l == m + 1) {
            return pmmp1;
        } else {
            for (int ll = m + 2; ll <= l; ++ll) {
                pll = (x * (2.0f * ll - 1.0f) * pmmp1 - (ll + m - 1) * pmm) / (float)(ll - m);
                pmm = pmmp1;
                pmmp1 = pll;
            }
            return pll;
        }
    }
}

void assert_approx_equal(float actual, float expected, float tolerance, const std::string& message) {
    if (std::fabs(actual - expected) > tolerance) {
        throw std::runtime_error("Assertion failed: " + message + ". Expected: " + std::to_string(expected) + ", Got: " + std::to_string(actual));
    }
    std::cout << message << ": PASS." << std::endl;
}

void run_tests() {
    std::cout << "Running C++ Tests" << std::endl;
    float tolerance = 1e-6f;

    assert_approx_equal(plgndr_s(2, 1, 0.5f), -2.598076211f, tolerance, "Test 1");
    assert_approx_equal(plgndr_s(1, 0, 0.0f), 0.0f, tolerance, "Test 2");

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    try {
        run_tests();
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}