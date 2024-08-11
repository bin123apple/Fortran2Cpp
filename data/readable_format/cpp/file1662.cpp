#include <iostream>
#include <cmath>

// SNRM2 function definition
float SNRM2(int N, float *X, int INCX) {
    float ONE = 1.0f;
    float ZERO = 0.0f;
    float ABSXI, NORM, SCALE, SSQ;
    int IX;

    if (N < 1 || INCX < 1) {
        NORM = ZERO;
    } else if (N == 1) {
        NORM = std::abs(X[0]); // Adjusted for 0-based indexing
    } else {
        SCALE = ZERO;
        SSQ = ONE;

        for (IX = 0; IX < N; IX += INCX) { // Adjusted loop for 0-based indexing
            if (X[IX] != ZERO) {
                ABSXI = std::abs(X[IX]);
                if (SCALE < ABSXI) {
                    SSQ = ONE + SSQ * (SCALE / ABSXI) * (SCALE / ABSXI);
                    SCALE = ABSXI;
                } else {
                    SSQ += (ABSXI / SCALE) * (ABSXI / SCALE);
                }
            }
        }
        NORM = SCALE * std::sqrt(SSQ);
    }

    return NORM;
}

// Main function to test SNRM2
int main() {
    int N = 3;
    float X[] = {3.0f, 4.0f, 0.0f};
    int INCX = 1;

    float result = SNRM2(N, X, INCX);
    std::cout << "The 2-norm of the vector is: " << result << std::endl;

    return 0;
}