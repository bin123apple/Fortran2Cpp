#include <iostream>
#include <cmath>
#include <string>

class SimpleMath {
public:
    // Hypotenuse calculation using Pythagorean theorem
    static double hypot(double x, double y) {
        return std::sqrt(x * x + y * y);
    }

    static double hypot3(double x, double y, double z) {
        return std::sqrt(x * x + y * y + z * z);
    }
};

class UnitTest {
public:
    void assert_equal_within(const std::string& testName, double expected, double actual, double tolerance) {
        if (std::fabs(expected - actual) > tolerance) {
            std::cerr << testName << " failed: Expected " << expected << ", got " << actual << std::endl;
        } else {
            std::cout << testName << " passed." << std::endl;
        }
    }
};

int main() {
    UnitTest tester;

    // Perform some tests
    double r = SimpleMath::hypot(3.0, 4.0);
    tester.assert_equal_within("hypot", 5.0, r, 1e-12);

    r = SimpleMath::hypot3(3.0, 4.0, 0.0);
    tester.assert_equal_within("hypot3", 5.0, r, 1e-12);

    return 0;
}