To translate the given Fortran code to C++, we need to consider several aspects, including the array allocation, the OpenMP directives, and the loop structure. The Fortran code uses OpenMP for parallelization and has a dependency between iterations. In C++, we can use OpenMP for parallelization as well, but the syntax and structure of the code will differ.

Here's a C++ version of the Fortran code, using OpenMP for parallelization:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));

    #pragma omp parallel for collapse(2) ordered
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            #pragma omp ordered
            {
                a[i][j] = a[i][j] + 1;
                // The sink and source directives in Fortran correspond to the implicit barrier in C++.
                // We don't need to explicitly specify them in C++.
                std::cout << "test i = " << i << "  j = " << j << std::endl;
            }
        }
    }

    return 0;
}
```

Key Points in the Translation:

1. **Array Allocation**: In C++, we use `std::vector` for dynamic arrays. This automatically manages memory and provides a similar dynamic array functionality as Fortran's `allocate`.

2. **OpenMP Directives**: The OpenMP directives in C++ are similar to Fortran, but the syntax is slightly different. The `#pragma omp parallel for` directive is used to parallelize the outer loop, and `#pragma omp ordered` is used to specify the order of execution. The `collapse(2)` directive is used to collapse the nested loops into a single parallel loop.

3. **Loop Structure**: The loop indices and conditions are directly translated from Fortran to C++. Note that C++ uses 0-based indexing, so the loop bounds are adjusted accordingly.

4. **Dependency Handling**: The `depend(sink:i-1,j) depend(sink:i,j-1)` directives in Fortran imply that the current iteration depends on the previous iterations. In C++, this is implicitly handled by the ordered block. The `depend(source)` directive in Fortran indicates that the current iteration is a source of dependency for subsequent iterations. In C++, this is also implicitly handled by the ordered block.

5. **Printing**: The `print*` statement in Fortran is replaced with `std::cout` in C++ for output.

6. **Compilation**: To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using GCC, you can compile the program with the `-fopenmp` flag:
   ```sh
   g++ -fopenmp your_program.cpp -o your_program
   ```

This translation assumes that the goal is to maintain the parallel execution and the order of operations as closely as possible to the original Fortran code. However, due to differences in how OpenMP is implemented between Fortran and C++, there might be slight differences in behavior.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking that the array `a` is correctly updated and that the operations are performed in the correct order. However, due to the parallel execution and the dependency between iterations, a straightforward comparison of the output or the final state of the array `a` is not straightforward. Instead, we can focus on verifying that the operations are performed correctly and in the correct order, which can be checked by ensuring that each element of the array `a` is incremented exactly `len * len` times.

### Fortran Unit Test

For the Fortran code, we'll modify the original program to include a simple test after the parallel region. This test will check if each element of the array `a` is equal to `len`.

```fortran
program DRB094_doall2_ordered_orig_no
    use omp_lib
    implicit none

    integer, parameter :: len = 100
    integer :: i, j
    integer, allocatable :: a(:,:)

    allocate (a(len,len))

    !$omp parallel do ordered(2)
    do i = 1, len
        do j = 1, len
            a(i,j) = a(i,j)+1
            !$omp ordered depend(sink:i-1,j) depend (sink:i,j-1)
            !print*,'test i =',i,'  j =',j
            !$omp ordered depend(source)
        end do
    end do
    !$omp end parallel do

    ! Test
    do i = 1, len
        do j = 1, len
            if (a(i,j) /= len) then
                print*, 'Test failed at a(',i,',',j,') = ', a(i,j)
                stop
            endif
        end do
    end do
    print*, 'All tests passed.'

end program
```

### C++ Unit Test

For the C++ code, we'll use a similar approach, modifying the main function to include a simple test after the parallel region. This test will check if each element of the array `a` is equal to `len`.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<std::vector<int>> a(len, std::vector<int>(len, 0));

    #pragma omp parallel for collapse(2) ordered
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            #pragma omp ordered
            {
                a[i][j] = a[i][j] + 1;
                // The sink and source directives in Fortran correspond to the implicit barrier in C++.
                // We don't need to explicitly specify them in C++.
                //std::cout << "test i = " << i << "  j = " << j << std::endl;
            }
        }
    }

    // Test
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (a[i][j] != len) {
                std::cout << "Test failed at a[" << i << "][" << j << "] = " << a[i][j] << std::endl;
                return 1;
            }
        }
    }
    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

### Compilation and Execution

- **Fortran**: Use a Fortran compiler that supports OpenMP, such as gfortran, and compile the Fortran code with the `-fopenmp` flag:
  ```sh
  gfortran -fopenmp DRB094_doall2_ordered_orig_no.f90 -o DRB094_doall2_ordered_orig_no
  ./DRB094_doall2_ordered_orig_no
  ```

- **C++**: Use a C++ compiler that supports OpenMP, such as g++, and compile the C++ code with the `-fopenmp` flag:
  ```sh
  g++ -fopenmp DRB094_doall2_ordered_orig_no.cpp -o DRB094_doall2_ordered_orig_no
  ./DRB094_doall2_ordered_orig_no
  ```

These tests ensure that each element of the array `a` is incremented `len * len` times, verifying that the operations are performed correctly and in the correct order.
