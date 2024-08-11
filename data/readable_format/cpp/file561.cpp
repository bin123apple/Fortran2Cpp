#include <iostream>

void test(int n, float* a, const float* b, const float* c) {
    for (int i = 0; i < n; ++i) {
        a[i] = b[i] + c[i];
    }
}

int main() {
    // Example usage
    const int size = 5;
    float a[size], b[size] = {1.0, 2.0, 3.0, 4.0, 5.0}, c[size] = {5.0, 4.0, 3.0, 2.0, 1.0};

    test(size, a, b, c);

    // Print the result to check
    std::cout << "Result of a[i] = b[i] + c[i]:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    return 0;
}