To translate the given Fortran code to C++, we need to understand the structure and functionality of the original Fortran code and then replicate its behavior using C++ constructs. The Fortran code defines an array `a` of size 100, initializes it using a subroutine `foo` (which is not provided in the original code snippet), and then prints the value at index 50 of the array.

Here's how you can translate the given Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

// Assuming the functionality of foo is as follows for demonstration purposes.
// This function initializes the array with a specific value, in this case, 7.
void foo(std::vector<int>& a, int size, int value) {
    for (int i = 0; i < size; ++i) {
        a[i] = value;
    }
}

int main() {
    // Equivalent to allocate(a(100)) in Fortran
    std::vector<int> a(100);

    // Calling foo to initialize the array
    foo(a, 100, 7);

    // Printing the value at index 50
    std::cout << a[50] << std::endl;

    return 0;
}
```

### Explanation:
1. **Vector Initialization**: In C++, the `std::vector` container is used to dynamically allocate an array of integers. This is equivalent to the `allocate` statement in Fortran.
2. **Function Call**: The `foo` function is defined to initialize the array with a specific value. This is a placeholder implementation based on the original Fortran code's functionality.
3. **Printing the Value**: The value at index 50 of the array `a` is printed to the standard output.

### Notes:
- The `omp_lib` and `DRB048` modules in the Fortran code are not directly translatable to C++ because they are specific to the Fortran programming environment and might not be available in C++.
- The `implicit none` statement in Fortran is not needed in C++ because variable types must be explicitly declared.
- The `use` statements in Fortran are not needed in C++ because the functionality they provide (e.g., access to modules) can be directly included or implemented in the C++ code.

This C++ code should provide similar functionality to the original Fortran code, though the exact implementation of `foo` is not provided in the original question.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify that the array `a` is correctly initialized with the value 7 and that the value at index 50 is correctly printed.

### Fortran Unit Test Code

```fortran
program test_DRB048_firstprivate_orig_no
    use omp_lib
    implicit none
    integer, allocatable :: a(:)
    integer :: i

    allocate(a(100))
    call foo(a, 100, 7)

    ! Check if the array is correctly initialized
    do i = 1, 100
        if (a(i) /= 7) then
            print *, "Test failed: Array not correctly initialized."
            stop
        end if
    end do
    print *, "Array initialization test passed."

    ! Check if the value at index 50 is correct
    if (a(50) /= 7) then
        print *, "Test failed: Value at index 50 is incorrect."
        stop
    end if
    print *, "Value at index 50 test passed."

    print *, "All tests passed."
end program test_DRB048_firstprivate_orig_no

subroutine foo(a, size, value)
    integer, intent(inout) :: a(:)
    integer, intent(in) :: size, value
    integer :: i

    do i = 1, size
        a(i) = value
    end do
end subroutine foo
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

void foo(std::vector<int>& a, int size, int value) {
    for (int i = 0; i < size; ++i) {
        a[i] = value;
    }
}

int main() {
    std::vector<int> a(100);
    foo(a, 100, 7);

    // Check if the array is correctly initialized
    for (int i = 0; i < 100; ++i) {
        if (a[i] != 7) {
            std::cout << "Test failed: Array not correctly initialized." << std::endl;
            return 1;
        }
    }
    std::cout << "Array initialization test passed." << std::endl;

    // Check if the value at index 50 is correct
    if (a[50] != 7) {
        std::cout << "Test failed: Value at index 50 is incorrect." << std::endl;
        return 1;
    }
    std::cout << "Value at index 50 test passed." << std::endl;

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

### Explanation:
1. **Fortran Unit Test Code**:
   - The `test_DRB048_firstprivate_orig_no` program initializes the array `a` and calls the `foo` subroutine.
   - It then checks if the array is correctly initialized by iterating over the array and ensuring all elements are 7.
   - It also checks if the value at index 50 is 7.
   - If any of the checks fail, it prints an error message and stops the program.
   - If all checks pass, it prints a success message.

2. **C++ Unit Test Code**:
   - The `main` function initializes the vector `a` and calls the `foo` function.
   - It then checks if the vector is correctly initialized by iterating over the vector and ensuring all elements are 7.
   - It also checks if the value at index 50 is 7.
   - If any of the checks fail, it prints an error message and returns 1.
   - If all checks pass, it prints a success message.

These unit tests will help verify the correctness of the array initialization and the value at index 50 in both the Fortran and C++ implementations.
