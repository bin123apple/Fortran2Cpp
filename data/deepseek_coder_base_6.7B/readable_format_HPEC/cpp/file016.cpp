Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int i, x, len;
    len = 10000;

    #pragma omp parallel for private(i)
    for (i = 0; i <= len; ++i) {
        x = i;
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Declare variables**:
   - `int i, x, len;` declares integer variables.

3. **Initialize variables**:
   - `len = 10000;` sets the length of the loop.

4. **OpenMP parallel for loop**:
   - `#pragma omp parallel for private(i)` specifies that the loop should be parallelized and `i` should be private to each thread.
   - The loop runs from `0` to `len` (inclusive) and updates `x` with the current value of `i`.

5. **Output the result**:
   - `std::cout` is used to print the value of `x`.

This C++ code should produce the same output as the provided Fortran code. Note that the index `i` starts from `0` in C++ as opposed to `1` in Fortran.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

To test the Fortran code, you can use a simple script that runs the program and checks the output. Here is an example using a shell script and a Fortran compiler:

```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp -o DRB009_lastprivatemissing_orig_yes DRB009_lastprivatemissing_orig_yes.f90

# Run the Fortran code and capture the output
output=$(./DRB009_lastprivatemissing_orig_yes)

# Expected output
expected_output="x = 9999"

# Check if the output matches the expected output
if [ "$output" == "$expected_output" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
    echo "Expected: $expected_output"
    echo "Got: $output"
fi
```

### C++ Unit Test Code

To test the C++ code, you can use a similar shell script and a C++ compiler:

```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp -o DRB009_lastprivatemissing_orig_yes DRB009_lastprivatemissing_orig_yes.cpp

# Run the C++ code and capture the output
output=$(./DRB009_lastprivatemissing_orig_yes)

# Expected output
expected_output="x = 9999"

# Check if the output matches the expected output
if [ "$output" == "$expected_output" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
    echo "Expected: $expected_output"
    echo "Got: $output"
fi
```

### Explanation

1. **Shell Scripts**:
   - The shell scripts (`test_fortran.sh` and `test_cpp.sh`) are used to compile and run the respective programs.
   - They capture the output of the programs and compare it to the expected output.

2. **Compilation**:
   - `gfortran -fopenmp -o DRB009_lastprivatemissing_orig_yes DRB009_lastprivatemissing_orig_yes.f90` compiles the Fortran code.
   - `g++ -fopenmp -o DRB009_lastprivatemissing_orig_yes DRB009_lastprivatemissing_orig_yes.cpp` compiles the C++ code.

3. **Output Comparison**:
   - The script captures the output of the compiled programs using `$(./DRB009_lastprivatemissing_orig_yes)`.
   - It compares the captured output to the expected output (`"x = 9999"`) using `if [ "$output" == "$expected_output" ]`.
   - If the output matches the expected output, the script prints "Fortran test passed!" or "C++ test passed!". Otherwise, it prints "Fortran test failed!" or "C++ test failed!" along with the expected and actual outputs.

### Running the Tests

1. **Save the Fortran code** in a file named `DRB009_lastprivatemissing_orig_yes.f90`.
2. **Save the C++ code** in a file named `DRB009_lastprivatemissing_orig_yes.cpp`.
3. **Save the shell scripts** in files named `test_fortran.sh` and `test_cpp.sh` respectively.
4. **Make the shell scripts executable** by running `chmod +x test_fortran.sh test_cpp.sh`.
5. **Run the shell scripts** to execute the tests.

If both tests print "Fortran test passed!" and "C++ test passed!" respectively, then the translation is correct.
