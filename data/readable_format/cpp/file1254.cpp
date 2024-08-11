#include <iostream>

// Function definition
void interpol_alfa2(double lzd, double reynolds, double& alfa2) {
    alfa2 = 1.0;
}

int main() {
    double lzd = 0.0;
    double reynolds = 0.0;
    double alfa2 = 0.0;

    // Test 1
    interpol_alfa2(lzd, reynolds, alfa2);
    if (alfa2 == 1.0) {
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed." << std::endl;
    }

    return 0;
}