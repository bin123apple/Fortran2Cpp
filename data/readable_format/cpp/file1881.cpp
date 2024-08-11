#include <iostream>

void v7swp(int n, float* x, float* y) {
    float t;
    for (int i = 0; i < n; i++) {
        t = x[i];
        x[i] = y[i];
        y[i] = t;
    }
}

int main() {
    // Example usage
    int n = 5;
    float x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float y[] = {5.0, 4.0, 3.0, 2.0, 1.0};

    v7swp(n, x, y);

    std::cout << "Array X: ";
    for (int i = 0; i < n; i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;

    std::cout << "Array Y: ";
    for (int i = 0; i < n; i++)
        std::cout << y[i] << " ";
    std::cout << std::endl;

    return 0;
}