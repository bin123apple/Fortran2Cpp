#include <iostream>
#include <cstdlib>

#define N 1024

void unit_test(int a[], int b[], int c[]) {
    bool test_passed = true;
    
    // Test array a initialization
    for (int i = 0; i < N; ++i) {
        if (a[i] != i * 2) {
            std::cout << "Test failed for array a at index: " << i << std::endl;
            test_passed = false;
        }
    }
    
    // Test array b initialization
    for (int i = 0; i < N; ++i) {
        if (b[i] != i * 4) {
            std::cout << "Test failed for array b at index: " << i << std::endl;
            test_passed = false;
        }
    }
    
    // Test array c summation
    for (int i = 0; i < N; ++i) {
        if (c[i] != a[i] + b[i]) {
            std::cout << "Test failed for array c at index: " << i << std::endl;
            test_passed = false;
        }
    }
    
    if (test_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    int a[N], b[N], c[N];
    
    #pragma acc data copyout(a[0:N])
    #pragma acc kernels
    for (int i = 0; i < N; ++i) {
        a[i] = i * 2;
    }
    
    #pragma acc data copyout(b[0:N])
    #pragma acc kernels
    for (int i = 0; i < N; ++i) {
        b[i] = i * 4;
    }
    
    #pragma acc data copyin(a[0:N], b[0:N]) copyout(c[0:N])
    #pragma acc kernels
    for (int i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }
    
    unit_test(a, b, c);

    return 0;
}