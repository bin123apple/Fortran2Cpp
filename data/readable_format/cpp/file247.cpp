#include <iostream>
#include <omp.h>

// Function prototypes
void foo(int i, int j, int k, int s, int a[100]);
void bar(int i, int j, int k, int s, int a[100]);

int main() {
    int a[100], i, j, k, s;

    // Test values
    i = 2;
    j = 1;
    k = 10;
    s = 1;

    // Initialize array
    std::fill_n(a, 100, 0);

    // Test foo
    foo(i, j, k, s, a);
    std::cout << "Test foo:";
    for (int l = 0; l < 10; ++l) std::cout << " " << a[l];
    std::cout << std::endl;

    // Reset array
    std::fill_n(a, 100, 0);

    // Test bar
    bar(i, j, k, s, a);
    std::cout << "Test bar:";
    for (int l = 0; l < 10; ++l) std::cout << " " << a[l];
    std::cout << std::endl;

    return 0;
}

// Function definitions

void foo(int i, int j, int k, int s, int a[100]) {
    int l;
    #pragma omp parallel for schedule(dynamic, s * 2)
    for (l = j; l <= k; ++l) {
        a[l - 1] = i; // Adjusted for zero-based indexing
    }

    #pragma omp parallel for schedule(dynamic, s * 2)
    for (l = j; l <= k; l += 3) {
        a[l - 1] = i + 1; // Adjusted for zero-based indexing
    }
}

void bar(int i, int j, int k, int s, int a[100]) {
    int l;
    #pragma omp parallel for schedule(guided, s * 2)
    for (l = j; l <= k; ++l) {
        a[l - 1] = i; // Adjusted for zero-based indexing
    }

    #pragma omp parallel for schedule(guided, s * 2)
    for (l = j; l <= k; l += 3) {
        a[l - 1] = i + 1; // Adjusted for zero-based indexing
    }
}