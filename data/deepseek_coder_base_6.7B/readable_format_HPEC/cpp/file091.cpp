To translate the given Fortran code to C++, we need to understand the structure and functionality of the original Fortran code, then replicate its behavior using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for parallelism and task dependencies.

Here's a C++ version of the Fortran code, using OpenMP for parallelism and task dependencies:

```cpp
#include <iostream>
#include <omp.h>

// Function prototype
void foo();

int main() {
    // Open a parallel region
    #pragma omp parallel
    {
        // Execute the foo subroutine in a single thread
        #pragma omp single
        {
            foo();
        }
    }

    return 0;
}

void foo() {
    int x, y;
    x = 0;
    y = 2;

    // First task: x = x + 1
    #pragma omp task depend(inout: x) shared(x)
    {
        x = x + 1; // This line is executed in a separate thread
    }

    // Second task: y = y - x
    #pragma omp task shared(y)
    {
        y = y - x; // This line is executed in a separate thread
    }

    // Wait for the first task to complete
    #pragma omp taskwait depend(in: x)

    // Print the results
    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;

    // Wait for the second task to complete
    #pragma omp taskwait
}
```

### Explanation:
1. **Program Structure**: The `main` function in C++ serves as the entry point for the program, similar to the `program` block in Fortran.
2. **OpenMP Directives**: The OpenMP directives `#pragma omp parallel`, `#pragma omp single`, `#pragma omp task`, and `#pragma omp taskwait` are used to parallelize the code and manage task dependencies in a similar manner to the Fortran code.
3. **Subroutine `foo`**: The `foo` function replicates the functionality of the Fortran subroutine. It initializes `x` and `y`, then creates two tasks, one to increment `x` and another to decrement `y` by `x`. The `taskwait` directives ensure that the operations on `x` and `y` are synchronized.
4. **Printing**: The results are printed to the standard output using `std::cout`.

### Compilation:
To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp -o DRB168_taskdep5_orig_yes_omp_50 DRB168_taskdep5_orig_yes_omp_50.cpp
```

This will compile the C++ code with OpenMP support and generate an executable named `DRB168_taskdep5_orig_yes_omp_50`.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the correctness of the `foo` subroutine/function. The expected behavior is that after the parallel execution, `x` should be incremented by 1 and `y` should be decremented by the value of `x`.

### Fortran Unit Test

For the Fortran code, we can write a simple test program that calls `foo` and checks the results.

```fortran
program test_foo
    use omp_lib
    implicit none
    integer :: x, y

    ! Call the foo subroutine
    call foo(x, y)

    ! Check the results
    if (x == 1 .and. y == 0) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_foo

subroutine foo(x, y)
    use omp_lib
    implicit none
    integer, intent(out) :: x, y
    integer :: tmp

    x = 0
    y = 2

    !$omp parallel private(tmp)
    !$omp single
    !$omp task depend(inout: x) shared(x)
    x = x + 1
    !$omp end task

    !$omp task shared(y)
    y = y - x
    !$omp end task

    !$omp taskwait depend(in: x)
    tmp = x
    !$omp end taskwait

    !$omp taskwait
    !$omp end parallel

    ! Update x and y based on the task execution
    x = tmp
end subroutine foo
```

### C++ Unit Test

For the C++ code, we can use a simple test function that calls `foo` and checks the results.

```cpp
#include <iostream>
#include <omp.h>

void foo(int& x, int& y);

int main() {
    int x, y;

    // Call the foo function
    foo(x, y);

    // Check the results
    if (x == 1 && y == 0) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}

void foo(int& x, int& y) {
    x = 0;
    y = 2;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(inout: x) shared(x)
            {
                x = x + 1; // This line is executed in a separate thread
            }

            #pragma omp task shared(y)
            {
                y = y - x; // This line is executed in a separate thread
            }

            #pragma omp taskwait depend(in: x)
            {
                // This block is executed after the first task is completed
                // and before the second taskwait
            }

            #pragma omp taskwait
            {
                // This block is executed after the second task is completed
            }
        }
    }
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran test program, use the following commands:

```sh
gfortran -fopenmp -o test_foo test_foo.f90
./test_foo
```

#### C++

To compile and run the C++ test program, use the following commands:

```sh
g++ -fopenmp -o test_foo test_foo.cpp
./test_foo
```

These commands compile the test programs with OpenMP support and then run them. If the translation is correct, both tests should print "Test passed."
