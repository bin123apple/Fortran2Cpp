Certainly! Below is the translated Fortran code to C++. Note that OpenMP directives in Fortran and C++ are somewhat different, especially when it comes to targeting specific devices (GPUs). However, the parallel loop structure is similar in both languages.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for
        for (int i = 1; i <= 100; ++i) {
            #pragma omp atomic
            var += 1;
        }
    }

    std::cout << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library.
2. **Main Function**: The main function in C++ is defined as `int main()`.
3. **Variable Declaration**: The variable `var` is declared as an integer and initialized to 0.
4. **OpenMP Directives**:
   - `#pragma omp target map(tofrom:var) device(0)`: This directive specifies that the variable `var` should be mapped to and from the target device (GPU in this case). The `device(0)` specifies the device index.
   - `#pragma omp teams distribute parallel for`: This directive parallelizes the loop across teams, distributing the iterations among the threads.
   - `#pragma omp atomic`: This directive ensures that the operation on `var` is atomic, which is necessary for correct synchronization when multiple threads try to access and modify `var`.
5. **Loop**: The loop runs from 1 to 100, similar to the Fortran code.
6. **Output**: The final value of `var` is printed to the standard output.

### Notes:
- Ensure you compile the C++ code with an OpenMP-supporting compiler and enable OpenMP support (e.g., by using the `-fopenmp` flag with GCC or Clang).
- The specifics of the `device(0)` directive might vary depending on the compiler and the setup of the system. Adjust the device index as necessary.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by checking if the final value of the variable `var` is 100.

### Fortran Unit Test

For the Fortran code, you can use a simple script to compile and run the program, then check the output. Here is an example using a shell script and a Fortran compiler (e.g., gfortran):

```sh
#!/bin/bash

# Save this script as test_fortran.sh and make it executable
# Compile the Fortran code
gfortran -fopenmp -o test_fortran DRB151_missinglock3_orig_gpu_yes.f90

# Run the compiled program and capture the output
output=$(./test_fortran)

# Check the output
if [ "$output" -eq "100" ]; then
    echo "Test passed!"
else
    echo "Test failed!"
fi
```

### C++ Unit Test

For the C++ code, you can use a similar approach with a shell script and a C++ compiler (e.g., g++):

```sh
#!/bin/bash

# Save this script as test_cpp.sh and make it executable
# Compile the C++ code
g++ -fopenmp -o test_cpp DRB151_missinglock3_orig_gpu_yes.cpp

# Run the compiled program and capture the output
output=$(./test_cpp)

# Check the output
if [ "$output" -eq "100" ]; then
    echo "Test passed!"
else
    echo "Test failed!"
fi
```

### Explanation

1. **Shell Scripts**:
   - `test_fortran.sh`: This script compiles the Fortran code and runs it, then checks if the output is `100`.
   - `test_cpp.sh`: This script compiles the C++ code and runs it, then checks if the output is `100`.

2. **Compilation**:
   - `gfortran -fopenmp -o test_fortran DRB151_missinglock3_orig_gpu_yes.f90`: Compiles the Fortran code with OpenMP support.
   - `g++ -fopenmp -o test_cpp DRB151_missinglock3_orig_gpu_yes.cpp`: Compiles the C++ code with OpenMP support.

3. **Execution and Check**:
   - `output=$(./test_fortran)`: Executes the Fortran program and captures its output.
   - `output=$(./test_cpp)`: Executes the C++ program and captures its output.
   - `if [ "$output" -eq "100" ]; then`: Checks if the output is `100`. If so, it prints "Test passed!"; otherwise, it prints "Test failed!".

### Running the Tests

1. Save the Fortran code in a file named `DRB151_missinglock3_orig_gpu_yes.f90`.
2. Save the C++ code in a file named `DRB151_missinglock3_orig_gpu_yes.cpp`.
3. Save the shell scripts as mentioned above.
4. Make the shell scripts executable: `chmod +x test_fortran.sh test_cpp.sh`.
5. Run the shell scripts: `./test_fortran.sh` and `./test_cpp.sh`.

If both tests print "Test passed!" then the translation is correct.
