To translate the given Fortran code to C++, we need to understand the structure and functionality of the original Fortran code and then replicate its behavior using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for parallel reduction, which is a common parallel programming model in Fortran and C++.

Here's a C++ translation of the Fortran code:

```cpp
#include <iostream>
#include <omp.h>

// Assuming the f1 function is defined elsewhere
extern void f1(int& i);

int main() {
    int sum = 0;

    // OpenMP parallel region with reduction on sum
    #pragma omp parallel reduction(+:sum) num_threads(10)
    {
        int i = 0;
        f1(i); // Assuming f1 modifies i in some way
        #pragma omp critical
        {
            sum += i;
        }
    }

    if (sum != 10) {
        std::cout << "sum = " << sum << std::endl;
    }

    return 0;
}
```

### Key Points in Translation:

1. **Program Structure**: The C++ `main` function serves as the entry point for the program, similar to the `program` block in Fortran.

2. **OpenMP Directives**: The `#pragma omp parallel` directive is used in C++ to parallelize the loop. The `reduction` clause is used to perform a reduction on the `sum` variable. The `num_threads(10)` clause specifies the number of threads to use.

3. **Variable Declarations**: The `integer :: i, sum` declaration in Fortran is translated to `int i, sum = 0;` in C++. The `i` variable is declared and initialized inside the parallel region to ensure it is private to each thread.

4. **Function Call**: The `call f1(i)` statement in Fortran is translated to a direct function call `f1(i);` in C++. Note that in C++, functions are declared before they are used, so you might need to declare `f1` before this line or include its declaration in a header file.

5. **Critical Section**: The `#pragma omp critical` directive is used to ensure that only one thread at a time can modify the `sum` variable. This is necessary because the `sum` variable is shared between threads and we don't want multiple threads to update it concurrently.

6. **Output**: The `print*,'sum =',sum` statement in Fortran is translated to `std::cout` in C++ for output.

7. **Implicit None**: In Fortran, `implicit none` is used to avoid implicit typing based on variable names, which is a common practice in C++ as well.

8. **Header Files**: The `use omp_lib` and `use DRB076` statements in Fortran are assumed to be included in the C++ code as `#include <omp.h>` and any necessary headers for `f1`, respectively.

This translation assumes that `f1` is a function that modifies the `i` variable in some way, which is why it's called with a reference (`f1(i)`) in C++. If `f1` doesn't modify `i`, you might need to adjust the function signature accordingly.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will check if the `sum` variable is correctly updated after parallel execution.

### Fortran Unit Test

For the Fortran code, we can create a simple test by modifying the `f1` subroutine to increment `i` by 1. This way, we know that `sum` should end up as 10 after parallel execution.

First, let's modify the original Fortran code to include a simple test subroutine `f1`:

```fortran
module DRB076
contains
    subroutine f1(i)
        integer, intent(inout) :: i
        i = i + 1
    end subroutine f1
end module DRB076

program DRB076_flush_orig_no
    use omp_lib
    use DRB076
    implicit none

    integer :: i, sum
    i = 0
    sum = 0

    !$omp parallel reduction(+:sum) num_threads(10) private(i)
    call f1(i)
    sum = sum + i
    !$omp end parallel

    if (sum /= 10) then
        print*, 'sum =', sum
    else
        print*, 'Test passed.'
    end if
end program
```

### C++ Unit Test

For the C++ code, we can create a similar test by modifying the `f1` function to increment `i` by 1. This way, we know that `sum` should end up as 10 after parallel execution.

Here's the modified C++ code with a simple test:

```cpp
#include <iostream>
#include <omp.h>

void f1(int& i) {
    i += 1;
}

int main() {
    int sum = 0;

    #pragma omp parallel reduction(+:sum) num_threads(10)
    {
        int i = 0;
        f1(i);
        #pragma omp critical
        {
            sum += i;
        }
    }

    if (sum != 10) {
        std::cout << "sum = " << sum << std::endl;
    } else {
        std::cout << "Test passed." << std::endl;
    }

    return 0;
}
```

### Running the Tests

To run the Fortran test, you'll need a Fortran compiler that supports OpenMP, such as `gfortran`. Compile and run the Fortran code as follows:

```sh
gfortran -fopenmp your_fortran_code.f90 -o fortran_test
./fortran_test
```

To run the C++ test, you'll need a C++ compiler that supports OpenMP, such as `g++`. Compile and run the C++ code as follows:

```sh
g++ -fopenmp your_cpp_code.cpp -o cpp_test
./cpp_test
```

### Expected Output

For both tests, the expected output should be:

```
Test passed.
```

This indicates that the `sum` variable was correctly updated to 10 by the parallel execution of the `f1` subroutine/function.
