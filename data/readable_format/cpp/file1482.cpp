#include <iostream>
#include <vector>
#include <cstdlib>

// Helper function for array indexing
inline int index(int i, int j, int k, int J, int K) {
    return (i * J * K) + (j * K) + k;
}

void test1() {
    const int I = 3, J = 3, K = 3; // Adjust dimensions to 0-based indexing
    std::vector<int> a(I * J * K, 0); // 3D array flattened into a 1D vector, initialized to 0
    bool l = false;

    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            for (int k = 0; k < K; ++k) {
                a[index(i, j, k, J, K)] = (i+1) + (j+4) + (k+5); // Adjusting indices
                if (a[index(i, j, k, J, K)] != (i+1) + (j+4) + (k+5)) {
                    l = true;
                }
            }
        }
    }

    if (l) std::abort(); // If l is true, there was an error
    else std::cout << "test1 passed." << std::endl;
}

void test2() {
    const int I = 3, J = 3, K = 3; // Dimensions
    std::vector<int> a(I * J * K, 0); // 3D array flattened into a 1D vector

    for (int k = 0; k < I; ++k) {
        for (int kk = 0; kk < J; ++kk) {
            for (int kkk = 0; kkk < K; ++kkk) {
                a[index(k, kk, kkk, J, K)] = 1;
            }
        }
    }

    bool error_detected = false;
    for (int l = 0; l < I; ++l) {
        for (int ll = 0; ll < J; ++ll) {
            for (int lll = 0; lll < K; ++lll) {
                if (a[index(l, ll, lll, J, K)] != 1) {
                    error_detected = true;
                }
                a[index(l, ll, lll, J, K)] = 2; // Update for the second check
            }
        }
    }

    for (int l = 0; l < I; ++l) {
        for (int ll = 0; ll < J; ++ll) {
            for (int lll = 0; lll < K; ++lll) {
                if (a[index(l, ll, lll, J, K)] != 2) {
                    error_detected = true;
                }
            }
        }
    }

    if (error_detected) std::abort(); // If an error was detected, abort
    else std::cout << "test2 passed." << std::endl;
}

int main() {
    test1();
    test2();

    return 0;
}