#include <iostream>
#include <cmath>
#include <cassert>
#include <type_traits>

// Define the template class directly in this file
template<typename T>
class PpmBemQuadrule {
public:
    T quadrule() {
        // Hypothetical calculation for demonstration
        if constexpr (std::is_same<float, T>::value) {
            return 1.0f; // Placeholder value for single precision
        } else {
            return 1.0; // Placeholder value for double precision
        }
    }
};

// Basic test function, using assert for simplicity
void test() {
    PpmBemQuadrule<float> quadruleSinglePrecision;
    PpmBemQuadrule<double> quadruleDoublePrecision;

    auto resultSingle = quadruleSinglePrecision.quadrule();
    auto resultDouble = quadruleDoublePrecision.quadrule();

    assert(std::abs(resultSingle - 1.0f) < 1e-5);
    std::cout << "Single precision test passed." << std::endl;

    assert(std::abs(resultDouble - 1.0) < 1e-10);
    std::cout << "Double precision test passed." << std::endl;
}

// Main function to run the tests
int main() {
    test();
    return 0;
}