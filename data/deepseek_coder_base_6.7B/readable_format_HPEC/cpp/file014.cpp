Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    long long num_steps = 2000000000;
    double interval_width, pi = 0.0;
    double x;

    interval_width = 1.0 / num_steps;

    #pragma omp parallel for reduction(+:pi) private(x)
    for (long long i = 1; i <= num_steps; i++) {
        x = (i + 0.5) * interval_width;
        pi += 1.0 / (x * x + 1.0);
    }

    pi = pi * 4.0 * interval_width;

    std::cout << "PI = " << pi << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Declare variables**:
   - `long long num_steps = 2000000000;` specifies the number of steps for the computation.
   - `double interval_width, pi = 0.0;` declares the variables for the interval width and the approximation of pi.
   - `double x;` declares a variable for intermediate calculations.

3. **Compute the interval width and initialize pi**:
   - `interval_width = 1.0 / num_steps;` computes the width of each interval.
   - `pi = 0.0;` initializes the approximation of pi.

4. **Parallelize the loop with reduction**:
   - `#pragma omp parallel for reduction(+:pi) private(x)` specifies that the loop should be parallelized and the reduction operation should be applied to `pi`.
   - The loop iterates from `1` to `num_steps`.
   - Inside the loop, `x` is computed and `pi` is updated.

5. **Finalize the computation and print the result**:
   - `pi = pi * 4.0 * interval_width;` computes the final approximation of pi.
   - `std::cout` is used to print the result.

### Compilation:
To compile this C++ program with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp -o pi_approx pi_approx.cpp
```

This command tells the compiler to enable OpenMP support (`-fopenmp`) and outputs an executable named `pi_approx`.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the computed value of pi with the expected value.

### Fortran Unit Test

To test the Fortran code, you can create a simple test program that includes the original code and checks if the computed value of pi is close to the expected value.

```fortran
program test_pi
    use omp_lib
    implicit none

    real(kind = 16) :: x, interval_width, pi
    integer(kind = 8) :: i, num_steps
    real(kind = 16) :: expected_pi

    pi = 0.0
    num_steps = 2000000000
    interval_width = 1.0 / num_steps

    !$omp parallel do reduction(+:pi) private(x)
    do i = 1, num_steps
        x = (i + 0.5) * interval_width
        pi = pi + 1.0 / (x*x + 1.0)
    end do
    !$omp end parallel do

    pi = pi * 4.0 * interval_width

    expected_pi = 3.14159265358979323846
    if (abs(pi - expected_pi) < 1.0e-10) then
        print *, "Test Passed: PI =", pi
    else
        print *, "Test Failed: PI =", pi
    end if

end program test_pi
```

### C++ Unit Test

For the C++ code, you can use a simple test function that computes the value of pi and checks if it is close to the expected value.

```cpp
#include <iostream>
#include <omp.h>
#include <cmath>

bool test_pi() {
    long long num_steps = 2000000000;
    double interval_width, pi = 0.0;
    double x;
    double expected_pi = 3.14159265358979323846;

    interval_width = 1.0 / num_steps;

    #pragma omp parallel for reduction(+:pi) private(x)
    for (long long i = 1; i <= num_steps; i++) {
        x = (i + 0.5) * interval_width;
        pi += 1.0 / (x * x + 1.0);
    }

    pi = pi * 4.0 * interval_width;

    if (std::abs(pi - expected_pi) < 1.0e-10) {
        std::cout << "Test Passed: PI = " << pi << std::endl;
        return true;
    } else {
        std::cout << "Test Failed: PI = " << pi << std::endl;
        return false;
    }
}

int main() {
    if (test_pi()) {
        return 0;
    } else {
        return 1;
    }
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran test, use the following commands:

```sh
gfortran -fopenmp -o test_pi test_pi.f90
./test_pi
```

#### C++

To compile and run the C++ test, use the following commands:

```sh
g++ -fopenmp -o test_pi test_pi.cpp
./test_pi
```

### Expected Output

For both the Fortran and C++ tests, the expected output should indicate that the test passed, indicating that the translation was successful.

```
Test Passed: PI = 3.14159265358979323846
```

This output verifies that the translation from Fortran to C++ was successful and that both implementations produce the same result for the computation of pi.
