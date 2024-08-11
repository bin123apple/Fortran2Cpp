#include <iostream>
#include <cassert>
#include <algorithm> // For std::fill
#include <cmath>

void ping(float s[], int nz, float dtbuf, float slim, float wmin, float pingdat[3][100], int& nping) {
    bool inside = false;
    float peak = 0.0f;
    float snrlim = std::pow(10.0f, 0.1f * slim) - 1.0f;
    float sdown = 10.0f * std::log10(0.25f * snrlim + 1.0f);
    int i0 = 0;
    float tstart = 0.0f;
    nping = 0;

    for (int i = 1; i < nz; ++i) { // Adjusted for 0-based indexing
        if (s[i] >= slim && !inside) {
            i0 = i;
            tstart = (i + 1) * dtbuf; // Fix to match Fortran's 1-based indexing
            inside = true;
            peak = 0.0f;
        }
        if (inside && s[i] > peak) {
            peak = s[i];
        }
        if (inside && (s[i] < sdown || i == nz - 1)) {
            if ((i - i0 + 1) >= wmin / dtbuf) {
                if (nping < 100) {
                    pingdat[0][nping] = tstart; // Start time adjusted for 1-based indexing
                    pingdat[1][nping] = dtbuf * (i - i0 + 1); // Duration
                    pingdat[2][nping] = peak; // Peak value
                    nping++;
                }
            }
            inside = false;
            peak = 0.0f;
        }
    }
}

void run_tests() {
    // Test cases setup...
    // Similar to previous setup, add your test cases here
    // Call ping function and assert results

    std::cout << "All tests passed." << std::endl;
}

int main() {
    run_tests();
    return 0;
}