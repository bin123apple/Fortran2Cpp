To translate the given Fortran code to C++, we need to understand the structure and functionality of the original Fortran code and then replicate it using C++ syntax and constructs. The Fortran code defines a module `DRB086` with a type `A` and a procedure `foo`, which is intended to demonstrate the use of OpenMP for parallel execution. The main program then creates an instance of type `A`, calls `foo` in a parallel region, and prints the values of a static data member of type `A` and a global variable within the module `DRB086`.

Here's a C++ translation that captures the essence of the original Fortran code:

```cpp
#include <iostream>
#include <omp.h>

// Equivalent to the Fortran module 'DRB086'
namespace DRB086 {
    // Equivalent to the Fortran derived type 'A'
    class A {
    public:
        int x, y;
        static int counter; // Equivalent to the Fortran 'counter'

        A(int x = 0, int y = 0) : x(x), y(y) {}

        // Equivalent to the Fortran procedure 'foo'
        static void foo() {
            #pragma omp atomic
            counter++;
        }
    };

    // Definition of the static member 'counter'
    int A::counter = 0;
}

int main() {
    using namespace DRB086;

    A c(0, 0); // Equivalent to the Fortran type instance 'c'

    #pragma omp parallel
    {
        #pragma omp single
        A::foo(); // Equivalent to the Fortran call to 'foo' in a parallel region
    }

    std::cout << A::counter << std::endl; // Equivalent to the Fortran print statement

    return 0;
}
```

Key Points in the Translation:

1. **Namespace `DRB086`**: Used to encapsulate the class `A` and its static member `counter`, similar to the Fortran module.

2. **Class `A`**: Defined with public member variables `x` and `y` and a static member `counter`. The constructor initializes `x` and `y`. The `foo` method is declared as `static` to belong to the class rather than any instance of it, and it uses `#pragma omp atomic` to ensure that the increment of `counter` is atomic.

3. **Static Member `counter`**: Initialized outside the class definition to ensure it has a unique instance.

4. **Parallel Execution**: The `#pragma omp parallel` directive is used in C++ to parallelize the execution of the code. The `#pragma omp single` directive ensures that only one thread executes the call to `foo`. This mimics the behavior of the Fortran code where `foo` is called in a parallel region.

5. **Print Statement**: The C++ standard library function `std::cout` is used to print the value of `A::counter`.

6. **Headers and Pragmas**: The `#include <iostream>` directive is used for input/output operations, and `#include <omp.h>` is included for OpenMP support. The `#pragma` directives are used similarly to those in Fortran to enable OpenMP functionalities.

This translation aims to maintain the original code's structure and functionality while adapting it to C++ syntax and constructs.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create unit tests. These tests will check the functionality of the `foo` procedure/method and the static data member `counter`.

### Fortran Unit Test

For the Fortran code, we can create a simple test program that calls `foo` in parallel and checks the value of `counter` after the parallel region.

```fortran
program test_DRB086
    use omp_lib
    use DRB086
    implicit none

    integer :: i

    ! Initialize counter to 0
    A::counter = 0

    ! Call foo in parallel
    !$omp parallel do
    do i = 1, 100
        call A::foo()
    end do
    !$omp end parallel do

    ! Check the value of counter
    if (A::counter == 100) then
        print *, "Test passed: counter == 100"
    else
        print *, "Test failed: counter /= 100"
    end if
end program test_DRB086
```

This test initializes `counter` to 0, calls `foo` in a parallel loop 100 times, and then checks if `counter` is equal to 100. If the test passes, it prints "Test passed: counter == 100"; otherwise, it prints "Test failed: counter /= 100".

### C++ Unit Test

For the C++ code, we can use a simple test framework like Google Test to verify the functionality. However, for simplicity, I'll provide a basic test similar to the Fortran test.

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

namespace DRB086 {
    class A {
    public:
        int x, y;
        static int counter;

        A(int x = 0, int y = 0) : x(x), y(y) {}

        static void foo() {
            #pragma omp atomic
            counter++;
        }
    };

    int A::counter = 0;
}

void test_foo() {
    using namespace DRB086;

    // Initialize counter to 0
    A::counter = 0;

    // Call foo in parallel
    #pragma omp parallel for
    for (int i = 0; i < 100; ++i) {
        A::foo();
    }

    // Check the value of counter
    assert(A::counter == 100);
    std::cout << "Test passed: counter == 100" << std::endl;
}

int main() {
    test_foo();
    return 0;
}
```

This C++ test does essentially the same thing as the Fortran test: it initializes `counter` to 0, calls `foo` in a parallel loop 100 times, and then checks if `counter` is equal to 100. If the test passes, it prints "Test passed: counter == 100".

### Running the Tests

- **Fortran**: Compile the Fortran test program with an OpenMP-capable Fortran compiler (e.g., `gfortran`) and run the executable. Ensure that the OpenMP library is available.
  
  ```sh
  gfortran -fopenmp test_DRB086.f90 -o test_DRB086
  ./test_DRB086
  ```

- **C++**: Compile the C++ test program with an OpenMP-capable C++ compiler (e.g., `g++`) and run the executable. Ensure that the OpenMP library is available.

  ```sh
  g++ -fopenmp test_DRB086.cpp -o test_DRB086
  ./test_DRB086
  ```

These tests should confirm that the functionality of the `foo` procedure/method and the static data member `counter` are correctly implemented and behave as expected in both the Fortran and C++ versions.
