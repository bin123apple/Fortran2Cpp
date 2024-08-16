Certainly! Below is the translated Fortran code to C++ using OpenMP for parallelism. Note that in C++, you need to include the OpenMP library and enable it using pragmas. The `sleep` function is not directly available in C++, so we'll simulate it using `std::this_thread::sleep_for` from the `<thread>` library.

```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <omp.h>

int main() {
    int result = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskgroup
            {
                #pragma omp task
                {
                    // Simulate sleep by sleeping for 3 seconds
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    result = 1;
                }
            }
            #pragma omp task
            result = 2;
        }
    }

    std::cout << "result = " << result << std::endl;

    return 0;
}
```

### Explanation:
1. **Include Libraries**: We include the necessary libraries for input/output and thread operations.
2. **Main Function**: The main function initializes the result variable.
3. **Parallel Region**: We start a parallel region using `#pragma omp parallel`.
4. **Single Region**: Inside the parallel region, we have a single region using `#pragma omp single`.
5. **Taskgroup**: Inside the single region, we have a taskgroup.
6. **Tasks**: Inside the taskgroup, we have two tasks. The first task sleeps for 3 seconds and then sets `result` to 1. The second task sets `result` to 2.

### Notes:
- **Sleep Function**: We simulate the `sleep` function by using `std::this_thread::sleep_for`.
- **OpenMP Pragmas**: The `#pragma omp` directives are used to parallelize the code using OpenMP.
- **Output**: The result is printed to the standard output.

Make sure to compile this C++ code with OpenMP support enabled. For example, if you're using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by ensuring that the program behaves as expected.

### Fortran Unit Test

For the Fortran code, we can use a simple script to compile and run the program, then check the output.

**Fortran Code (DRB107_taskgroup_orig_no.f90):**
```fortran
program DRB107_taskgroup_orig_no
    use omp_lib
    implicit none

    integer :: result
    result = 0

    !$omp parallel
    !$omp single
        !$omp taskgroup
            !$omp task
            call sleep(3)
            result = 1
            !$omp end task
        !$omp end taskgroup
        !$omp task
        result = 2
        !$omp end task
    !$omp end single
    !$omp end parallel

    print 100, result
    100 format ('result =',3i8)
end program
```

**Fortran Unit Test (test_fortran.sh):**
```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp DRB107_taskgroup_orig_no.f90 -o DRB107_taskgroup_orig_no

# Run the Fortran program and capture the output
output=$(./DRB107_taskgroup_orig_no)

# Check the output
if [ "$output" == "result =           2" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
fi
```

### C++ Unit Test

For the C++ code, we can use a similar approach to compile and run the program, then check the output.

**C++ Code (DRB107_taskgroup_orig_no.cpp):**
```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <omp.h>

int main() {
    int result = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskgroup
            {
                #pragma omp task
                {
                    // Simulate sleep by sleeping for 3 seconds
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    result = 1;
                }
            }
            #pragma omp task
            result = 2;
        }
    }

    std::cout << "result = " << result << std::endl;

    return 0;
}
```

**C++ Unit Test (test_cpp.sh):**
```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp DRB107_taskgroup_orig_no.cpp -o DRB107_taskgroup_orig_no

# Run the C++ program and capture the output
output=$(./DRB107_taskgroup_orig_no)

# Check the output
if [ "$output" == "result = 2" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
fi
```

### Running the Tests

1. **Fortran Test**:
   - Save the Fortran code in a file named `DRB107_taskgroup_orig_no.f90`.
   - Save the Fortran unit test script in a file named `test_fortran.sh`.
   - Make the script executable: `chmod +x test_fortran.sh`.
   - Run the script: `./test_fortran.sh`.

2. **C++ Test**:
   - Save the C++ code in a file named `DRB107_taskgroup_orig_no.cpp`.
   - Save the C++ unit test script in a file named `test_cpp.sh`.
   - Make the script executable: `chmod +x test_cpp.sh`.
   - Run the script: `./test_cpp.sh`.

These scripts will compile the respective programs, run them, and check if the output matches the expected result. If the output is correct, the script will print a message indicating that the test passed; otherwise, it will indicate that the test failed.
