#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

// Forward declaration of rffti function
void rffti(int n, double* wsave);

// Test function for rffti
void test_rffti() {
    const int n = 8;
    std::vector<double> wsave(n);
    const double tol = 1.0e-7;

    rffti(n, wsave.data());

    // Check a few key values with expected results
    assert(std::abs(wsave[0] - cos(2.0 * M_PI / n)) <= tol && "Test failed for wsave[0]");
    assert(std::abs(wsave[n/2-2] - sin(2.0 * M_PI / n)) <= tol && "Test failed for wsave[n/2-2]");

    std::cout << "All tests passed" << std::endl;
}

// Implementation of rffti function
void rffti(int n, double* wsave) {
    int ns2 = n / 2;
    int nqm = (ns2 - 1) / 2;
    double tpi = 8.0 * atan(1.0); // Alternatively, you can use 2.0 * M_PI which is more straightforward and equivalent.
    double dt = tpi / static_cast<double>(n);
    double dc = cos(dt);
    double ds = sin(dt);
    wsave[0] = dc;
    wsave[ns2 - 2] = ds; // Adjust for zero-based indexing
    if (nqm < 2) return;

    for (int k = 2; k <= nqm; ++k) {
        int kc = ns2 - k;
        wsave[k - 1] = dc * wsave[k - 2] - ds * wsave[kc];
        wsave[kc - 1] = ds * wsave[k - 2] + dc * wsave[kc];
    }
}

int main() {
    test_rffti();
    return 0;
}