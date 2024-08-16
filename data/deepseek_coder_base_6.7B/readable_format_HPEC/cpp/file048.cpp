Certainly! Below is the translated C++ code from the provided Fortran code. This translation assumes you are familiar with basic C++ syntax and OpenMP for parallelism.

```cpp
#include <omp.h>
#include <iostream>

int main() {
    omp_lock_t lck;
    int var = 0;
    int i;

    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams num_teams(1)
        {
            #pragma omp distribute parallel for
            for(i = 1; i <= 100; ++i) {
                omp_set_lock(&lck);
                var = var + 1;
                omp_unset_lock(&lck);
            }
        }
    }

    omp_destroy_lock(&lck);

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Declare Variables**: The variables `var` and `i` are declared as integers.
3. **Initialize Lock**: An OpenMP lock `lck` is declared and initialized.
4. **Target Directive**: The `#pragma omp target` directive is used to specify the target for parallel execution. In this case, it maps `var` to the target device with ID 0.
5. **Teams Directive**: The `#pragma omp teams num_teams(1)` directive specifies that only one team of threads should be created.
6. **Distribute Parallel For**: The `#pragma omp distribute parallel for` directive is used to parallelize the loop across multiple threads.
7. **Lock Operations**: Inside the parallel loop, `omp_set_lock(&lck)` is used to acquire the lock, `var = var + 1` is executed safely, and `omp_unset_lock(&lck)` is used to release the lock.
8. **Destroy Lock**: The lock `lck` is destroyed.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp your_program.cpp -o your_program
```

Replace `your_program.cpp` with the name of your C++ source file.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by checking the final value of `var`.

### Fortran Unit Test Code

```fortran
program test_DRB152_missinglock2_orig_gpu_no
    use omp_lib
    implicit none

    integer (kind=omp_lock_kind) :: lck
    integer :: var, i
    var = 0

    !$omp target map(tofrom:var) device(0)
    !$omp teams num_teams(1)
    !$omp distribute parallel do
    do i = 1, 100
        call omp_set_lock(lck)
        var = var+1
        call omp_unset_lock(lck)
    end do
    !$omp end distribute parallel do
    !$omp end teams
    !$omp end target

    print *, 'Final value of var:', var
    if (var == 100) then
        print *, 'Test Passed'
    else
        print *, 'Test Failed'
    end if
end program test_DRB152_missinglock2_orig_gpu_no
```

### C++ Unit Test Code

```cpp
#include <omp.h>
#include <iostream>

int main() {
    omp_lock_t lck;
    int var = 0;
    int i;

    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams num_teams(1)
        {
            #pragma omp distribute parallel for
            for(i = 1; i <= 100; ++i) {
                omp_set_lock(&lck);
                var = var + 1;
                omp_unset_lock(&lck);
            }
        }
    }

    omp_destroy_lock(&lck);

    std::cout << "Final value of var: " << var << std::endl;
    if (var == 100) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran unit test code, use the following commands:

```sh
gfortran -fopenmp test_DRB152_missinglock2_orig_gpu_no.f90 -o test_DRB152_missinglock2_orig_gpu_no
./test_DRB152_missinglock2_orig_gpu_no
```

#### C++

To compile and run the C++ unit test code, use the following commands:

```sh
g++ -fopenmp test_DRB152_missinglock2_orig_gpu_no.cpp -o test_DRB152_missinglock2_orig_gpu_no
./test_DRB152_missinglock2_orig_gpu_no
```

### Expected Output

For both the Fortran and C++ programs, the expected output should be:

```
Final value of var: 100
Test Passed
```

This indicates that the final value of `var` is 100, which is the expected result based on the logic of the program.
