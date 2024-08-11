#include <iostream>
#include <cmath>

const int N = 1000;

int main() {
    int a[N];
    float b[N];
    double c[N];
    long long sa = 1; // Adjusted for potential overflow
    float sb = 1.0f;
    double sc = 1.0;
    
    for (int i = 0; i < N; ++i) {
        if ((i + 1) % 100 == 0) {
            a[i] = 2;
            b[i] = 2.0f;
            c[i] = 4.0;
        } else if ((i + 1) % 100 == 50) {
            a[i] = 1;
            b[i] = 0.5f;
            c[i] = 0.25;
        } else {
            a[i] = 1;
            b[i] = 1.0f;
            c[i] = 1.0;
        }
    }

    for (int i = 0; i < N; ++i) {
        sa *= a[i];
        sb *= b[i];
        sc *= c[i];
    }

    int result = 0;
    if (sa != 1024 || std::abs(sb - 1.0f) > 0.0000001 || std::abs(sc - 1.0) > 0.0001) {
        result = -1;
    }

    if (result == 0) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}