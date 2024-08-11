#include <cassert>
#include <cmath>
#include <iostream>

// Define the conref_C class directly in this file
class conref_C {
public:
    static constexpr double fpcref[2][10] = {
        {1.602176462e0, 14.399643e0, 0.5291772083e0, 27.2113834e0, 1.9872065e0, 
        6.6260755e-27, 1.3806503e-16, 2.99792458e10, 23.060529e0, 6.0221367e23},
        {1.60217733e0, 14.399e0, 0.529167e0, 27.21e0, 1.98726e0, 
        6.626e-27, 1.3807e-16, 2.99776e10, 23.061e0, 6.02205e23}
    };
};

// Main function containing unit tests
int main() {
    // Example test for the first and last value
    assert(std::abs(conref_C::fpcref[0][0] - 1.602176462e0) < 1e-9);
    assert(std::abs(conref_C::fpcref[1][9] - 6.02205e23) < 1e-9);

    // You can add more tests here as needed

    std::cout << "All tests passed." << std::endl;

    return 0;
}