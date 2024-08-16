To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code, and then replicate its behavior using C++ syntax and OpenMP directives. The Fortran code defines a parallel region with a subroutine `foo` that performs a parallel loop with `i` as a private variable and `x` as a lastprivate variable. The loop updates `x` with the value of `i` in each iteration. After the parallel loop, it prints the value of `x`.

Here is the equivalent C++ code using OpenMP:

```cpp
#include <iostream>
#include <omp.h>

// Function prototype
void foo();

int main() {
    // Equivalent of the Fortran 'program' block
    #pragma omp parallel
    {
        foo(); // Call the subroutine
    }

    return 0;
}

// Equivalent of the Fortran 'subroutine foo'
void foo() {
    int x = 0; // Initialize x to 0

    #pragma omp parallel for private(i) lastprivate(x)
    for (int i = 1; i <= 100; ++i) {
        x = i; // Update x with the value of i
    }

    // Print the value of x
    std::cout << "x = " << x << std::endl;
}
```

### Explanation:
1. **Program Structure**:
   - The `main` function in C++ serves as the entry point for the program, similar to the `program` block in Fortran.
   - The `#pragma omp parallel` directive is used to create a parallel region.

2. **Subroutine `foo`**:
   - The `foo` function is defined to replicate the behavior of the Fortran subroutine.
   - The `#pragma omp parallel for private(i) lastprivate(x)` directive is used to parallelize the loop with `i` as a private variable and `x` as a lastprivate variable.
   - The loop updates `x` with the value of `i` in each iteration.
   - After the loop, it prints the value of `x`.

### Notes:
- **Private Variables**: In the Fortran code, `i` is a private variable within the parallel loop. In C++, `i` is also private within the loop, but `x` is explicitly marked as `lastprivate` to retain its value after the parallel loop.
- **Loop Indexing**: Fortran arrays are 1-based, while C++ arrays (and most collections) are 0-based. However, since we're not using the loop index for any array indexing or calculations, the loop in this context starts from 1 and goes to 100, inclusive, which matches the original Fortran code's behavior.
- **Printing**: The C++ code uses `std::cout` for output, similar to the Fortran `print` statement.

This C++ code should exhibit the same functionality as the original Fortran code, with the loop updating `x` with the last value of `i` and then printing that value.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will execute the code and check if the output matches the expected result.

### Fortran Unit Test

For Fortran, we can use a simple approach to test the program by redirecting the output to a file and then comparing the file content with the expected output.

1. **Fortran Code (`DRB059_lastprivate_orig_no.f90`)**:

```fortran
program DRB059_lastprivate_orig_no
    use omp_lib
    implicit none
    !$omp parallel
    call foo()
    !$omp end parallel
contains
    subroutine foo()
        integer :: i, x
        !$omp parallel do private(i) lastprivate(x)
        do i = 1, 100
            x = i
        end do
        !$omp end parallel do
        print 100, x
        100 format ("x =",i3)
    end subroutine foo
end program
```

2. **Fortran Unit Test Script (`test_fortran.sh`)**:

```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp DRB059_lastprivate_orig_no.f90 -o DRB059_lastprivate_orig_no

# Run the program and redirect output to a file
./DRB059_lastprivate_orig_no > output.txt

# Expected output
EXPECTED_OUTPUT="x =100"

# Read output from file
read -r OUTPUT < output.txt

# Check if output matches expected output
if [ "$OUTPUT" == "$EXPECTED_OUTPUT" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
    echo "Expected: '$EXPECTED_OUTPUT'"
    echo "Got: '$OUTPUT'"
fi
```

### C++ Unit Test

For C++, we can use a similar approach to test the program by redirecting the output to a file and comparing the file content with the expected output.

1. **C++ Code (`DRB059_lastprivate_orig_no.cpp`)**:

```cpp
#include <iostream>
#include <omp.h>

void foo();

int main() {
    #pragma omp parallel
    {
        foo(); // Call the subroutine
    }

    return 0;
}

void foo() {
    int x = 0; // Initialize x to 0

    #pragma omp parallel for private(i) lastprivate(x)
    for (int i = 1; i <= 100; ++i) {
        x = i; // Update x with the value of i
    }

    // Print the value of x
    std::cout << "x = " << x << std::endl;
}
```

2. **C++ Unit Test Script (`test_cpp.sh`)**:

```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp DRB059_lastprivate_orig_no.cpp -o DRB059_lastprivate_orig_no

# Run the program and redirect output to a file
./DRB059_lastprivate_orig_no > output.txt

# Expected output
EXPECTED_OUTPUT="x =100"

# Read output from file
read -r OUTPUT < output.txt

# Check if output matches expected output
if [ "$OUTPUT" == "$EXPECTED_OUTPUT" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
    echo "Expected: '$EXPECTED_OUTPUT'"
    echo "Got: '$OUTPUT'"
fi
```

### Running the Tests

1. **Fortran Test**:
   - Save the Fortran code in a file named `DRB059_lastprivate_orig_no.f90`.
   - Save the Fortran test script in a file named `test_fortran.sh`.
   - Make the test script executable: `chmod +x test_fortran.sh`.
   - Run the test script: `./test_fortran.sh`.

2. **C++ Test**:
   - Save the C++ code in a file named `DRB059_lastprivate_orig_no.cpp`.
   - Save the C++ test script in a file named `test_cpp.sh`.
   - Make the test script executable: `chmod +x test_cpp.sh`.
   - Run the test script: `./test_cpp.sh`.

Both scripts will compile the respective programs, run them, and check if the output matches the expected result. If the output matches, the script will print that the test passed; otherwise, it will print that the test failed and show the expected and actual outputs.
