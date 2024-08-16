Sure, here is the equivalent C++ code for the provided Fortran code. This C++ code uses OpenMP for parallel processing.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char** argv) {
    int len = 100;
    std::vector<std::string> args;
    std::vector<int> a;

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
        } catch (const std::exception&) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    // Allocate and initialize vector a
    a.resize(len);
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Parallel processing
    #pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + 1;
    }

    std::cout << "a(50)=" << a[49] << std::endl; // Note: C++ uses 0-based indexing

    return 0;
}
```

### Explanation:
1. **Command Line Arguments**: The `argc` and `argv` parameters are used to handle command line arguments in C++. The `args` vector is used to store these arguments as strings.
2. **Dynamic Arrays**: The `std::vector` container is used for dynamic arrays.
3. **Parallel Processing**: The OpenMP pragma `#pragma omp parallel for` is used to parallelize the loop.
4. **Indexing**: C++ uses 0-based indexing, so `a[49]` corresponds to the 50th element in Fortran's 1-based indexing.
5. **Error Handling**: The `std::stoi` function is used to convert the first command line argument to an integer. If the conversion fails, an error message is printed.

Make sure to compile this C++ code with OpenMP support enabled. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp -o program program.cpp
```
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the output of both programs.

### Fortran Unit Test Code

This Fortran program will run the original program and capture its output.

```fortran
program test_drb030
    implicit none
    integer :: i, len, argCount, allocStatus, rdErr, ix
    character(len=80), dimension(:), allocatable :: args
    integer, dimension(:), allocatable :: a
    character(len=80) :: cmd
    character(len=80) :: output
    character(len=80) :: expectedOutput

    len = 100
    argCount = 1
    allocate(args(argCount), stat=allocStatus)
    if (allocStatus > 0) then
        write (*,'(a)') "Allocation error, program terminated."
        stop
    end if

    ! Prepare command line arguments
    write(args(1), '(i10)') len

    ! Construct command to run the original program
    cmd = 'DRB030_truedep1_var_yes '
    do ix = 1, argCount
        cmd = trim(cmd) // ' ' // trim(args(ix))
    end do

    ! Execute the command and capture the output
    call execute_command_line(cmd, output)

    ! Expected output
    expectedOutput = 'a(50)=100'

    ! Check if the output matches the expected output
    if (trim(output) == trim(expectedOutput)) then
        write(*,*) "Test Passed"
    else
        write(*,*) "Test Failed"
        write(*,*) "Expected: ", trim(expectedOutput)
        write(*,*) "Got: ", trim(output)
    end if

    deallocate(args,a)
end program test_drb030
```

### C++ Unit Test Code

This C++ program will run the translated program and capture its output.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>
#include <cassert>
#include <sstream>
#include <cstdlib>

std::string run_program(int argc, char** argv) {
    std::ostringstream output;
    std::vector<std::string> args;
    std::vector<int> a;

    if (argc == 0) {
        output << "No command line arguments provided." << std::endl;
    }

    // Allocate and initialize args vector
    args.resize(argc);
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix + 1]);
    }

    int len = 100;
    if (argc >= 1) {
        try {
            len = std::stoi(args[0]);
        } catch (const std::exception&) {
            output << "Error, invalid integer value." << std::endl;
        }
    }

    // Allocate and initialize vector a
    a.resize(len);
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Parallel processing
    #pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + 1;
    }

    output << "a(50)=" << a[49] << std::endl; // Note: C++ uses 0-based indexing

    return output.str();
}

int main(int argc, char** argv) {
    std::string output = run_program(argc, argv);
    std::cout << output;

    // Expected output
    std::string expectedOutput = "a(50)=100
";

    // Check if the output matches the expected output
    if (output == expectedOutput) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
        std::cout << "Expected: " << expectedOutput << std::endl;
        std::cout << "Got: " << output << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

#### Fortran
To compile and run the Fortran unit test code, you can use the following commands:

```sh
gfortran -fopenmp -o test_drb030 test_drb030.f90
./test_drb030
```

#### C++
To compile and run the C++ unit test code, you can use the following commands:

```sh
g++ -fopenmp -o test_program test_program.cpp
./test_program
```

### Explanation

1. **Fortran Unit Test**:
   - The `test_drb030` program prepares the command line arguments and executes the original Fortran program.
   - It captures the output and compares it with the expected output.

2. **C++ Unit Test**:
   - The `run_program` function runs the translated C++ code and returns its output as a string.
   - The `main` function captures the output and compares it with the expected output.

By running these unit tests, you can verify that the translated
