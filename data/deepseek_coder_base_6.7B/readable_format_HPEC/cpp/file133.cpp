Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> a(4);
    std::vector<int> psum(4);
    int sum = 0;

    #pragma omp parallel num_threads(2)
    {
        #pragma omp for schedule(dynamic, 1)
        for (int i = 0; i < 4; ++i) {
            a[i] = i + 1;
        }

        #pragma omp single
        {
            #pragma omp task
            {
                #pragma omp task
                {
                    psum[1] = a[2] + a[3];
                }
                psum[0] = a[0] + a[1];
            }
            #pragma omp taskwait
            sum = psum[1] + psum[0];
        }
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}
```

### Explanation:
1. **Vector Initialization**:
   - In C++, we use `std::vector<int>` to dynamically allocate arrays.
   - The size of `a` and `psum` is set to 4.

2. **OpenMP Directives**:
   - `#pragma omp parallel num_threads(2)` specifies that the parallel region should use 2 threads.
   - `#pragma omp for schedule(dynamic, 1)` specifies a dynamic schedule with a chunk size of 1.
   - `#pragma omp single` ensures that the enclosed block is executed by a single thread.
   - `#pragma omp task` is used to create tasks.
   - `#pragma omp taskwait` waits for all tasks to complete.

3. **Loop and Array Access**:
   - Fortran arrays are 1-based, whereas C++ arrays are 0-based. Adjustments are made accordingly.
   - The loop runs from 0 to 3 to match C++'s 0-based indexing.

4. **Computation and Output**:
   - The computation and output are straightforward translations from Fortran to C++.

### Notes:
- Ensure you have the OpenMP library installed and enabled in your compiler. For example, if you are using GCC, you can compile the program with the `-fopenmp` flag.
- The original Fortran code uses `print*` for output, which is equivalent to `std::cout` in C++.

This C++ code should produce the same output as the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB117_taskwait_waitonlychild_orig_yes
    use omp_lib
    implicit none

    integer, dimension(:), allocatable :: a, psum
    integer :: sum, i
    integer :: expected_sum

    allocate(a(4))
    allocate(psum(4))

    expected_sum = 10

    !$omp parallel num_threads(2)
        !$omp do schedule(dynamic, 1)
        do i = 1, 4
            a(i) = i
        end do
        !$omp end do

        !$omp single
            !$omp task
                !$omp task
                  psum(2) = a(3)+a(4)
                !$omp end task
               psum(1) = a(1)+a(2)
            !$omp end task
            !$omp taskwait
            sum = psum(2)+psum(1)
        !$omp end single
    !$omp end parallel

    if (sum == expected_sum) then
        print*, 'Test Passed'
    else
        print*, 'Test Failed'
    end if

    deallocate(a, psum)
end program test_DRB117_taskwait_waitonlychild_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> a(4);
    std::vector<int> psum(4);
    int sum = 0;
    int expected_sum = 10;

    #pragma omp parallel num_threads(2)
    {
        #pragma omp for schedule(dynamic, 1)
        for (int i = 0; i < 4; ++i) {
            a[i] = i + 1;
        }

        #pragma omp single
        {
            #pragma omp task
            {
                #pragma omp task
                {
                    psum[1] = a[2] + a[3];
                }
                psum[0] = a[0] + a[1];
            }
            #pragma omp taskwait
            sum = psum[1] + psum[0];
        }
    }

    if (sum == expected_sum) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
   - The `expected_sum` is set to 10.
   - The program checks if the computed `sum` matches the `expected_sum` and prints "Test Passed" or "Test Failed" accordingly.

2. **C++ Unit Test Code**:
   - The `expected_sum` is set to 10.
   - The program checks if the computed `sum` matches the `expected_sum` and prints "Test Passed" or "Test Failed" accordingly.

### Compilation and Execution:
1. **Fortran**:
   - Compile the Fortran code with OpenMP support:
     ```sh
     gfortran -fopenmp test_DRB117_taskwait_waitonlychild_orig_yes.f90 -o test_DRB117
     ./test_DRB117
     ```

2. **C++**:
   - Compile the C++ code with OpenMP support:
     ```sh
     g++ -fopenmp test_DRB117_taskwait_waitonlychild_orig_yes.cpp -o test_DRB117
     ./test_DRB117
     ```

Both programs should output "Test Passed" if the translation is correct.
