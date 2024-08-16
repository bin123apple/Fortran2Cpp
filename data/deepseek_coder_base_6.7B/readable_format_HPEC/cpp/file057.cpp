Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int n = 1000;
    const int m = 1000;
    std::vector<std::vector<float>> b(n, std::vector<float>(m));

    // Initialize the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = 0.5f;
        }
    }

    // Parallel region
    #pragma omp parallel for collapse(2) private(j)
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            b[i][j] = b[i-1][j-1];
        }
    }

    // Print the value at b[500][500]
    std::cout << "b[500][500] = " << b[500][500] << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `<iostream>` for input/output operations.
   - `<vector>` for dynamic arrays.
   - `<omp.h>` for OpenMP support.

2. **Define constants**:
   - `n` and `m` are set to 1000, similar to the Fortran code.

3. **Create a 2D vector**:
   - `std::vector<std::vector<float>> b(n, std::vector<float>(m))` creates a 2D vector with `n` rows and `m` columns.

4. **Initialize the matrix**:
   - A nested loop initializes all elements of the matrix to 0.5.

5. **Parallel region**:
   - The parallel region is created using `#pragma omp parallel for collapse(2) private(j)`.
   - The `collapse(2)` directive is used to collapse the nested loops into a single parallel loop.
   - The `private(j)` clause ensures that each thread has its own instance of `j`.

6. **Update the matrix**:
   - The nested loop updates the matrix elements similar to the Fortran code.

7. **Print the result**:
   - The value at `b[500][500]` is printed to the console.

8. **Return 0**:
   - The program ends by returning 0.

### Compilation:
To compile this C++ program with OpenMP support, you can use a command similar to the following:

```sh
g++ -fopenmp -o DRB031_truedepfirstdimension_orig_yes DRB031_truedepfirstdimension_orig_yes.cpp
```

This command tells the compiler to enable OpenMP support (`-fopenmp`) and generates an executable named `DRB031_truedepfirstdimension_orig_yes`.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

To create a unit test for the Fortran code, you can use a simple script that runs the program and checks the output. Here is an example using a shell script and a Fortran compiler:

```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp -o DRB031_truedepfirstdimension_orig_yes DRB031_truedepfirstdimension_orig_yes.f90

# Run the Fortran code and capture the output
output=$(./DRB031_truedepfirstdimension_orig_yes)

# Check the output
expected_output="b(500,500) =  0.500000"

if [ "$output" == "$expected_output" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
    echo "Expected: $expected_output"
    echo "Got: $output"
fi
```

### C++ Unit Test

To create a unit test for the C++ code, you can use a similar approach with a shell script and a C++ compiler:

```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp -o DRB031_truedepfirstdimension_orig_yes DRB031_truedepfirstdimension_orig_yes.cpp

# Run the C++ code and capture the output
output=$(./DRB031_truedepfirstdimension_orig_yes)

# Check the output
expected_output="b[500][500] = 0.5"

if [ "$output" == "$expected_output" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
    echo "Expected: $expected_output"
    echo "Got: $output"
fi
```

### Explanation:

1. **Shell Scripts**:
   - The shell scripts are used to compile and run the Fortran and C++ programs.
   - They capture the output of the programs and compare it to the expected output.

2. **Output Comparison**:
   - The expected output is set based on the Fortran program's output format.
   - If the actual output matches the expected output, the test passes; otherwise, it fails.

### Running the Tests

1. **Fortran Test**:
   - Save the Fortran code in a file named `DRB031_truedepfirstdimension_orig_yes.f90`.
   - Save the shell script in a file named `test_fortran.sh` and make it executable (`chmod +x test_fortran.sh`).
   - Run the script: `./test_fortran.sh`.

2. **C++ Test**:
   - Save the C++ code in a file named `DRB031_truedepfirstdimension_orig_yes.cpp`.
   - Save the shell script in a file named `test_cpp.sh` and make it executable (`chmod +x test_cpp.sh`).
   - Run the script: `./test_cpp.sh`.

If both tests print "Fortran test passed!" and "C++ test passed!" respectively, then the translation is correct.
