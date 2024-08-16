To translate the given Fortran code to C++, we need to understand the structure and functionality of the original Fortran code and then replicate its behavior using C++ constructs. The Fortran code uses OpenMP for parallel processing and includes a critical section to update a shared variable `sum`. It also demonstrates the use of a thread-private variable `sum0`.

Here's how you can translate the Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

// Assuming the functionality of foo is defined elsewhere
extern void foo(int i);

int main() {
    const int len = 1000;
    long long sum = 0;
    long long sum1 = 0;

    #pragma omp parallel
    {
        long long sum0 = 0;
        #pragma omp for
        for (int i = 1; i <= len; ++i) {
            foo(i);
        }

        #pragma omp critical
        {
            sum += sum0;
        }
    }

    for (int i = 1; i <= len; ++i) {
        sum1 += i;
    }

    std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;

    return 0;
}
```

### Key Points:

1. **OpenMP Pragmas**: The `#pragma omp parallel` and `#pragma omp for` directives are used in C++ to parallelize the loop and specify that the variable `sum0` is private to each thread.

2. **Thread-Private Variable**: The variable `sum0` is declared within the parallel region and thus is private to each thread. This mimics the behavior of the Fortran code where `sum0` is thread-private.

3. **Critical Section**: The `#pragma omp critical` directive is used to ensure that only one thread at a time can update the shared variable `sum`.

4. **Function Call**: The `foo` function is assumed to be defined elsewhere in the C++ codebase. It's important to ensure that `foo` is correctly declared and defined in your C++ project.

5. **Loop and Summation**: The loop and summation logic are straightforward translations from Fortran to C++.

6. **Output**: The final sum is printed to the standard output using `std::cout`.

Make sure to compile the C++ code with OpenMP support enabled. For example, if you are using GCC, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```

This will enable OpenMP in your C++ compiler, allowing the parallel sections to be executed.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the functionality of the `foo` function and the overall logic of summing numbers. For simplicity, let's assume that `foo` simply adds its input to a global variable, which we'll reset before each test.

### Fortran Unit Test

First, we'll modify the original Fortran program to include a simple test for the functionality of `foo` and the overall logic.

```fortran
module DRB085
    implicit none
    integer(kind=8) :: sum0 = 0
contains
    subroutine foo(i)
        integer(kind=8), intent(in) :: i
        sum0 = sum0 + i
    end subroutine foo
end module DRB085

program DRB085_threadprivate_orig_no
    use omp_lib
    use DRB085
    implicit none

    integer :: len
    integer(kind=8) :: i, sum
    len = 1000
    sum = 0

    !$omp parallel private(i)
        !$omp do
        do i = 1, len
            call foo(i)
        end do
        !$omp end do
        !$omp critical
        sum = sum + sum0
        !$omp end critical
    !$omp end parallel

    print*, 'sum = ', sum
end program
```

### C++ Unit Test

Similarly, we'll modify the C++ code to include a simple test for the functionality of `foo` and the overall logic.

```cpp
#include <iostream>
#include <omp.h>

long long sum0 = 0;

void foo(int i) {
    sum0 += i;
}

int main() {
    const int len = 1000;
    long long sum = 0;

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 1; i <= len; ++i) {
            foo(i);
        }

        #pragma omp critical
        {
            sum += sum0;
        }
    }

    std::cout << "sum = " << sum << std::endl;

    return 0;
}
```

### Testing Procedure

1. **Reset Global Variables**: Before running each test, reset the `sum0` variable to zero. This ensures that the test starts with a clean slate.

2. **Run the Program**: Execute the modified Fortran and C++ programs.

3. **Verify Output**: The output of both programs should be the same, which confirms that the functionality of `foo` and the overall logic are correct.

### Fortran Test Script

You can use a shell script to compile and run the Fortran test.

```sh
#!/bin/bash

# Compile the Fortran program
gfortran -fopenmp -o DRB085_test DRB085_threadprivate_orig_no.f90

# Run the Fortran program and capture the output
output=$(./DRB085_test)

# Expected sum
expected_sum=500500

# Extract the actual sum from the output
actual_sum=$(echo $output | grep -oP 'sum = \K[0-9]+')

# Check if the actual sum matches the expected sum
if [ "$actual_sum" -eq "$expected_sum" ]; then
    echo "Fortran test passed!"
else
    echo "Fortran test failed!"
fi
```

### C++ Test Script

You can use a similar shell script to compile and run the C++ test.

```sh
#!/bin/bash

# Compile the C++ program
g++ -fopenmp -o DRB085_test_cpp DRB085_threadprivate_orig_no.cpp

# Run the C++ program and capture the output
output=$(./DRB085_test_cpp)

# Expected sum
expected_sum=500500

# Extract the actual sum from the output
actual_sum=$(echo $output | grep -oP 'sum = \K[0-9]+')

# Check if the actual sum matches the expected sum
if [ "$actual_sum" -eq "$expected_sum" ]; then
    echo "C++ test passed!"
else
    echo "C++ test failed!"
fi
```

### Running the Tests

1. **Save the Fortran code** in a file named `DRB085_threadprivate_orig_no.f90`.
2. **Save the C++ code** in a file named `DRB085_threadprivate_orig_no.cpp`.
3. **Save the Fortran test script** in a file named `test_fortran.sh` and make it executable (`chmod +x test_fortran.sh`).
4. **Save the C++ test script** in a file named `test_cpp.sh` and make it executable (`chmod +x test_cpp.sh`).

Run the test scripts:

```sh
./test_fortran.sh
./test_cpp.sh
```

If both tests print "Fortran test passed!" and "C++ test passed!" respectively, then the translation is verified to be correct.
