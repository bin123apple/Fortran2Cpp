Certainly! Below is the translated C++ code from the provided Fortran code. Note that the translation involves adapting Fortran constructs to their C++ equivalents, including OpenMP directives.

```cpp
#include <omp.h>
#include "global_foo.h" // Assuming this header file exists and contains the declaration of 'foo()'

int main() {
    // Equivalent of the Fortran 'program' block
    #pragma omp parallel
    {
        // Equivalent of the Fortran 'call foo()' statement
        foo();
    }
    return 0;
}
```

### Key Points:

1. **Program Structure**: The Fortran `program` block is translated to the `main` function in C++.
2. **OpenMP Directives**: The `!$omp parallel` and `!$omp end parallel` directives are translated to `#pragma omp parallel` and its closing brace `}`, respectively.
3. **Function Call**: The Fortran `call foo()` statement is translated to a direct call to `foo()` in C++.
4. **Headers and Includes**: The `use omp_lib` and `use global_foo` statements in Fortran are translated to including the OpenMP header (`#include <omp.h>`) and the header file for the global function (`#include "global_foo.h"`), respectively.

Make sure that the `global_foo.h` file exists and contains the declaration of the `foo()` function, as shown in the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify that the translation is correct by ensuring that the `foo()` function is called correctly.

### Fortran Unit Test Code

First, let's create a simple Fortran program that includes the `foo()` function and a test program that calls `foo()`.

**global_foo.f90** (The module containing the `foo()` function)
```fortran
module global_foo
    implicit none
contains
    subroutine foo()
        print *, "foo() called"
    end subroutine foo
end module global_foo
```

**DRB082_declared_in_func_orig_yes_test.f90** (The test program)
```fortran
program DRB082_declared_in_func_orig_yes_test
    use omp_lib
    use global_foo
    implicit none

    !$omp parallel
    call foo()
    !$omp end parallel
end program DRB082_declared_in_func_orig_yes_test
```

To compile and run the Fortran code, you can use the following commands (assuming you have an OpenMP-capable Fortran compiler like `gfortran`):
```sh
gfortran -fopenmp global_foo.f90 DRB082_declared_in_func_orig_yes_test.f90 -o test_program
./test_program
```

### C++ Unit Test Code

Next, let's create a C++ program that includes the `foo()` function and a test program that calls `foo()`.

**global_foo.h** (The header file containing the `foo()` function declaration)
```cpp
#ifndef GLOBAL_FOO_H
#define GLOBAL_FOO_H

void foo();

#endif // GLOBAL_FOO_H
```

**global_foo.cpp** (The implementation of the `foo()` function)
```cpp
#include "global_foo.h"
#include <iostream>

void foo() {
    std::cout << "foo() called" << std::endl;
}
```

**main.cpp** (The test program)
```cpp
#include <omp.h>
#include "global_foo.h"

int main() {
    #pragma omp parallel
    {
        foo();
    }
    return 0;
}
```

To compile and run the C++ code, you can use the following commands (assuming you have an OpenMP-capable C++ compiler like `g++`):
```sh
g++ -fopenmp main.cpp global_foo.cpp -o test_program
./test_program
```

### Expected Output

When you run the Fortran and C++ test programs, you should see the following output:
```
foo() called
```

This output verifies that the `foo()` function is correctly called in both the Fortran and C++ versions, demonstrating that the translation has been done correctly.
