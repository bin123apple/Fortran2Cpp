Certainly! Below is the translated C++ code from the provided Fortran code. Note that OpenMP directives in Fortran and C++ are slightly different, but the logic and structure are similar.

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int init, local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp master
        {
            init = 10;
        }
        local = init;
    }

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The main function is the entry point of the C++ program.
3. **Variable Declarations**: The variables `init` and `local` are declared at the beginning of the `main` function.
4. **Parallel Region**: The `#pragma omp parallel` directive is used to start a parallel region. The `shared(init)` clause makes `init` a shared variable, and `private(local)` makes `local` a private variable within the parallel region.
5. **Master Region**: The `#pragma omp master` directive specifies that the enclosed code block is executed by the master thread only.
6. **Initialization**: Inside the master region, `init` is set to 10.
7. **Local Assignment**: After the master region, `local` is assigned the value of `init`.
8. **End Parallel Region**: The parallel region ends with `#pragma omp end parallel`.

This C++ code should behave similarly to the provided Fortran code, with the OpenMP directives controlling the parallel execution.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by checking the values of `init` and `local`.

### Fortran Unit Test

To test the Fortran code, you can create a Fortran program that includes the original code and checks the values of `init` and `local`.

```fortran
program test_DRB124_master_orig_yes
    use omp_lib
    implicit none

    integer :: init, local

    !$omp parallel shared(init) private(local)
        !$omp master
        init = 10
        !$omp end master
        local = init
    !$omp end parallel

    ! Check the values
    if (init == 10) then
        print *, 'Test init PASS'
    else
        print *, 'Test init FAIL'
    end if

    if (local == 10) then
        print *, 'Test local PASS'
    else
        print *, 'Test local FAIL'
    end if

end program test_DRB124_master_orig_yes
```

### C++ Unit Test

To test the C++ code, you can create a C++ program that includes the translated code and checks the values of `init` and `local`.

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int init, local;

    #pragma omp parallel shared(init) private(local)
    {
        #pragma omp master
        {
            init = 10;
        }
        local = init;
    }

    // Check the values
    if (init == 10) {
        std::cout << "Test init PASS" << std::endl;
    } else {
        std::cout << "Test init FAIL" << std::endl;
    }

    if (local == 10) {
        std::cout << "Test local PASS" << std::endl;
    } else {
        std::cout << "Test local FAIL" << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

#### Fortran
To compile and run the Fortran unit test, you can use the following commands (assuming you have a Fortran compiler like `gfortran`):

```sh
gfortran -fopenmp test_DRB124_master_orig_yes.f90 -o test_DRB124_master_orig_yes
./test_DRB124_master_orig_yes
```

#### C++
To compile and run the C++ unit test, you can use the following commands (assuming you have a C++ compiler like `g++`):

```sh
g++ -fopenmp test_DRB124_master_orig_yes.cpp -o test_DRB124_master_orig_yes
./test_DRB124_master_orig_yes
```

### Expected Output

For both Fortran and C++, the expected output should be:

```
Test init PASS
Test local PASS
```

This indicates that the `init` and `local` variables have the correct values, verifying the correctness of the translation.
