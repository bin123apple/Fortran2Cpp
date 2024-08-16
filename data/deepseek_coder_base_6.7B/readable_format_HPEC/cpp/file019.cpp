To translate the provided Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, memory management, and parallel processing. Here's a C++ version of the Fortran code using OpenMP for parallel processing:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]) {
    int len = 1000;
    std::vector<std::string> args(argv, argv + argc);

    if (argc >= 2) {
        try {
            len = std::stoi(args[1]);
        } catch (const std::exception&) {
            std::cerr << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    std::vector<std::vector<float>> a(len, std::vector<float>(len, 0.5f));

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] += a[i + 1][j];
        }
    }

    std::cout << "a(10,10) = " << a[9][9] << std::endl; // Note: C++ uses 0-based indexing

    return 0;
}
```

### Key Points:

1. **Array Indexing**: C++ uses 0-based indexing, unlike Fortran's 1-based indexing. This is adjusted in the loop where we access `a[9][9]` to correspond to the Fortran code's `a(10,10)`.

2. **Memory Management**: The `std::vector` class in C++ automatically manages memory, which simplifies the code and eliminates the need for manual allocation and deallocation.

3. **Parallel Processing**: The OpenMP pragma `#pragma omp parallel for collapse(2)` is used to parallelize the nested loops. The `collapse` clause is used to collapse the nested loops into a single parallel loop, which is more efficient for parallel execution.

4. **Command Line Arguments**: The `argc` and `argv` parameters are used to handle command line arguments, similar to how they are handled in Fortran. The `std::stoi` function is used to convert the second command line argument to an integer, which is then used to set the `len` variable.

5. **Error Handling**: The `try`-`catch` block is used to handle the case where the second command line argument cannot be converted to an integer, printing an error message and returning a non-zero value from `main` to indicate an error.

6. **Output**: The result is printed to the standard output using `std::cout`.

### Compilation and Execution:
To compile this C++ program with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o program program.cpp
./program
```

This command enables OpenMP and compiles the program into an executable named `program`, which you can then run.
Let's write some test to verify if the translation is correct. 
Below are examples of how you might write unit tests for both the Fortran and C++ versions of the code. These tests will verify the correctness of the program by checking the value of `a(10,10)` after the computation.

### Fortran Unit Test

For the Fortran code, we can add a simple test procedure at the end of the program to check the value of `a(10,10)`. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll do a basic check.

```fortran
program DRB004_antidep2_var_yes
    use omp_lib
    implicit none

    integer :: i, j, len, argCount, allocStatus, rdErr, ix
    character(len=80), dimension(:), allocatable :: args
    real, dimension (:,:), allocatable :: a
    real :: expected_value
    len = 1000

    argCount = command_argument_count()
    if (argCount == 0) then
        write (*,'(a)') "No command line arguments provided."
    end if

    allocate(args(argCount), stat=allocStatus)
    if (allocStatus > 0) then
        write (*,'(a)') "Allocation error, program terminated."
        stop
    end if

    do ix = 1, argCount
        call get_command_argument(ix,args(ix))
    end do

    if (argCount >= 1) then
        read (args(1), '(i10)', iostat=rdErr) len
        if (rdErr /= 0 ) then
            write (*,'(a)') "Error, invalid integer value."
        end if
    end if

    allocate (a(len,len))

    do i = 1, len
        do j = 1, len
            a(i,j) = 0.5
        end do
    end do

    !$omp parallel do private(j)
    do i = 1, len-1
        do j = 1, len
            a(i,j) = a(i,j) + a(i+1,j)
        end do
    end do
    !$omp end parallel do

    expected_value = 0.5 * (len - 1)
    if (a(10,10) == expected_value) then
        write(*,*) 'Test Passed: a(10,10) =', a(10,10)
    else
        write(*,*) 'Test Failed: a(10,10) =', a(10,10), 'Expected:', expected_value
    end if

    deallocate(a)
    deallocate(args)

end program
```

### C++ Unit Test

For the C++ code, we can use a simple assertion to check the value of `a[9][9]` after the computation. C++ doesn't include a built-in unit testing framework, but for a simple test, we'll use `assert` from the `<cassert>` header. For more comprehensive testing, consider using a testing framework like Google Test.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>
#include <cassert>

int main(int argc, char *argv[]) {
    int len = 1000;
    std::vector<std::string> args(argv, argv + argc);

    if (argc >= 2) {
        try {
            len = std::stoi(args[1]);
        } catch (const std::exception&) {
            std::cerr << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    std::vector<std::vector<float>> a(len, std::vector<float>(len, 0.5f));

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] += a[i + 1][j];
        }
    }

    float expected_value = 0.5f * (len - 1);
    assert(a[9][9] == expected_value); // Note: C++ uses 0-based indexing

    std::cout << "Test Passed: a(10,10) = " << a[9][9] << std::endl;

    return 0;
}
```

### Compilation and Execution

For the Fortran code, you can compile and run it using a Fortran compiler like `gfortran`:

```sh
gfortran -fopenmp -o test_fortran test_fortran.f90
./test_fortran
```

For the C++ code, you can compile and run it using a C++ compiler with OpenMP support, such as `g++`:

```sh
g++ -fopenmp -o test_cpp test_cpp.cpp
./test_cpp
```
