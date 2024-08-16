Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp parallel sections
    {
        for (int i = 1; i <= 10; ++i) {
            #pragma omp task shared(var)
            {
                var = var + 1;
            }
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functions and pragmas.

2. **Main function**:
   - Initializes the variable `var` to 0.

3. **Parallel sections**:
   - Uses the `#pragma omp parallel sections` directive to parallelize the sections.
   - Inside the parallel sections, a `for` loop iterates from 1 to 10.

4. **Tasks**:
   - Each iteration of the loop creates a task using the `#pragma omp task shared(var)` directive.
   - Inside the task, `var` is incremented by 1.

5. **Output**:
   - After the parallel sections, the value of `var` is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command like:
```sh
g++ -fopenmp -o DRB123_taskundeferred_orig_yes DRB123_taskundeferred_orig_yes.cpp
```

This command tells the compiler to enable OpenMP (`-fopenmp`) and generates an executable named `DRB123_taskundeferred_orig_yes`.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

To create a unit test for the Fortran code, you can use a simple script that runs the program and checks the output. Here is an example using a shell script:

```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp -o DRB123_taskundeferred_orig_yes DRB123_taskundeferred_orig_yes.f90

# Run the Fortran code and capture the output
output=$(./DRB123_taskundeferred_orig_yes)

# Expected output
expected_output="var = 10"

# Check if the output matches the expected output
if [ "$output" == "$expected_output" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
    echo "Expected: $expected_output"
    echo "Got: $output"
fi
```

### C++ Unit Test

To create a unit test for the C++ code, you can use a similar shell script:

```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp -o DRB123_taskundeferred_orig_yes DRB123_taskundeferred_orig_yes.cpp

# Run the C++ code and capture the output
output=$(./DRB123_taskundeferred_orig_yes)

# Expected output
expected_output="var = 10"

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
   - Each script compiles the respective Fortran or C++ code with OpenMP support.
   - It then runs the compiled program and captures its output.
   - The output is compared against the expected output.

2. **Output Comparison**:
   - If the output matches the expected output, the script prints that the test passed.
   - If the output does not match the expected output, the script prints that the test failed and prints the expected and actual outputs.

### Running the Tests

1. **Fortran Test**:
   - Save the Fortran code in a file named `DRB123_taskundeferred_orig_yes.f90`.
   - Save the shell script in a file named `test_fortran.sh`.
   - Make the shell script executable: `chmod +x test_fortran.sh`.
   - Run the shell script: `./test_fortran.sh`.

2. **C++ Test**:
   - Save the C++ code in a file named `DRB123_taskundeferred_orig_yes.cpp`.
   - Save the shell script in a file named `test_cpp.sh`.
   - Make the shell script executable: `chmod +x test_cpp.sh`.
   - Run the shell script: `./test_cpp.sh`.

If both tests print "Fortran test passed!" and "C++ test passed!" respectively, then the translation is correct.
