Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    int tmp = 10;
    std::vector<int> a(len);

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = tmp;
        tmp = a[i] + (i + 1);
    }

    std::cout << "a(50) = " << a[49] << std::endl;

    return 0;
}
```

### Explanation:
1. **Include Libraries**:
   - `#include <iostream>` for input/output operations.
   - `#include <vector>` for dynamic array (vector) support.
   - `#include <omp.h>` for OpenMP support.

2. **Main Function**:
   - Declare the length of the array `len` and initialize `tmp`.
   - Create a vector `a` of size `len`.

3. **Parallel Loop**:
   - Use OpenMP's `#pragma omp parallel for` directive to parallelize the loop.
   - Loop from `0` to `len - 1` to match C++'s 0-based indexing.

4. **Array Assignment and Update**:
   - Assign `tmp` to the current element of `a`.
   - Update `tmp` to `a[i] + (i + 1)`.

5. **Printing the Result**:
   - Print the value of `a[49]` which corresponds to the 50th element in the original Fortran code.

### Notes:
- Remember to compile the C++ code with OpenMP support enabled. For example, using `g++`, you can compile the code with the `-fopenmp` flag:
  ```sh
  g++ -fopenmp your_program.cpp -o your_program
  ```
- The original Fortran code uses 1-based indexing, while C++ uses 0-based indexing. Therefore, when accessing the 50th element of the array in the Fortran code (`a(50)`), the equivalent C++ code uses `a[49]`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_DRB035_truedepscalar_orig_yes
    use omp_lib
    implicit none

    integer :: i, tmp, len
    integer, dimension(:), allocatable :: a
    integer :: expected_value

    len = 100
    tmp = 10
    allocate (a(len))

    !$omp parallel do
    do i = 1, len
        a(i) = tmp
        tmp = a(i) + i
    end do
    !$omp end parallel do

    expected_value = 150
    if (a(50) == expected_value) then
        print *, "Test passed: a(50) = ", a(50)
    else
        print *, "Test failed: a(50) = ", a(50), "Expected: ", expected_value
    end if

    deallocate(a)
end program test_DRB035_truedepscalar_orig_yes
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int len = 100;
    int tmp = 10;
    std::vector<int> a(len);
    int expected_value = 150;

    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        a[i] = tmp;
        tmp = a[i] + (i + 1);
    }

    if (a[49] == expected_value) {
        std::cout << "Test passed: a[49] = " << a[49] << std::endl;
    } else {
        std::cout << "Test failed: a[49] = " << a[49] << " Expected: " << expected_value << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The program initializes the array `a` and updates it using OpenMP parallelization.
   - It checks if the 50th element of the array `a` is equal to the expected value `150`.
   - If the test passes, it prints a success message; otherwise, it prints a failure message.

2. **C++ Unit Test Code**:
   - The program does the same as the Fortran code, initializing the vector `a` and updating it using OpenMP parallelization.
   - It checks if the 50th element of the vector `a` is equal to the expected value `150`.
   - If the test passes, it prints a success message; otherwise, it prints a failure message.

### Compilation and Execution:

- **Fortran**:
  - Compile the Fortran code with OpenMP support:
    ```sh
    gfortran -fopenmp test_DRB035_truedepscalar_orig_yes.f90 -o test_DRB035_truedepscalar_orig_yes
    ```
  - Run the executable:
    ```sh
    ./test_DRB035_truedepscalar_orig_yes
    ```

- **C++**:
  - Compile the C++ code with OpenMP support:
    ```sh
    g++ -fopenmp test_DRB035_truedepscalar_orig_yes.cpp -o test_DRB035_truedepscalar_orig_yes
    ```
  - Run the executable:
    ```sh
    ./test_DRB035_truedepscalar_orig_yes
    ```

These unit tests will help verify that the translated C++ code produces the same output as the original Fortran code.
