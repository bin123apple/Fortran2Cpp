#include <iostream>
#include <cmath>

// Assuming COOP_REAL is a type alias for double or similar
using COOP_REAL = double;

class coop_HST_object {
public:
    COOP_REAL H0 = 74.03;
    COOP_REAL H0_err = 1.42;

    // Constructor
    coop_HST_object() = default;

    // LogLike function as a member method
    COOP_REAL LogLike(COOP_REAL h_value) const {
        return std::pow((h_value * 100.0 - H0) / H0_err, 2) / 2.0;
    }
};

// Function to test the LogLike function
void test_LogLike() {
    coop_HST_object hst;
    
    // Example h_value
    COOP_REAL h_value = 0.74;

    // Expected log likelihood value for given test
    COOP_REAL expected_loglike = std::pow((h_value * 100.0 - hst.H0) / hst.H0_err, 2) / 2.0;

    // Compute the log likelihood
    COOP_REAL computed_loglike = hst.LogLike(h_value);

    // Check if the computed value matches the expected value
    if (std::abs(computed_loglike - expected_loglike) < 1.0e-6) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected: " << expected_loglike << " Got: " << computed_loglike << std::endl;
    }
}

int main() {
    test_LogLike();
    return 0;
}