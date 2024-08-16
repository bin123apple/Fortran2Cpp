To translate the given Fortran subroutine to C++, we need to consider several aspects, including the data types, array indexing, and the loop structure. In Fortran, arrays are 1-based, while in C++, they are 0-based. Also, Fortran passes arrays to functions/subroutines by reference automatically, whereas in C++, we need to explicitly use pointers or references. For simplicity and to maintain the 1-based indexing of the original Fortran code, we'll use a 2D array in C++ that is dynamically allocated.

Here's how the Fortran subroutine could be translated to a C++ function:

```cpp
#include <iostream>

void init_array(int n, double** a) {
    // Dynamically allocate 2D array
    a = new double*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[j][i] = ((static_cast<double>(i) * static_cast<double>(j + 1)) + 2.0) / static_cast<double>(n);
        }
    }
}

int main() {
    int n = 5; // Example size
    double** a = nullptr;

    init_array(n, a);

    // Example: Print the array
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Clean up dynamically allocated memory
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
```

Key points in the translation:

1. **Dynamic Allocation**: The 2D array `a` is dynamically allocated in the `init_array` function. This is necessary because the size of the array is not known at compile time in the same way it is in the Fortran code.

2. **Array Indexing**: Adjusted the loop indices and calculations to account for C++'s 0-based indexing.

3. **Data Types**: Converted Fortran's `DBLE` to `double` in C++.

4. **Memory Management**: Ensured to properly deallocate the dynamically allocated memory to avoid memory leaks.

This C++ function should behave similarly to the original Fortran subroutine, initializing a 2D array with the specified formula and returning it.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the array initialization.

### Fortran Unit Test

To test the Fortran subroutine, we'll write a simple program that calls the subroutine and checks the results.

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 5
    real, dimension(n, n) :: a
    integer :: i, j

    call init_array(n, a)

    do i = 1, n
        do j = 1, n
            print *, 'a(', i, ',', j, ') = ', a(i, j)
        end do
    end do
end program test_init_array

subroutine init_array(n, a)
    implicit none
    integer, intent(in) :: n
    real, dimension(n, n), intent(out) :: a
    integer :: i, j

    do i = 1, n
        do j = 1, n
            a(j, i) = ((real(i - 1) * real(j + 1)) + 2.0) / real(n)
        end do
    end do
end subroutine init_array
```

This Fortran program defines a test program `test_init_array` that calls the `init_array` subroutine and prints the resulting array. You can compile and run this Fortran code using a Fortran compiler like `gfortran`.

### C++ Unit Test

For the C++ code, we'll use a simple test within the `main` function to verify the array initialization. For a more structured unit test, one might use a testing framework like Google Test, but for simplicity, we'll stick to basic checks.

```cpp
#include <iostream>
#include <cmath> // For fabs

void init_array(int n, double** a);

int main() {
    int n = 5; // Example size
    double** a = nullptr;

    init_array(n, a);

    // Example: Print the array and check values
    bool success = true;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            double expected = ((static_cast<double>(i) * static_cast<double>(j + 1)) + 2.0) / static_cast<double>(n);
            if(fabs(a[i][j] - expected) > 1e-6) { // Using a small threshold for floating point comparison
                std::cout << "Test failed: a[" << i << "][" << j << "] = " << a[i][j] << " expected " << expected << std::endl;
                success = false;
            }
        }
    }

    if(success) {
        std::cout << "All tests passed." << std::endl;
    }

    // Clean up dynamically allocated memory
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

void init_array(int n, double** a) {
    a = new double*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[j][i] = ((static_cast<double>(i) * static_cast<double>(j + 1)) + 2.0) / static_cast<double>(n);
        }
    }
}
```

This C++ program initializes the array, then checks each element against the expected value. If any element does not match the expected value within a small tolerance (to account for floating-point arithmetic inaccuracies), it reports a failure. Otherwise, it reports success.

To compile and run the C++ code, use a C++ compiler like `g++`:

```sh
g++ -o test_init_array test_init_array.cpp
./test_init_array
```

These unit tests should help verify the correctness of both the Fortran and C++ implementations of the array initialization.
