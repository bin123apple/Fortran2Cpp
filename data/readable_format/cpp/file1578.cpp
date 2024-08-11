#include <iostream>
#include <cmath>
#include <cassert>

class PARAMETERS {
public:
    // Constants (equivalent to Fortran parameters)
    static constexpr float d2r = std::asin(1.0f) / 90.0f;
    static constexpr float mu = 40e09f;
    static constexpr float moment = 5.593e22f;

    // Variables
    float al1, al2, aw1, aw2;

    // More constants
    static constexpr float alpha = 2.0f / 3.0f;
    static constexpr float depth = 10.0f;
    static constexpr float dip = 9.0f;
    static constexpr float length = 250.0f;
    static constexpr float rake = 78.0f * d2r;
    static constexpr float strike = (180.0f - 193.0f) * d2r;

    // Constructor
    PARAMETERS() {
        start_parameters();
    }

    // Member function (equivalent to Fortran subroutine)
    void start_parameters() {
        al2 = length / 2.0f;
        al1 = -al2;
        aw1 = -150.0f;
        aw2 = 0.0f;
    }
};

int main() {
    PARAMETERS params;

    // Test the constants
    assert(std::abs(PARAMETERS::d2r - (std::asin(1.0f) / 90.0f)) < 1e-6);
    assert(std::abs(PARAMETERS::mu - 40e09f) < 1e-6);
    assert(std::abs(PARAMETERS::moment - 5.593e22f) < 1e-6);

    // Test the results of start_parameters
    assert(std::abs(params.al1 + PARAMETERS::length / 2.0f) < 1e-6);
    assert(std::abs(params.al2 - PARAMETERS::length / 2.0f) < 1e-6);
    assert(std::abs(params.aw1 + 150.0f) < 1e-6);
    assert(std::abs(params.aw2) < 1e-6);

    std::cout << "C++ tests completed successfully." << std::endl;

    return 0;
}