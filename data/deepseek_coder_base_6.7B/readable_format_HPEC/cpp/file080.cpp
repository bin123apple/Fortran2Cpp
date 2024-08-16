Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, j, n, m, len, rdErr;
    std::vector<std::string> args;
    std::vector<std::vector<float>> b;

    len = 1000;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Allocate and initialize args vector
    args.resize(argc);
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix + 1]);
    }

    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    n = len;
    m = len;

    // Allocate and initialize b matrix
    b.resize(n, std::vector<float>(m, 0.0f));

    // Fill b matrix with 0.5
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            b[i][j] = 0.5f;
        }
    }

    // Parallel loop to update b matrix
    #pragma omp parallel for private(j)
    for (i = 1; i < n; ++i) {
        for (j = 1; j < m; ++j) {
            b[i][j] = b[i-1][j-1];
        }
    }

    // Print the value of b[500][500]
    std::cout << "b[500][500] = " << b[500][500] << std::endl;

    return 0;
}
```

### Explanation:
1. **Command Line Arguments**: The number of command line arguments and their values are handled using `argc` and `argv`.
2. **Dynamic Arrays**: The Fortran `allocatable` arrays are translated to `std::vector` in C++.
3. **OpenMP Directives**: The OpenMP directives `!$omp parallel do private(j)` and `!$omp end parallel do` are translated to `#pragma omp parallel for private(j)`.
4. **Matrix Initialization and Updation**: The nested loops are used to initialize and update the matrix `b`.
5. **Printing the Result**: The value of `b[500][500]` is printed to the console.

### Notes:
- The `std::stoi` function is used to convert the string argument to an integer. If the conversion fails, an error message is printed.
- The `std::vector` is used to dynamically allocate arrays and matrices.
- OpenMP is used for parallelization.
- The `main` function in C++ corresponds to the `program` block in Fortran.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

To compile and run the Fortran code, you can use a Fortran compiler like `gfortran`. Here is the unit test code for the Fortran program:

```fortran
program test_DRB032_truedepfirstdimension_var_yes
    use omp_lib
    implicit none

    integer :: i, j, n, m, len, argCount, allocStatus, rdErr, ix
    character(len=80), dimension(:), allocatable :: args
    real, dimension(:,:), allocatable :: b
    real :: expected_value, tolerance

    len = 1000
    expected_value = 0.5
    tolerance = 1.0e-6

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

    n = len
    m = len
    allocate (b(n,m))

    do i = 1, n
        do j = 1, m
            b(i,j) = 0.5
        end do
    end do

    !$omp parallel do private(j)
    do i = 2, n
        do j = 2, m
            b(i,j) = b(i-1, j-1)
        end do
    end do
    !$omp end parallel do

    if (abs(b(500,500) - expected_value) > tolerance) then
        write(*,*) "Test failed: b(500,500) = ", b(500,500)
    else
        write(*,*) "Test passed: b(500,500) = ", b(500,500)
    end if

    deallocate(args,b)
end program test_DRB032_truedepfirstdimension_var_yes
```

### C++ Unit Test Code

To compile and run the C++ code, you can use a C++ compiler like `g++`. Here is the unit test code for the C++ program:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>
#include <cmath>

int main(int argc, char* argv[]) {
    int i, j, n, m, len, rdErr;
    std::vector<std::string> args;
    std::vector<std::vector<float>> b;
    float expected_value = 0.5f;
    float tolerance = 1.0e-6f;

    len = 1000;

    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Allocate and initialize args vector
    args.resize(argc);
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix + 1]);
    }

    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception& e) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    n = len;
    m = len;

    // Allocate and initialize b matrix
    b.resize(n, std::vector<float>(m, 0.0f));

    // Fill b matrix with 0.5
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            b[i][j] = 0.5f;
        }
    }

    // Parallel loop to update b matrix
    #pragma omp parallel for private(j)
    for (i = 1; i < n; ++i) {
        for (j = 1; j < m; ++j) {
            b[i][j] = b[i-1][j-1];
        }
    }

    // Check the value of b[500][500]
    if (std::abs(b[500][500] - expected_value) > tolerance) {
        std::cout << "Test failed: b[500
