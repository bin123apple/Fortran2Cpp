Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 100;
    double getSum = 0.0;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    if (argc >= 1) {
        try {
            len = std::stoi(argv[1]);
        } catch (const std::exception&) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    std::vector<std::vector<double>> u(len, std::vector<double>(len));

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            u[i][j] = 0.5;
        }
    }

    #pragma omp parallel for reduction(+:getSum) private(i, j, temp)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            double temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    return 0;
}
```

### Key Points of Translation:

1. **Command Line Arguments**: The Fortran code uses `command_argument_count` and `get_command_argument` to handle command line arguments. In C++, `argc` and `argv` are used for this purpose. The length of the matrix `len` is set based on the first command line argument if provided, with error handling for invalid integers.

2. **Dynamic Arrays**: Fortran's allocatable arrays are replaced with `std::vector` in C++ for dynamic arrays.

3. **Parallel Loops**: The OpenMP directives for parallelization are used similarly in C++. The `reduction` clause is used to safely accumulate `getSum` across threads.

4. **I/O Operations**: Fortran's `write` and `print` statements are replaced with C++'s `std::cout` for output.

5. **Error Handling**: Fortran's `stop` is replaced with C++'s `exit(EXIT_FAILURE)` for terminating the program upon allocation error.

6. **Type Declarations**: Fortran's `real` type is replaced with C++'s `double` for floating-point arithmetic.

7. **Loop Indices**: Fortran's 1-based indexing is replaced with C++'s 0-based indexing.

8. **Comments**: The `!$omp` directives in Fortran are replaced with `#pragma omp` in C++ for OpenMP directives.

Make sure you compile this C++ code with OpenMP support enabled. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp -o DRB022_reductionmissing_var_yes DRB022_reductionmissing_var_yes.cpp
```
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the outputs of both implementations.

### Fortran Unit Test Code

Save the following Fortran code in a file named `test_DRB022_reductionmissing_var_yes.f90`:

```fortran
program test_DRB022_reductionmissing_var_yes
    use omp_lib
    implicit none

    integer :: i, j, len, argCount, allocStatus, rdErr, ix
    real :: temp, getSum
    character(len=80), dimension(:), allocatable :: args
    real, dimension (:,:), allocatable :: u

    len = 100
    getSum = 0.0

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

    allocate (u(len, len))

    do i = 1, len
        do j = 1, len
            u(i,j) = 0.5
        end do
    end do

    !$omp parallel do private(temp, i, j) reduction(+:getSum)
    do i = 1, len
        do j = 1, len
            temp = u(i,j)
            getSum = getSum + temp * temp
        end do
    end do
    !$omp end parallel do

    print*,"sum =", getSum

    deallocate(args,u)
end program test_DRB022_reductionmissing_var_yes
```

### C++ Unit Test Code

Save the following C++ code in a file named `test_DRB022_reductionmissing_var_yes.cpp`:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 100;
    double getSum = 0.0;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    if (argc >= 1) {
        try {
            len = std::stoi(argv[1]);
        } catch (const std::exception&) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    std::vector<std::vector<double>> u(len, std::vector<double>(len));

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            u[i][j] = 0.5;
        }
    }

    #pragma omp parallel for reduction(+:getSum) private(i, j, temp)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            double temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran unit test code, use the following commands:

```sh
gfortran -fopenmp -o test_DRB022_reductionmissing_var_yes test_DRB022_reductionmissing_var_yes.f90
./test_DRB022_reductionmissing_var_yes
```

#### C++

To compile and run the C++ unit test code, use the following commands:

```sh
g++ -fopenmp -o test_DRB022_reductionmissing_var_yes test_DRB022_reductionmissing_var_yes.cpp
./test_DRB022_reductionmissing_var_yes
```

### Expected Output

Both programs should output the same value for `sum =`. For example, if `len` is set to 100, the expected output should be:

```
sum = 300.0
