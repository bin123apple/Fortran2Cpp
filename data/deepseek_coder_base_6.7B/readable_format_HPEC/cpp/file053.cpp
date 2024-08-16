Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int a = 0;

    #pragma omp parallel shared(a)
    {
        #pragma omp master
        {
            a = 0;
        }

        #pragma omp for reduction(+:a)
        for(int i = 1; i <= 10; ++i) {
            a += i;
        }

        #pragma omp single
        {
            std::cout << "Sum is " << a << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Main Function**: The main function in C++ is equivalent to the `program` block in Fortran.
3. **Variable Declaration**: The variable `a` is declared as an integer.
4. **Parallel Region**: The `#pragma omp parallel shared(a)` directive is used to start a parallel region, with `a` being shared among all threads.
5. **Master Region**: The `#pragma omp master` directive ensures that the code inside it is executed by the master thread only. This is equivalent to the `!$omp master` block in Fortran.
6. **Initialization**: The variable `a` is initialized to 0 within the master region.
7. **Reduction**: The `#pragma omp for reduction(+:a)` directive is used to perform a reduction operation on `a`. This is equivalent to the `!$omp do reduction(+:a)` block in Fortran.
8. **Loop**: A for loop is used to iterate from 1 to 10, adding each number to `a`.
9. **Single Region**: The `#pragma omp single` directive ensures that the code inside it is executed by a single thread, which is the master thread after the reduction operation. This is equivalent to the `!$omp single` block in Fortran.
10. **Output**: The sum is printed using `std::cout` inside the single region.
11. **End Parallel Region**: The parallel region is ended with `#pragma omp end parallel`.

This C++ code should produce the same output as the original Fortran code, calculating the sum of numbers from 1 to 10 using OpenMP parallel reduction.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

```fortran
program test_DRB140_reduction_barrier_orig_yes
    use omp_lib
    implicit none

    integer :: a, i
    integer :: expected_sum

    a = 0
    expected_sum = 55

    !$omp parallel shared(a) private(i)
        !$omp master
        a = 0
        !$omp end master

        !$omp do reduction(+:a)
        do i = 1, 10
            a = a+i
        end do
        !$omp end do

        !$omp single
        if (a == expected_sum) then
            print*, "Test Passed: Sum is ", a
        else
            print*, "Test Failed: Sum is ", a
        end if
        !$omp end single
    !$omp end parallel
end program test_DRB140_reduction_barrier_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int a = 0;
    int expected_sum = 55;

    #pragma omp parallel shared(a)
    {
        #pragma omp master
        {
            a = 0;
        }

        #pragma omp for reduction(+:a)
        for(int i = 1; i <= 10; ++i) {
            a += i;
        }

        #pragma omp single
        {
            if (a == expected_sum) {
                std::cout << "Test Passed: Sum is " << a << std::endl;
            } else {
                std::cout << "Test Failed: Sum is " << a << std::endl;
            }
        }
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
    - The `expected_sum` variable is initialized to 55, which is the sum of numbers from 1 to 10.
    - The parallel region is used to perform the reduction operation.
    - After the reduction, the master thread checks if the computed sum (`a`) matches the expected sum (`expected_sum`).
    - If the sum is correct, it prints "Test Passed"; otherwise, it prints "Test Failed".

2. **C++ Unit Test Code**:
    - The `expected_sum` variable is initialized to 55, which is the sum of numbers from 1 to 10.
    - The parallel region is used to perform the reduction operation.
    - After the reduction, the master thread checks if the computed sum (`a`) matches the expected sum (`expected_sum`).
    - If the sum is correct, it prints "Test Passed"; otherwise, it prints "Test Failed".

### Compilation and Execution:

#### Fortran:
To compile and run the Fortran unit test code, you can use the following commands:
```sh
gfortran -fopenmp test_DRB140_reduction_barrier_orig_yes.f90 -o test_DRB140_reduction_barrier_orig_yes
./test_DRB140_reduction_barrier_orig_yes
```

#### C++:
To compile and run the C++ unit test code, you can use the following commands:
```sh
g++ -fopenmp test_DRB140_reduction_barrier_orig_yes.cpp -o test_DRB140_reduction_barrier_orig_yes
./test_DRB140_reduction_barrier_orig_yes
```

Both programs should output "Test Passed: Sum is 55" if the translation is correct.
