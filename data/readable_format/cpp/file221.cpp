#include <iostream>
#include <numeric> // For std::accumulate

int main() {
    const int size = 10000; // Array size
    int a[size], b[size];

    // Initializing arrays a and b
    for (int i = 0; i < size; ++i) {
        a[i] = 1;
        b[i] = 2;
    }

    // Adding arrays element-wise
    for (int i = 0; i < size; ++i) {
        a[i] = a[i] + b[i];
    }

    // Calculating the sum of array a
    int d = std::accumulate(a, a + size, 0);

    // Printing the result
    std::cout << d << std::endl;

    return 0;
}