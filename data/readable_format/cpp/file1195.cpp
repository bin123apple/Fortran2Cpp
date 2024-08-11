#include <iostream>
using namespace std;

float asum(float* a, int n, float a0) {
    float asum = a0;
    for(int i = 0; i < n; i++) {
        asum += a[i];
    }
    return asum;
}

int main() {
    float a[8];
    for(int i = 0; i < 8; i++) {
        a[i] = i + 1; // Arrays in C++ are 0-indexed, so to mimic the original behavior we add 1
    }

    float b = asum(a, 8, 0.0f);
    if(b == 36.0f) {
        cout << "PASS" << endl;
    } else {
        cout << "ERROR" << endl;
    }

    return 0;
}