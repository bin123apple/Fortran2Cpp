Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <omp.h>

int main() {
    std::vector<std::string> a(100);
    std::string str;

    #pragma omp parallel for private(str)
    for (int i = 1; i <= 100; ++i) {
        std::ostringstream ss;
        ss << i;
        str = ss.str();
        a[i - 1] = str;
    }

    // Printing the 23rd element of the array
    std::cout << "a(23) = " << a[22] << std::endl;

    return 0;
}
```

### Explanation:
1. **Vector Initialization**: In C++, we use `std::vector<std::string>` to create an array of strings. This is similar to the `character(len=100), dimension(:), allocatable :: a` in Fortran.
2. **OpenMP Directives**: The `#pragma omp parallel for` directive is used to parallelize the loop, similar to the `!$omp parallel do private(str)` in Fortran.
3. **String Formatting**: The Fortran `write` statement is replaced by `std::ostringstream` in C++ to format the string.
4. **Array Assignment**: The loop assigns the formatted string to the corresponding element of the array.
5. **Printing the Result**: The 23rd element of the array is printed, equivalent to the Fortran `print*,'a(i)',a(23)` statement.

### Notes:
- **Array Indexing**: Fortran arrays are 1-based, while C++ arrays are 0-based. Therefore, when accessing the 23rd element of the array in Fortran (`a(23)`), the equivalent C++ index is `a[22]`.
- **OpenMP**: Ensure you have OpenMP installed and enabled in your compiler settings to compile this code.
- **Compilation**: To compile this C++ code with OpenMP support, you might use a command like `g++ -fopenmp your_program.cpp -o your_program`.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_drb047_doallchar_orig_no
    use omp_lib
    implicit none

    character(len=100), dimension(:), allocatable :: a
    character(50) :: str
    integer :: i
    logical :: test_passed

    allocate (a(100))

    !$omp parallel do private(str)
    do i = 1, 100
        write( str, '(i10)' )  i
        a(i) = str
    end do
    !$omp end parallel do

    test_passed = .true.
    do i = 1, 100
        write( str, '(i10)' )  i
        if (a(i) /= str) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print*, 'Test Passed'
    else
        print*, 'Test Failed'
    endif
end program test_drb047_doallchar_orig_no
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <omp.h>
#include <cassert>

int main() {
    std::vector<std::string> a(100);
    std::string str;
    bool test_passed = true;

    #pragma omp parallel for private(str)
    for (int i = 1; i <= 100; ++i) {
        std::ostringstream ss;
        ss << i;
        str = ss.str();
        a[i - 1] = str;
    }

    for (int i = 1; i <= 100; ++i) {
        std::ostringstream ss;
        ss << i;
        str = ss.str();
        if (a[i - 1] != str) {
            test_passed = false;
            break;
        }
    }

    if (test_passed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The Fortran program initializes an array of strings `a`.
   - It fills the array with strings formatted as integers from 1 to 100.
   - It then checks if each element of the array matches the expected string (i.e., the integer as a string).
   - If all elements match, it prints "Test Passed"; otherwise, it prints "Test Failed".

2. **C++ Unit Test Code**:
   - The C++ program does the same as the Fortran program.
   - It initializes a vector of strings `a`.
   - It fills the vector with strings formatted as integers from 1 to 100.
   - It then checks if each element of the vector matches the expected string.
   - If all elements match, it prints "Test Passed"; otherwise, it prints "Test Failed".

### Compilation and Execution:

- **Fortran**:
  - Compile the Fortran code with OpenMP support using a command like `gfortran -fopenmp test_drb047_doallchar_orig_no.f90 -o test_drb047_doallchar_orig_no`.
  - Run the executable: `./test_drb047_doallchar_orig_no`.

- **C++**:
  - Compile the C++ code with OpenMP support using a command like `g++ -fopenmp test_drb047_doallchar_orig_no.cpp -o test_drb047_doallchar_orig_no`.
  - Run the executable: `./test_drb047_doallchar_orig_no`.

These unit tests will verify that the translated C++ code behaves the same as the original Fortran code.
