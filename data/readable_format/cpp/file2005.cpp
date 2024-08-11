#include <iostream>

void foo10(float a[10][10], float b[10][10]) {
    for (int k = 1; k <= 4; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (a[i][j] < k) {
                    a[i][j] = a[i][j] + b[i][j];
                    b[i][j] = a[i][j] - b[i][j];
                } else {
                    a[i][j] = a[i][j] * 2;
                }
            }
        }
    }
}

int main() {
    float a[10][10] = {0}, b[10][10];

    // Initialize b
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            b[i][j] = 1.0;
        }
    }

    foo10(a, b);

    // Output for inspection or perform checks
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << "a[" << i << "][" << j << "] = " << a[i][j]
                      << " b[" << i << "][" << j << "] = " << b[i][j] << std::endl;
        }
    }

    return 0;
}