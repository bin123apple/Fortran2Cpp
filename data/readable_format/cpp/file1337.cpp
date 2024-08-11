#include <iostream>
#include <vector>

int main() {
    const int size = 32 * 32 * 32;
    std::vector<int> arr(size); // Dynamic array with size equivalent to arr in Fortran
    int i, j, k, idx;
    int x;
    int* p;

    // Initialize array
    for (i = 0; i < size; i++) {
        arr[i] = i;
    }

    // Parallel region
    #pragma acc kernels copy(arr[0:size])
    {
        for (i = 0; i < 32; i++) {
            #pragma acc loop gang(num:32)
            for (j = 0; j < 32; j++) {
                p = &x; // Pointer assignment equivalent
                x = i ^ (j * 3); // ieor in Fortran is equivalent to XOR (^) in C++

                #pragma acc loop worker(num:8) private(x, p)
                for (k = 0; k < 32; k++) {
                    arr[i * 1024 + j * 32 + k] += x * k;
                }
                
                *p = i | (j * 5); // ior in Fortran is equivalent to OR (|) in C++

                #pragma acc loop vector(length:32)
                for (k = 0; k < 32; k++) {
                    arr[i * 1024 + j * 32 + k] += x * k;
                }
            }
        }
    } // End of parallel region

    // Verification loop
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            for (k = 0; k < 32; k++) {
                idx = i * 1024 + j * 32 + k;
                if (arr[idx] != idx + (i ^ (j * 3)) * k + (i | (j * 5)) * k) {
                    std::cerr << "Mismatch detected, stopping.\n";
                    return 1;
                }
            }
        }
    }

    return 0;
}