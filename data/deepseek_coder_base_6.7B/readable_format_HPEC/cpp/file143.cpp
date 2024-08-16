Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int N = 1000;
    std::vector<std::vector<float>> a(N, std::vector<float>(N));
    std::vector<float> v(N), v_out(N);

    // Initialize the matrix 'a' and the vector 'v' with some values
    // Here we're just filling them with zeros for simplicity
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = 0.0f; // Example initialization
        }
        v[i] = 0.0f; // Example initialization
    }

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        float sum = 0.0f;
        #pragma omp parallel for reduction(+:sum)
        for (int j = 0; j < N; ++j) {
            sum += a[i][j] * v[j];
        }
        v_out[i] = sum;
    }

    // Optionally, print the results for verification
    // for (int i = 0; i < N; ++i) {
    //     std::cout << "v_out[" << i << "] = " << v_out[i] << std::endl;
    // }
}

int main() {
    foo();
    return 0;
}
```

### Explanation:
1. **Headers and Namespaces**:
   - `#include <iostream>` for input/output operations.
   - `#include <vector>` for dynamic arrays.
   - `#include <omp.h>` for OpenMP directives.

2. **Function Declaration**:
   - `void foo()` is the equivalent of the Fortran subroutine.

3. **Matrix and Vector Initialization**:
   - In C++, we use `std::vector` to create dynamic arrays for matrices and vectors.
   - We initialize the matrix `a` and the vector `v` with zeros for simplicity.

4. **Parallel Loops**:
   - The outer loop is parallelized using `#pragma omp parallel for`.
   - The inner loop is also parallelized using `#pragma omp parallel for reduction(+:sum)`.

5. **Computation**:
   - The computation inside the inner loop is straightforward: `sum += a[i][j] * v[j];`.
   - The result `sum` is stored in `v_out[i]`.

6. **Main Function**:
   - The `main` function calls `foo()` to execute the computation.

### Notes:
- Make sure you have the OpenMP library installed and enabled in your compiler.
- The initialization of `a` and `v` with zeros is just an example. You can initialize them with any values as needed.
- The print statement inside the inner loop is commented out because it might cause performance issues in a parallel environment. If you need to verify the results, uncomment the print lines and inspect the output manually.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB062_matrixvector2_orig_no
    use omp_lib
    implicit none

    call foo

contains

    subroutine foo()
        integer :: i, j, N
        real :: sum
        real, dimension(:,:), allocatable :: a
        real, dimension(:), allocatable :: v, v_out

        N = 1000
        allocate (a(N,N))
        allocate (v(N))
        allocate (v_out(N))

        ! Initialize the matrix 'a' and the vector 'v' with some values
        do i = 1, N
            do j = 1, N
                a(i, j) = 1.0
            end do
            v(i) = 1.0
        end do

        do i = 1, N
            sum = 0.0
            !$omp parallel do reduction(+:sum)
            do j = 1, N
                sum = sum + a(i,j)*v(j)
            end do
            !$omp end parallel do
            v_out(i) = sum
        end do

        ! Verify the results
        do i = 1, N
            if (v_out(i) /= N) then
                print *, "Test failed at index ", i
                stop
            end if
        end do
        print *, "All tests passed."

    end subroutine foo

end program test_DRB062_matrixvector2_orig_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

void foo() {
    int N = 1000;
    std::vector<std::vector<float>> a(N, std::vector<float>(N, 1.0f)); // Initialize with 1.0
    std::vector<float> v(N, 1.0f); // Initialize with 1.0
    std::vector<float> v_out(N);

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        float sum = 0.0f;
        #pragma omp parallel for reduction(+:sum)
        for (int j = 0; j < N; ++j) {
            sum += a[i][j] * v[j];
        }
        v_out[i] = sum;
    }

    // Verify the results
    for (int i = 0; i < N; ++i) {
        if (v_out[i] != N) {
            std::cout << "Test failed at index " << i << std::endl;
            exit(1);
        }
    }
    std::cout << "All tests passed." << std::endl;
}

int main() {
    foo();
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `foo` subroutine initializes the matrix `a` and vector `v` with `1.0`.
   - It computes `v_out` using the matrix-vector multiplication.
   - It verifies if all elements of `v_out` are `N` (where `N = 1000`) and prints the result.

2. **C++ Unit Test Code**:
   - The `foo` function initializes the matrix `a` and vector `v` with `1.0f`.
   - It computes `v_out` using the matrix-vector multiplication.
   - It verifies if all elements of `v_out` are `N` (where `N = 1000`) and prints the result.

### Running the Tests:

- **Fortran**:
  - Compile the Fortran code with OpenMP support: `gfortran -fopenmp test_DRB062_matrixvector2_orig_no.f90 -o test_DRB062`.
  - Run the executable: `./test_DRB062`.

- **C++**:
  - Compile the C++ code with OpenMP support: `g++ -fopenmp test_DRB062_matrixvector2_orig_no.cpp -o test_DRB062`.
  - Run the executable: `./test_DRB062`.

Both tests should pass, indicating that the translation is correct.
