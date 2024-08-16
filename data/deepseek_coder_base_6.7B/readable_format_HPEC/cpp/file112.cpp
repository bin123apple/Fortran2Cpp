Certainly! Below is the equivalent C++ code for the provided Fortran code. This C++ code uses OpenMP for parallelism, similar to the Fortran code.

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int k;

    #pragma omp parallel
    {
        #pragma omp master
        {
            k = omp_get_num_threads();
            std::cout << "Number of threads requested = " << k << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functions and pragmas.

2. **Main function**:
   - Declares an integer variable `k`.

3. **OpenMP parallel region**:
   - The `#pragma omp parallel` directive starts a parallel region.

4. **OpenMP master directive**:
   - Inside the parallel region, the `#pragma omp master` directive ensures that the code inside it is executed by the master thread only.

5. **Get number of threads**:
   - Inside the master region, `k` is set to the number of threads requested by the program.

6. **Print the result**:
   - The number of threads is printed to the standard output.

### Compilation:
To compile this C++ code with OpenMP support, you need to enable OpenMP in your compiler. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp -o DRB103_master_orig_no DRB103_master_orig_no.cpp
```

This will compile the C++ code and enable OpenMP support, allowing the program to run in parallel.
Let's write some test to verify if the translation is correct. 
Below are the executable unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by checking if the number of threads printed matches the expected value.

### Fortran Unit Test Code

Save the following Fortran code in a file named `test_DRB103_master_orig_no.f90`:

```fortran
program test_DRB103_master_orig_no
    use omp_lib
    implicit none

    integer :: k
    integer :: expected_num_threads

    ! Get the expected number of threads
    expected_num_threads = omp_get_max_threads()

    !$omp parallel
    !$omp master
    k = omp_get_num_threads()
    !$omp end master
    !$omp end parallel

    ! Check if the number of threads matches the expected value
    if (k == expected_num_threads) then
        print *, "Test Passed: Number of threads = ", k
    else
        print *, "Test Failed: Number of threads = ", k, " Expected = ", expected_num_threads
    end if

end program test_DRB103_master_orig_no
```

### C++ Unit Test Code

Save the following C++ code in a file named `test_DRB103_master_orig_no.cpp`:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int k;
    int expected_num_threads = omp_get_max_threads();

    #pragma omp parallel
    {
        #pragma omp master
        {
            k = omp_get_num_threads();
        }
    }

    // Check if the number of threads matches the expected value
    if (k == expected_num_threads) {
        std::cout << "Test Passed: Number of threads = " << k << std::endl;
    } else {
        std::cout << "Test Failed: Number of threads = " << k << " Expected = " << expected_num_threads << std::endl;
    }

    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran code, use the following commands:

```sh
gfortran -fopenmp test_DRB103_master_orig_no.f90 -o test_DRB103_master_orig_no
./test_DRB103_master_orig_no
```

#### C++

To compile and run the C++ code, use the following commands:

```sh
g++ -fopenmp test_DRB103_master_orig_no.cpp -o test_DRB103_master_orig_no
./test_DRB103_master_orig_no
```

### Expected Output

For both the Fortran and C++ programs, the expected output should be:

```
Test Passed: Number of threads = <number of threads requested>
```

This output verifies that the number of threads printed matches the expected number of threads available in the system. If the number of threads printed does not match the expected value, the test will fail.
