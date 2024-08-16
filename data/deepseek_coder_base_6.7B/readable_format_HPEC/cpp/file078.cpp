To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code, then implement similar functionality using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for parallelism and locking to increment a variable across threads. Here's how you can translate it to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int var = 0;
    omp_lock_t lck;
    omp_init_lock(&lck);

    #pragma omp target map(tofrom:var) device(0)
    {
        #pragma omp teams distribute parallel for
        for (int i = 1; i <= 10; ++i) {
            omp_set_lock(&lck);
            var = var + 1;
            omp_unset_lock(&lck);
        }
    }

    omp_destroy_lock(&lck);

    std::cout << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP and iostream**:
   - `#include <omp.h>`: This is the header file that contains the OpenMP API.
   - `#include <iostream>`: This is the header file that contains the definition of `std::cout`.

2. **Main Function**:
   - The `main` function is the entry point of the C++ program.

3. **Variable Declaration**:
   - `int var = 0;`: This declares an integer variable `var` and initializes it to 0.

4. **Lock Declaration**:
   - `omp_lock_t lck;`: This declares a lock variable.

5. **Lock Initialization**:
   - `omp_init_lock(&lck);`: This initializes the lock.

6. **Target Directive**:
   - `#pragma omp target map(tofrom:var) device(0)`: This directive specifies that the following block of code should be offloaded to a target device (in this case, the first device available). The `map(tofrom:var)` clause specifies that `var` should be made available for offloading.

7. **Teams Distribute Parallel For**:
   - `#pragma omp teams distribute parallel for`: This directive specifies that the loop should be parallelized across teams, with each team distributing the iterations of the loop across its threads.

8. **Loop and Locking**:
   - The loop runs from 1 to 10, and within the loop, the lock is set, `var` is incremented, and the lock is released.

9. **Lock Destruction**:
   - `omp_destroy_lock(&lck);`: This destroys the lock.

10. **Printing the Result**:
   - `std::cout << var << std::endl;`: This prints the value of `var` to the standard output.

### Compilation:
To compile this C++ program with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp your_program.cpp -o your_program
```

Replace `your_program.cpp` with the name of your C++ source file.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create simple unit tests. These tests will run the programs and check if the output is as expected.

### Fortran Unit Test

To test the Fortran code, you can create a shell script that compiles and runs the Fortran program, then checks the output. Here's an example:

```sh
#!/bin/bash

# Compile the Fortran program
gfortran -fopenmp -o DRB150_missinglock1_orig_gpu_yes DRB150_missinglock1_orig_gpu_yes.f90

# Run the Fortran program and capture the output
output=$(./DRB150_missinglock1_orig_gpu_yes)

# Check the output
if [ "$output" -eq "10" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
fi
```

### C++ Unit Test

To test the C++ code, you can create a similar shell script that compiles and runs the C++ program, then checks the output.

```sh
#!/bin/bash

# Compile the C++ program
g++ -fopenmp -o DRB150_missinglock1_orig_gpu_yes_cpp DRB150_missinglock1_orig_gpu_yes.cpp

# Run the C++ program and capture the output
output=$(./DRB150_missinglock1_orig_gpu_yes_cpp)

# Check the output
if [ "$output" -eq "10" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
fi
```

### Explanation

1. **Shell Scripts**:
   - Each shell script is a simple bash script that compiles and runs the respective program, then checks if the output is as expected.

2. **Compilation**:
   - `gfortran -fopenmp -o DRB150_missinglock1_orig_gpu_yes DRB150_missinglock1_orig_gpu_yes.f90`: Compiles the Fortran program.
   - `g++ -fopenmp -o DRB150_missinglock1_orig_gpu_yes_cpp DRB150_missinglock1_orig_gpu_yes.cpp`: Compiles the C++ program.

3. **Execution and Checking**:
   - `output=$(./DRB150_missinglock1_orig_gpu_yes)`: Runs the Fortran program and captures its output.
   - `output=$(./DRB150_missinglock1_orig_gpu_yes_cpp)`: Runs the C++ program and captures its output.
   - `if [ "$output" -eq "10" ]; then`: Checks if the output is `10`. If the output is correct, it prints a success message; otherwise, it prints a failure message.

### Running the Tests

1. **Save** the Fortran code in a file named `DRB150_missinglock1_orig_gpu_yes.f90`.
2. **Save** the C++ code in a file named `DRB150_missinglock1_orig_gpu_yes.cpp`.
3. **Save** the Fortran test script in a file named `test_fortran.sh` and make it executable (`chmod +x test_fortran.sh`).
4. **Save** the C++ test script in a file named `test_cpp.sh` and make it executable (`chmod +x test_cpp.sh`).

Run the test scripts:

```sh
./test_fortran.sh
./test_cpp.sh
```

If both tests print "Fortran test passed!" and "C++ test passed!" respectively, then the translation is correct.
