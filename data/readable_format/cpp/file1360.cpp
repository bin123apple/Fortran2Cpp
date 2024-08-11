#include <iostream>
#include <cmath>

int main() {
    const int me = 1; // Simulated rank for testing
    const float eps = 0.00001f;
    int nerr = 0;
    float a2[2][3] = { {7.77f, 7.77f, 7.77f}, {7.77f, 7.77f, 7.77f} };
    
    // Simulated conditional modifications
    if (me == 1) {
        a2[0][1] = 1.22f;
    } else if (me == 2) {
        a2[1][2] = 2.33f;
    }
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            float val = 7.77f;
            if (i == 0 && j == 1 && me == 1) val = 1.22f;
            else if (i == 1 && j == 2 && me == 2) val = 2.33f;
            
            if (std::abs(a2[i][j] - val) > eps) {
                std::cout << "Test Failed: a2(" << i+1 << "," << j+1 << ")=" << a2[i][j]
                          << " should be " << val << std::endl;
                nerr++;
            }
        }
    }
    
    if (nerr == 0) {
        std::cout << "C++ Test Passed" << std::endl;
    } else {
        std::cout << "C++ Test Failed, errors: " << nerr << std::endl;
    }
    
    return 0;
}