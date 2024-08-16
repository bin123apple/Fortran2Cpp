Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    const int N = len;
    const int M = len;
    const int K = len;

    std::vector<std::vector<float>> a(N, std::vector<float>(M));
    std::vector<std::vector<float>> b(M, std::vector<float>(K));
    std::vector<std::vector<float>> c(K, std::vector<float>(N, 0.0f));

    #pragma omp parallel for collapse(3)
    for (int i = 0; i < N; ++i) {
        for (int l = 0; l < K; ++l) {
            for (int j = 0; j < M; ++j) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    return 0;
}
```

### Explanation:
1. **Headers and Namespaces**:
   - `#include <iostream>` for input/output operations.
   - `#include <vector>` for dynamic arrays.
   - `#include <omp.h>` for OpenMP functions.

2. **Constants and Variables**:
   - `const int len = 100;` defines the size of the matrices.
   - `const int N = len;`, `const int M = len;`, and `const int K = len;` define the dimensions of the matrices.
   - `std::vector<std::vector<float>> a(N, std::vector<float>(M));` creates a 2D vector `a` with dimensions `N x M`.
   - `std::vector<std::vector<float>> b(M, std::vector<float>(K));` creates a 2D vector `b` with dimensions `M x K`.
   - `std::vector<std::vector<float>> c(K, std::vector<float>(N, 0.0f));` creates a 2D vector `c` with dimensions `K x N`, initializing all elements to `0.0f`.

3. **Parallel Loop**:
   - `#pragma omp parallel for collapse(3)` specifies that the loop should be parallelized and that all the loops should be collapsed into a single parallel loop.
   - The loop iterates over `i` from `0` to `N-1`, `l` from `0` to `K-1`, and `j` from `0` to `M-1`.
   - The operation `c[i][j] += a[i][l] * b[l][j];` is performed for each element in the matrix `c`.

4. **Return Statement**:
   - The `main` function returns `0`, indicating successful execution.

This C++ code performs the same matrix multiplication as the original Fortran code using OpenMP for parallelization.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_matrix_multiply
    use omp_lib
    implicit none

    integer :: N,M,K, len, i, j, l
    real, dimension(:,:), allocatable :: a, b, c
    real :: start, finish

    len = 100
    N=len
    M=len
    K=len

    allocate (a(N,M))
    allocate (b(M,K))
    allocate (c(K,N))

    ! Initialize matrices a and b
    do i = 1, N
        do j = 1, M
            a(i,j) = 1.0
        end do
        do j = 1, K
            b(i,j) = 2.0
        end do
    end do

    ! Start timer
    call cpu_time(start)

    !$omp parallel do private(j, l)
    do i = 1, N
        do l = 1, K
            do j = 1, M
                c(i,j) = c(i,j) + a(i,l) * b(l,j)
            end do
        end do
    end do
    !$omp end parallel do

    ! Stop timer
    call cpu_time(finish)

    print *, "Time taken: ", finish - start, " seconds."

    deallocate(a,b,c)
end program test_matrix_multiply
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>

int main() {
    const int len = 100;
    const int N = len;
    const int M = len;
    const int K = len;

    std::vector<std::vector<float>> a(N, std::vector<float>(M, 1.0f));
    std::vector<std::vector<float>> b(M, std::vector<float>(K, 2.0f));
    std::vector<std::vector<float>> c(K, std::vector<float>(N, 0.0f));

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for collapse(3)
    for (int i = 0; i < N; ++i) {
        for (int l = 0; l < K; ++l) {
            for (int j = 0; j < M; ++j) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Time taken: " << elapsed.count() << " seconds." << std::endl;

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The matrices `a` and `b` are initialized with values `1.0` and `2.0` respectively.
   - The `cpu_time` function is used to measure the execution time.
   - The parallel loop is executed and the time taken is printed.

2. **C++ Unit Test Code**:
   - The matrices `a` and `b` are initialized with values `1.0f` and `2.0f` respectively.
   - The `std::chrono` library is used to measure the execution time.
   - The parallel loop is executed and the time taken is printed.

### Compilation and Execution:

1. **Fortran**:
   - Compile the Fortran code with OpenMP support: `gfortran -fopenmp test_matrix_multiply.f90 -o test_matrix_multiply`
   - Run the executable: `./test_matrix_multiply`

2. **C++**:
   - Compile the C++ code with OpenMP support: `g++ -fopenmp test_matrix_multiply.cpp -o test_matrix_multiply`
   - Run the executable: `./test_matrix_multiply`

By comparing the execution times of both the Fortran and C++ codes, you can verify if the translation is correct.
