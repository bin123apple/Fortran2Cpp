#include <iostream>
#include <cstdlib> // For std::abort

int main() {
    const int n = 1024;
    int a[n], b[n], c[n];

    for (int i = 0; i < n; ++i) {
        a[i] = i * 2;
    }

    for (int i = 0; i < n; ++i) {
        b[i] = i * 4;
    }

    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }

    for (int i = 0; i < n; ++i) {
        if (c[i] != a[i] + b[i]) {
            std::abort();
        }
    }

    return 0;
}