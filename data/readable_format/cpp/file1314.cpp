#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

class T {
public:
    double expectedScalar;

    T() : expectedScalar(0.0) {}

    // Function to check a single value
    template<typename X>
    void FCheck(X x) {
        if constexpr (std::is_same<X, double>::value) {
            if (std::abs(x - expectedScalar) > 0.0001) {
                std::cerr << "Value does not match the expected scalar within tolerance." << std::endl;
                std::exit(1);
            }
        } else {
            std::cerr << "Unsupported type." << std::endl;
            std::exit(2);
        }
    }

    // Function to check an array
    template<typename X>
    void FCheckArr(const std::vector<X>& x) {
        for (int i = 0; i < x.size(); ++i) {
            expectedScalar = i;
            FCheck(x[i]);
        }
    }

    // Generic check function utilizing function overloading
    template<typename X>
    void Check(X x) {
        FCheck(x);
    }

    template<typename X>
    void Check(const std::vector<X>& x) {
        FCheckArr(x);
    }
};

// Test functions
void testFCheck() {
    T tester;
    tester.expectedScalar = 2.0;
    try {
        tester.FCheck(2.0);  // This should pass
        std::cout << "FCheck with single value passed." << std::endl;
    } catch (...) {
        std::cerr << "FCheck with single value failed." << std::endl;
    }
}

void testFCheckArr() {
    T tester;
    std::vector<double> vec = {0, 1, 2, 3, 4, 5};
    try {
        tester.FCheckArr(vec);  // This should fail and exit
    } catch (...) {
        std::cerr << "FCheckArr failed as expected." << std::endl;
    }
}

int main() {
    testFCheck();
    testFCheckArr();  // Note: If testFCheckArr does cause an exit, this line won't be reached.
    return 0;
}