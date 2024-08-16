Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 1000;
    std::vector<int> a(len);

    a[0] = 2; // Note: C++ uses 0-based indexing

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] += a[0];
    }

    std::cout << "a[499] = " << a[499] << std::endl; // Note: C++ uses 0-based indexing

    return 0;
}
```

### Key Points:

1. **Array Indexing**: Fortran arrays are 1-based, while C++ arrays are 0-based. This difference is accounted for in the translation by setting the first element of the array to `2` and then accessing the 500th element (which is the 499th index in C++).

2. **Dynamic Array Allocation**: In Fortran, the array `a` is dynamically allocated using `allocate`. In C++, this is handled using `std::vector<int>`.

3. **Parallel Loop**: The OpenMP directives for parallelization are used similarly in both languages. The `#pragma omp parallel for` directive is used to parallelize the loop.

4. **Output**: The output is formatted to match the Fortran output style using `std::cout`.

5. **Deallocation**: In Fortran, the array `a` is deallocated using `deallocate`. In C++, this is not necessary as `std::vector` automatically handles memory deallocation.

Remember to compile the C++ code with OpenMP support enabled. For example, if you are using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

To test the Fortran code, you can create a simple test program that checks if the output is as expected. Here is an example:

```fortran
program test_DRB039_truedepsingleelement_orig_yes
    use omp_lib
    implicit none

    integer :: len, i
    integer, dimension(:), allocatable :: a
    integer :: expected_value

    len = 1000
    allocate (a(len))

    a(1) = 2

    !$omp parallel do
    do i = 1, len
        a(i) = a(i) + a(1)
    end do
    !$omp end parallel do

    expected_value = 3
    if (a(500) == expected_value) then
        print *, "Test Passed: a(500) = ", a(500)
    else
        print *, "Test Failed: a(500) = ", a(500), " Expected: ", expected_value
    end if

    deallocate(a)
end program test_DRB039_truedepsingleelement_orig_yes
```

### C++ Unit Test Code

To test the C++ code, you can use a simple test function that checks if the output is as expected. Here is an example:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

bool test_DRB039_truedepsingleelement_orig_yes() {
    const int len = 1000;
    std::vector<int> a(len);

    a[0] = 2; // Note: C++ uses 0-based indexing

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] += a[0];
    }

    int expected_value = 3;
    if (a[499] == expected_value) {
        std::cout << "Test Passed: a[499] = " << a[499] << std::endl;
        return true;
    } else {
        std::cout << "Test Failed: a[499] = " << a[499] << " Expected: " << expected_value << std::endl;
        return false;
    }
}

int main() {
    if (test_DRB039_truedepsingleelement_orig_yes()) {
        return 0;
    } else {
        return 1;
    }
}
```

### Compilation and Execution

#### Fortran

To compile and run the Fortran test code, use the following commands:

```sh
gfortran -fopenmp test_DRB039_truedepsingleelement_orig_yes.f90 -o test_DRB039
./test_DRB039
```

#### C++

To compile and run the C++ test code, use the following commands:

```sh
g++ -fopenmp test_DRB039_truedepsingleelement_orig_yes.cpp -o test_DRB039
./test_DRB039
```

### Expected Output

For both the Fortran and C++ test codes, the expected output should be:

```
Test Passed: a(500) = 3
```

or


```
Test Passed: a[499] = 3
```

This output verifies that the translation is correct.
