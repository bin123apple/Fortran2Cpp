To translate the given Fortran code to C++, we need to understand the functionality of the original code and then implement similar behavior using C++ syntax and OpenMP API. The Fortran code demonstrates the use of OpenMP for parallel sections, lock management, and variable synchronization.

Here's how you can translate the Fortran code to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    omp_lock_t lock;
    int i = 0;

    omp_init_lock(&lock);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            omp_set_lock(&lock);
            i = i + 1;
            omp_unset_lock(&lock);
        }
        #pragma omp section
        {
            omp_set_lock(&lock);
            i = i + 2;
            omp_unset_lock(&lock);
        }
    }

    omp_destroy_lock(&lock);

    std::cout << "I = " << i << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP and iostream**:
   - `#include <omp.h>`: This is the header file that contains the OpenMP API.
   - `#include <iostream>`: This is the header file for input and output operations.

2. **Main Function**:
   - `int main()`: The main function is the entry point of the C++ program.

3. **Lock Declaration**:
   - `omp_lock_t lock;`: This declares a lock variable.
   - `int i = 0;`: This declares an integer variable `i` and initializes it to 0.

4. **Lock Initialization**:
   - `omp_init_lock(&lock);`: This initializes the lock.

5. **Parallel Sections**:
   - `#pragma omp parallel sections`: This directive starts a parallel section block.
   - `#pragma omp section`: This directive defines a section within the parallel section block.
   - `omp_set_lock(&lock);`: This acquires the lock.
   - `i = i + 1;`: This increments `i` by 1.
   - `omp_unset_lock(&lock);`: This releases the lock.

6. **Lock Destruction**:
   - `omp_destroy_lock(&lock);`: This destroys the lock.

7. **Output**:
   - `std::cout << "I = " << i << std::endl;`: This prints the value of `i`.

### Compilation:
To compile this C++ code with OpenMP support, you need to use the `-fopenmp` flag with your compiler. For example, if you are using `g++`, the command would be:

```sh
g++ -fopenmp -o program program.cpp
```

Replace `program.cpp` with the name of your C++ source file.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create unit tests. For simplicity, the tests will check if the final value of `i` is as expected after the parallel sections.

### Fortran Unit Test

To test the Fortran code, we can create a simple test program that includes the original code and checks the value of `i` after the parallel sections.

```fortran
program test_DRB069_sectionslock1_orig_no
    use omp_lib
    implicit none

    integer (kind=omp_lock_kind) lock
    integer :: i
    integer :: expected_i

    i = 0
    call omp_init_lock(lock)

    !$omp parallel sections
        !$omp section
        call omp_set_lock(lock)
        i = i + 1
        call omp_unset_lock(lock)
        !$omp section
        call omp_set_lock(lock)
        i = i + 2
        call omp_unset_lock(lock)
    !$omp end parallel sections

    call omp_destroy_lock(lock)

    expected_i = 3
    if (i == expected_i) then
        print *, "Test Passed: I =", i
    else
        print *, "Test Failed: I =", i, "Expected:", expected_i
    end if
end program test_DRB069_sectionslock1_orig_no
```

### C++ Unit Test

For the C++ code, we can use a simple test function that includes the translated code and checks the value of `i` after the parallel sections.

```cpp
#include <omp.h>
#include <iostream>

bool test_sections_lock() {
    omp_lock_t lock;
    int i = 0;

    omp_init_lock(&lock);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            omp_set_lock(&lock);
            i = i + 1;
            omp_unset_lock(&lock);
        }
        #pragma omp section
        {
            omp_set_lock(&lock);
            i = i + 2;
            omp_unset_lock(&lock);
        }
    }

    omp_destroy_lock(&lock);

    int expected_i = 3;
    if (i == expected_i) {
        std::cout << "Test Passed: I = " << i << std::endl;
        return true;
    } else {
        std::cout << "Test Failed: I = " << i << " Expected: " << expected_i << std::endl;
        return false;
    }
}

int main() {
    test_sections_lock();
    return 0;
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran test, use the following commands:

```sh
gfortran -fopenmp -o test_fortran test_DRB069_sectionslock1_orig_no.f90
./test_fortran
```

#### C++

To compile and run the C++ test, use the following commands:

```sh
g++ -fopenmp -o test_cpp test_sections_lock.cpp
./test_cpp
```

### Expected Output

For both the Fortran and C++ tests, the expected output should be:

```
Test Passed: I = 3
```

This confirms that the translation is correct and both programs produce the expected result.
