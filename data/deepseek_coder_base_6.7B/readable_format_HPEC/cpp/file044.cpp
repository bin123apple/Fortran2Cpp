Certainly! Below is the translated version of the provided Fortran code to C++. Note that the translation process involves several steps, including converting Fortran array indexing to C++ array indexing, handling OpenMP directives, and adapting the syntax to C++.

```cpp
#include <iostream>
#include <omp.h>

// Assuming the size of arrays is known and fixed at 8
const int N = 8;

int main() {
    int b[N] = {0};
    int c[N] = {2};
    int temp[N] = {0};
    int a = 2;
    int val = 0;

    // Initialization of arrays
    for (int i = 0; i < N; ++i) {
        b[i] = 0;
        c[i] = 2;
        temp[i] = 0;
    }

    a = 2;

    // OpenMP directives for parallel execution
    #pragma omp target map(tofrom:b) map(to:c,temp,a) device(0)
    #pragma omp parallel
    {
        for (int i = 0; i < 100; ++i) {
            #pragma omp for
            for (int j = 0; j < N; ++j) {
                temp[j] = b[j] + c[j];
            }

            #pragma omp for
            for (int j = N - 1; j >= 0; --j) {
                b[j] = temp[j] * a;
            }
        }
    }

    // Additional loop for calculation
    for (int i = 0; i < 100; ++i) {
        val += 2;
        val *= 2;
    }

    // Checking the condition and printing
    for (int i = 0; i < N; ++i) {
        if (val != b[i]) {
            std::cout << b[i] << " " << val << std::endl;
        }
    }

    return 0;
}
```

### Key Points in the Translation:

1. **Array Indexing:** Fortran arrays are 1-based, while C++ arrays are 0-based. This requires adjusting the loop indices and array accesses.
2. **OpenMP Directives:** The OpenMP directives (`!$omp ...` in Fortran) are translated to `#pragma omp ...` in C++. Note that the syntax and structure of the directives are slightly different, but the logic remains the same.
3. **Printing:** Fortran's `print*,` is replaced with C++'s `std::cout` for output.
4. **Headers:** The `use` statements in Fortran are replaced with `#include` directives in C++ for necessary libraries.
5. **Program Structure:** The Fortran `program` block is translated to the `main` function in C++, which is the entry point of a C++ program.

Ensure you have the OpenMP library installed and enabled in your compiler settings to compile this C++ code. For example, if you are using GCC, you can compile the program with the `-fopenmp` flag.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ codes involves checking if the outputs are as expected. For simplicity, I'll provide a basic framework for testing the output of both programs. Note that due to the random nature of the output, we'll focus on testing the correctness of the final state of the arrays `b` and the value of `val`.

### Fortran Unit Test

For Fortran, we can write a simple test program that runs the original code and checks the final values of `b` and `val`.

```fortran
program test_DRB159_nobarrier_orig_gpu_no
    use omp_lib
    implicit none
    integer :: b(8), c(8), temp(8), a, val, i

    ! Initialize arrays and variables
    do i = 1, 8
        b(i) = 0
        c(i) = 2
        temp(i) = 0
    end do
    a = 2
    val = 0

    ! Execute the original code
    ! (This part is the same as the original program, but omitted for brevity)

    ! Test the final state of b and val
    print *, "Testing final state of b and val..."
    if (all(b == expected_b) .and. val == expected_val) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_DRB159_nobarrier_orig_gpu_no
```

Replace `expected_b` and `expected_val` with the actual expected values for `b` and `val` after execution.

### C++ Unit Test

For C++, we can use a simple test framework like Google Test. However, for simplicity, I'll provide a basic test similar to the Fortran one.

```cpp
#include <iostream>
#include <omp.h>
#include <cassert>

// Assuming the size of arrays is known and fixed at 8
const int N = 8;

int main() {
    int b[N] = {0};
    int c[N] = {2};
    int temp[N] = {0};
    int a = 2;
    int val = 0;

    // Execute the translated code
    // (This part is the same as the translated program, but omitted for brevity)

    // Test the final state of b and val
    std::cout << "Testing final state of b and val..." << std::endl;
    bool test_passed = true;
    for (int i = 0; i < N; ++i) {
        if (b[i] != expected_b[i]) {
            test_passed = false;
            break;
        }
    }
    if (val != expected_val) {
        test_passed = false;
    }

    if (test_passed) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}
```

Replace `expected_b` and `expected_val` with the actual expected values for `b` and `val` after execution.

### Running the Tests

To run these tests, you'll need to compile and execute the Fortran and C++ programs. The expected values for `b` and `val` should be determined by running the original code and noting the final state. These tests will verify that the translated code produces the same output as the original.

- For Fortran, use a command similar to `gfortran -fopenmp test_DRB159_nobarrier_orig_gpu_no.f90 -o test_DRB159_nobarrier_orig_gpu_no && ./test_DRB159_nobarrier_orig_gpu_no`.
- For C++, use a command similar to `g++ -fopenmp test_DRB159_nobarrier_orig_gpu_no.cpp -o test_DRB159_nobarrier_orig_gpu_no && ./test_DRB159_nobarrier_orig_gpu_no`.

These tests are basic and assume that the expected values are known and correctly set. In a real-world scenario, you would likely use a more sophisticated testing framework or method to automate the testing process and verify the correctness of the translated code against a wider range of inputs and scenarios.
