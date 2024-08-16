Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int numThreads = 0;

    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            numThreads = omp_get_num_threads();
        } else {
            std::cout << "numThreads = " << numThreads << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Declare the main function**:
   - This is the entry point of the C++ program.

3. **Initialize variables**:
   - `int numThreads = 0;` declares an integer variable `numThreads` and initializes it to 0.

4. **Parallel region**:
   - `#pragma omp parallel` is used to indicate that the following block of code should be executed in parallel.

5. **Check thread number**:
   - `if (omp_get_thread_num() == 0)` checks if the current thread is the master thread (thread 0 in C++).

6. **Update `numThreads`**:
   - If the current thread is the master thread, `numThreads` is set to the total number of threads in the parallel region using `omp_get_num_threads()`.

7. **Output**:
   - If the current thread is not the master thread, it prints the value of `numThreads`.

8. **Return statement**:
   - The `main` function returns 0, indicating successful execution.

This C++ code mirrors the functionality of the original Fortran code, using OpenMP for parallelism and checking the thread number to determine which thread should update `numThreads` and which threads should print the value of `numThreads`.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

To test the Fortran code, you can use a simple script that runs the program and checks the output. Here's an example using a shell script:

```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp -o DRB075_getthreadnum_orig_yes DRB075_getthreadnum_orig_yes.f90

# Run the Fortran code and capture the output
output=$(./DRB075_getthreadnum_orig_yes)

# Check the output
if [ "$output" == "numThreads = 1" ]; then
    echo "Test Passed"
else
    echo "Test Failed"
fi
```

### C++ Unit Test

To test the C++ code, you can use a similar shell script:

```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp -o DRB075_getthreadnum_orig_yes DRB075_getthreadnum_orig_yes.cpp

# Run the C++ code and capture the output
output=$(./DRB075_getthreadnum_orig_yes)

# Check the output
if [ "$output" == "numThreads = 1" ]; then
    echo "Test Passed"
else
    echo "Test Failed"
fi
```

### Explanation

1. **Shell Scripts**:
   - The shell scripts (`test_fortran.sh` and `test_cpp.sh`) are used to compile and run the respective programs.
   - They capture the output of the programs and compare it to the expected output (`numThreads = 1`).

2. **Compilation**:
   - `gfortran` and `g++` are used to compile the Fortran and C++ code, respectively. The `-fopenmp` flag is used to enable OpenMP support.

3. **Output Checking**:
   - If the output matches the expected output (`numThreads = 1`), the test passes; otherwise, it fails.

### Running the Tests

1. **Save the Fortran code** in a file named `DRB075_getthreadnum_orig_yes.f90`.
2. **Save the C++ code** in a file named `DRB075_getthreadnum_orig_yes.cpp`.
3. **Save the shell scripts** in files named `test_fortran.sh` and `test_cpp.sh` respectively.
4. **Make the shell scripts executable**:
   ```sh
   chmod +x test_fortran.sh
   chmod +x test_cpp.sh
   ```
5. **Run the shell scripts**:
   ```sh
   ./test_fortran.sh
   ./test_cpp.sh
   ```

If both tests print "Test Passed", then the translation is correct.
