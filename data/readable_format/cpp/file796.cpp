#include <iostream>
#include <cmath> // Include cmath for std::abs
#include <iomanip> // For std::setprecision

// Definition of the CROSS function directly in the file
void CROSS(float &X, float &XX, float &Y, float &YY, float &YYY, float &XXX) {
    YYY = Y - YY + XX - X;
    XXX = Y * (XX - X) + X * (Y - YY);

    if (std::abs(YYY) >= 1.E-6) {
        YYY = XXX / YYY;
        XXX = XX - X;
        if (std::abs(XXX) >= 1.E-6) {
            XXX = (YYY - X) / XXX;
        } else {
            XXX = Y - YY;
            if (std::abs(XXX) >= 1.E-6) {
                XXX = (Y - YYY) / XXX;
            }
        }
    }
}

// Main function to test the CROSS function
int main() {
    float X, XX, Y, YY, YYY, XXX;

    // Test case 1
    X = 1.0f;
    XX = 2.0f;
    Y = 3.0f;
    YY = 4.0f;
    CROSS(X, XX, Y, YY, YYY, XXX);
    std::cout << "Test case 1: YYY = " << std::setprecision(6) << YYY << ", XXX = " << XXX << std::endl;

    // Additional test cases can be added following the same pattern

    return 0;
}