Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                i = 1;
            }
            #pragma omp task
            {
                i = 2;
            }
        }
    }

    std::cout << "i=" << i << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Main function**:
   - Declare the integer variable `i` and initialize it to 0.

3. **OpenMP parallel region**:
   - Use `#pragma omp parallel` to start a parallel region.

4. **OpenMP single directive**:
   - Use `#pragma omp single` to ensure that the enclosed block is executed by only one thread in the team.

5. **OpenMP task directives**:
   - Use `#pragma omp task` to offload the execution of the enclosed block to a task.

6. **Assignments to `i`**:
   - Inside the task blocks, assign `i` to 1 or 2.

7. **Output**:
   - Use `std::cout` to print the value of `i`.

This C++ code should exhibit the same behavior as the original Fortran code, with the addition of OpenMP directives for parallelism.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

To test the Fortran code, you can use a simple script that runs the program and checks the output.

#### Fortran Code (`DRB027_taskdependmissing_orig_yes.f90`)
```fortran
program DRB027_taskdependmissing_orig_yes
    use omp_lib
    implicit none

    integer :: i
    i=0

    !$omp parallel
    !$omp single
    !$omp task
    i = 1
    !$omp end task
    !$omp task
    i = 2
    !$omp end task
    !$omp end single
    !$omp end parallel

    print 100, i
    100 format ("i=",i3)

end program
```

#### Fortran Unit Test Script (`test_fortran.sh`)
```sh
#!/bin/bash

# Compile the Fortran code
gfortran -fopenmp DRB027_taskdependmissing_orig_yes.f90 -o DRB027_taskdependmissing_orig_yes

# Run the Fortran program and capture the output
output=$(./DRB027_taskdependmissing_orig_yes)

# Expected output
expected_output="i= 2"

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

To test the C++ code, you can use a similar approach with a script to compile and run the program and check the output.

#### C++ Code (`DRB027_taskdependmissing_orig_yes.cpp`)
```cpp
#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                i = 1;
            }
            #pragma omp task
            {
                i = 2;
            }
        }
    }

    std::cout << "i=" << i << std::endl;

    return 0;
}
```

#### C++ Unit Test Script (`test_cpp.sh`)
```sh
#!/bin/bash

# Compile the C++ code
g++ -fopenmp DRB027_taskdependmissing_orig_yes.cpp -o DRB027_taskdependmissing_orig_yes

# Run the C++ program and capture the output
output=$(./DRB027_taskdependmissing_orig_yes)

# Expected output
expected_output="i= 2"

# Check if the output matches the expected output
if [ "$output" == "$expected_output" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
    echo "Expected: $expected_output"
    echo "Got: $output"
fi
```

### Running the Tests

1. **Fortran Test**:
   - Save the Fortran code in a file named `DRB027_taskdependmissing_orig_yes.f90`.
   - Save the Fortran unit test script in a file named `test_fortran.sh`.
   - Make the script executable: `chmod +x test_fortran.sh`.
   - Run the script: `./test_fortran.sh`.

2. **C++ Test**:
   - Save the C++ code in a file named `DRB027_taskdependmissing_orig_yes.cpp`.
   - Save the C++ unit test script in a file named `test_cpp.sh`.
   - Make the script executable: `chmod +x test_cpp.sh`.
   - Run the script: `./test_cpp.sh`.

Both scripts will compile the respective programs, run them, and check if the output matches the expected value of `i=2`. If the output is correct, the script will print a success message; otherwise, it will print a failure message along with the expected and actual outputs.
