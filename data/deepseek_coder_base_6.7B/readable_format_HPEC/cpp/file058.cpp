Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<double> a(len);

    for (int i = 0; i < len; ++i) {
        a[i] = static_cast<double>(i + 1) / 2.0;
    }

    #pragma omp target map(tofrom: a[0:len])
    {
        #pragma omp teams num_teams(2)
        {
            a[49] = a[49] * 2.0; // Note: C++ uses 0-based indexing
        }
    }

    std::cout << "a[49]=" << a[49] << std::endl; // 49 is the index for the 50th element in Fortran

    return 0;
}
```

### Explanation:
1. **Vector Initialization**:
   - In C++, we use `std::vector<double>` to dynamically allocate an array of doubles.
   - The size of the vector is set to `len`.

2. **Loop to Populate Vector**:
   - The loop fills the vector `a` with values using the formula `(i + 1) / 2.0`.
   - Note that C++ uses 0-based indexing, so the loop starts from 0 and goes up to `len - 1`.

3. **OpenMP Directives**:
   - `#pragma omp target map(tofrom: a[0:len])` specifies that the array `a` should be mapped to and from the target device.
   - `#pragma omp teams num_teams(2)` specifies that two teams should be created.
   - Inside the teams, the element at index 49 (Fortran's 50th element) is multiplied by 2.0.

4. **Printing the Result**:
   - The value of `a[49]` is printed to the standard output, which corresponds to the Fortran's 50th element.

### Notes:
- The `#include <omp.h>` directive is used to include the OpenMP library.
- The `#pragma` directives are used to specify OpenMP directives.
- The `std::vector` is used to manage the dynamic array, which is automatically deallocated when it goes out of scope.
- Remember to compile this C++ code with an OpenMP-capable compiler, such as `g++`, and enable OpenMP support with the `-fopenmp` flag.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

To create a unit test for the Fortran code, you can use a simple script that runs the program and checks the output. Here is an example using a shell script and a Fortran compiler:

```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp -o DRB116_target_teams_orig_yes DRB116_target_teams_orig_yes.f90

# Run the Fortran code and capture the output
output=$(./DRB116_target_teams_orig_yes)

# Check the output
expected_output=" a(50)= 2.0000000000000000"

if [ "$output" == "$expected_output" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
    echo "Expected: '$expected_output'"
    echo "Got: '$output'"
fi
```

### C++ Unit Test

To create a unit test for the C++ code, you can use a similar approach with a shell script and a C++ compiler:

```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp -o DRB116_target_teams_orig_yes DRB116_target_teams_orig_yes.cpp

# Run the C++ code and capture the output
output=$(./DRB116_target_teams_orig_yes)

# Check the output
expected_output="a[49]=2"

if [ "$output" == "$expected_output" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
    echo "Expected: '$expected_output'"
    echo "Got: '$output'"
fi
```

### Explanation

1. **Shell Scripts**:
   - The shell scripts (`test_fortran.sh` and `test_cpp.sh`) are used to compile and run the respective programs.
   - They capture the output of the program and compare it to the expected output.

2. **Compilation**:
   - The Fortran code is compiled with `gfortran` and the C++ code is compiled with `g++`.
   - The `-fopenmp` flag is used to enable OpenMP support.

3. **Output Comparison**:
   - The script checks if the actual output matches the expected output.
   - If the outputs match, the script prints that the test passed; otherwise, it prints that the test failed.

### Running the Tests

1. **Fortran Test**:
   - Save the Fortran code in a file named `DRB116_target_teams_orig_yes.f90`.
   - Save the Fortran test script in a file named `test_fortran.sh`.
   - Make the script executable: `chmod +x test_fortran.sh`.
   - Run the script: `./test_fortran.sh`.

2. **C++ Test**:
   - Save the C++ code in a file named `DRB116_target_teams_orig_yes.cpp`.
   - Save the C++ test script in a file named `test_cpp.sh`.
   - Make the script executable: `chmod +x test_cpp.sh`.
   - Run the script: `./test_cpp.sh`.

These tests will verify that the translation from Fortran to C++ is correct by comparing the outputs of both programs.
