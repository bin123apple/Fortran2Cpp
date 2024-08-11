#include <cassert>
#include <cmath>
#include <iostream>

// SNRM2 function definition
float SNRM2(int N, float* SX, int INCX) {
    int I, J, NEXT, NN;
    float CUTLO, CUTHI, HITEST, SUM, XMAX, ZERO, ONE;
    ZERO = 0.0e0;
    ONE = 1.0e0;
    CUTLO = 4.441e-16;
    CUTHI = 1.304e19;

    if (N <= 0) {
        return ZERO;
    }

    NEXT = 15;
    SUM = ZERO;
    NN = N * INCX;
    I = 0; // Adjusted for 0-based indexing

    while (true) {
        switch (NEXT) {
            case 15:
                if (fabs(SX[I]) > CUTLO) {
                    NEXT = 55;
                    continue;
                }
                NEXT = 20;
                XMAX = ZERO;
                // Fall through
            case 20:
                if (SX[I] == ZERO) {
                    NEXT = 65;
                    continue;
                }
                if (fabs(SX[I]) > CUTLO) {
                    NEXT = 55;
                    continue;
                }
                NEXT = 35;
                // Fall through
            case 25:
                I = J;
                NEXT = 40;
                SUM = (SUM / SX[I]) / SX[I];
                // Fall through
            case 30:
                XMAX = fabs(SX[I]);
                // Fall through
            case 35:
                if (fabs(SX[I]) > CUTLO) {
                    NEXT = 50;
                    continue;
                }
                // Fall through
            case 40:
                if (fabs(SX[I]) <= XMAX) {
                    NEXT = 45;
                    continue;
                }
                SUM = ONE + SUM * (XMAX / SX[I]) * (XMAX / SX[I]);
                XMAX = fabs(SX[I]);
                NEXT = 65;
                continue;
            case 45:
                SUM = SUM + (SX[I] / XMAX) * (SX[I] / XMAX);
                NEXT = 65;
                continue;
            case 50:
                SUM = (SUM * XMAX) * XMAX;
                // Fall through
            case 55:
                HITEST = CUTHI / static_cast<float>(N);
                for (J = I; J < NN; J += INCX) {
                    if (fabs(SX[J]) >= HITEST) {
                        NEXT = 25;
                        break;
                    }
                    SUM = SUM + SX[J] * SX[J];
                }
                if (J < NN) continue;
                return sqrt(SUM);
            case 65:
                I = I + INCX;
                if (I < NN) {
                    NEXT = 10;
                    continue;
                }
                return XMAX * sqrt(SUM);
            default:
                break;
        }
        break;
    }
    return 0; // Should never reach here
}

// Main function to test SNRM2
int main() {
    float testVector[5];
    for (int i = 0; i < 5; ++i) {
        testVector[i] = (i + 1) * 1.0f;
    }
    
    // Call SNRM2 function with N=5, SX=testVector, INCX=1
    float result = SNRM2(5, testVector, 1);
    
    // Check the result with some tolerance for floating-point arithmetic
    assert(std::fabs(result - 7.41619849) < 0.0001);
    std::cout << "Test Passed. Result: " << result << std::endl;
    
    return 0;
}