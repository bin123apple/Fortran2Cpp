#include <iostream>
#include <algorithm>
#include <cmath>

// Function declaration
float sla_gbrpvgrw(int n, int kl, int ku, int ncols, float** ab, int ldab, float** afb, int ldafb) {
    int i, j, kd;
    float amax, umax, rpvgrw = 1.0f;

    kd = ku;
    for (j = 0; j < ncols; ++j) {
        amax = 0.0f;
        umax = 0.0f;
        for (i = std::max(j-ku, 0); i < std::min(j+kl+1, n); ++i) {
            amax = std::max(std::abs(ab[kd+i-j][j]), amax);
        }
        for (i = std::max(j-ku, 0); i <= j; ++i) {
            umax = std::max(std::abs(afb[kd+i-j][j]), umax);
        }
        if (umax != 0.0f) {
            rpvgrw = std::min(amax / umax, rpvgrw);
        }
    }
    return rpvgrw;
}

// Main program to test the sla_gbrpvgrw function
int main() {
    int n = 4;
    int kl = 1;
    int ku = 1;
    int ldab = kl + ku + 1;
    int ldafb = kl + ku + 1;
    int ncols = n;

    // Dynamically allocate 2D arrays ab and afb
    float** ab = new float*[ldab];
    for(int i = 0; i < ldab; ++i) {
        ab[i] = new float[ncols]();
    }

    float** afb = new float*[ldafb];
    for(int i = 0; i < ldafb; ++i) {
        afb[i] = new float[ncols]();
    }

    // Populate ab and afb with some values for testing
    ab[ku][0] = 4;
    ab[ku-1][1] = -1; ab[ku][1] = 4; ab[ku+1][1] = -1;
    ab[ku][2] = 4; ab[ku+1][2] = -1;
    ab[ku][3] = 4;

    for(int i = 0; i < ldafb; ++i) {
        for(int j = 0; j < ncols; ++j) {
            afb[i][j] = ab[i][j];  // For simplicity, using the same values
        }
    }

    float result = sla_gbrpvgrw(n, kl, ku, ncols, ab, ldab, afb, ldafb);

    std::cout << "Reciprocal Pivot Growth Factor: " << result << std::endl;

    // Clean up dynamic arrays
    for(int i = 0; i < ldab; ++i) {
        delete[] ab[i];
    }
    delete[] ab;

    for(int i = 0; i < ldafb; ++i) {
        delete[] afb[i];
    }
    delete[] afb;

    return 0;
}