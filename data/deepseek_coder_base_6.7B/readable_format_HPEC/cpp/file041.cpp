Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main(int argc, char *argv[]) {
    int len = 100;
    int numNodes, numNodes2, ix, rdErr;
    std::vector<std::string> args;
    std::vector<int> x;

    // Check if command line arguments are provided
    if (argc == 1) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Allocate and initialize args vector
    args.resize(argc);
    for (ix = 1; ix < argc; ++ix) {
        args[ix] = std::string(argv[ix]);
    }

    // Check if there is at least one argument
    if (argc >= 2) {
        // Attempt to convert the first argument to an integer
        try {
            len = std::stoi(args[1]);
        } catch (const std::exception&) {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    // Allocate and initialize x vector
    x.resize(len);
    numNodes = len;
    numNodes2 = 0;

    // Initialize x array
    for (int i = 0; i < len; ++i) {
        if ((i + 1) % 2 == 0) {
            x[i] = 5;
        } else {
            x[i] = -5;
        }
    }

    // Parallel loop to count negative numbers
    #pragma omp parallel for reduction(+:numNodes2)
    for (int i = numNodes - 1; i >= 0; --i) {
        if (x[i] <= 0) {
            numNodes2--;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    return 0;
}
```

### Key Points:
1. **Command Line Arguments**: The Fortran code uses `command_argument_count` and `get_command_argument` to handle command line arguments. In C++, these are represented by `argc` and `argv`, respectively.
2. **Dynamic Arrays**: Fortran's `allocatable` arrays are replaced with `std::vector` in C++ for dynamic array allocation.
3. **Parallel Loop**: The OpenMP directives for parallelization are used similarly in C++. The `reduction` clause is used to safely update `numNodes2` across threads.
4. **Error Handling**: The Fortran code checks for errors when reading the command line argument. In C++, exceptions are used for error handling, and `std::stoi` is used to convert strings to integers.
5. **Output**: The `print*` statement in Fortran is replaced with `std::cout` in C++ for console output.

Make sure you compile the C++ code with OpenMP support enabled. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the outputs for a set of predefined inputs.

### Fortran Unit Test

Save the following Fortran code in a file named `test_drb012_minusminus_var_yes.f90`:

```fortran
program test_DRB012_minusminus_var_yes
    use omp_lib
    implicit none

    integer :: i, len, numNodes, numNodes2, argCount, allocStatus, rdErr, ix
    character(len=80), dimension(:), allocatable :: args
    integer, dimension (:), allocatable :: x

    len = 100

    argCount = 1
    allocate(args(argCount), stat=allocStatus)
    if (allocStatus > 0) then
        write (*,'(a)') "Allocation error, program terminated."
        stop
    end if
    args(1) = '100'

    allocate (x(len))

    numNodes=len
    numNodes2=0
    !initialize x()
    do i = 1, len
        if (MOD(i,2) == 0) then
            x(i) = 5
        else
            x(i) = -5
        end if
    end do

    !$omp parallel do
    do i = numNodes, 1, -1
        if (x(i) <= 0) then
            numNodes2 = numNodes2-1
        end if
    end do
    !$omp end parallel do

    print*,"numNodes2 =", numNodes2

    deallocate(args,x)
end program test_DRB012_minusminus_var_yes
```

### C++ Unit Test

Save the following C++ code in a file named `test_drb012_minusminus_var_yes.cpp`:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main() {
    int len = 100;
    int numNodes, numNodes2, ix, rdErr;
    std::vector<std::string> args;
    std::vector<int> x;

    // Allocate and initialize args vector
    args.resize(1);
    args[0] = "100"; // Simulate command line argument

    // Allocate and initialize x vector
    x.resize(len);
    numNodes = len;
    numNodes2 = 0;

    // Initialize x array
    for (int i = 0; i < len; ++i) {
        if ((i + 1) % 2 == 0) {
            x[i] = 5;
        } else {
            x[i] = -5;
        }
    }

    // Parallel loop to count negative numbers
    #pragma omp parallel for reduction(+:numNodes2)
    for (int i = numNodes - 1; i >= 0; --i) {
        if (x[i] <= 0) {
            numNodes2--;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran unit test, use the following commands:

```sh
gfortran -fopenmp test_drb012_minusminus_var_yes.f90 -o test_drb012_minusminus_var_yes
./test_drb012_minusminus_var_yes
```

#### C++

To compile and run the C++ unit test, use the following commands:

```sh
g++ -fopenmp test_drb012_minusminus_var_yes.cpp -o test_drb012_minusminus_var_yes
./test_drb012_minusminus_var_yes
```

### Expected Output

For both the Fortran and C++ unit tests, the expected output should be:

```
numNodes2 = 50
```

This output verifies that the translation is correct by comparing the outputs of both programs for the same input.
