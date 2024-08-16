Certainly! Below is the translated version of your Fortran code into C++. This translation assumes that you want to use a 2D array dynamically allocated based on the size `n` passed to the function. In C++, dynamic memory allocation for arrays is often handled using pointers and the `new` operator.

```cpp
#include <iostream>

// Function prototype
void init_array(int n, double** a);

int main() {
    int n = 5; // Example size
    double** a = nullptr; // Pointer to a pointer for the 2D array

    // Dynamically allocate memory for the 2D array
    a = new double*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    // Call the function to initialize the array
    init_array(n, a);

    // Example: Print the array to verify the initialization
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free the dynamically allocated memory
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

// Function definition
void init_array(int n, double** a) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[j][i] = static_cast<double>(i + 1) * static_cast<double>(j + 1) / static_cast<double>(n);
        }
    }
}
```

This C++ code dynamically allocates a 2D array of size `n x n`, initializes it using the Fortran subroutine logic, and then prints the array to verify the initialization. Remember to include proper error checking and clean up the dynamically allocated memory to avoid memory leaks.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the Fortran and C++ versions of the code. These tests will verify the correctness of the array initialization.

### Fortran Unit Test

First, let's create a Fortran program that calls the `init_array` subroutine and checks the results.

```fortran
program test_init_array
    implicit none
    integer, parameter :: n = 5
    real, dimension(n, n) :: a
    integer :: i, j
    logical :: test_passed

    call init_array(n, a)

    test_passed = .true.
    do i = 1, n
        do j = 1, n
            if (a(j, i) /= (real(i) * real(j)) / real(n)) then
                test_passed = .false.
                exit
            end if
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_init_array

subroutine init_array(n, a)
    implicit none
    integer, intent(in) :: n
    real, dimension(n, n), intent(out) :: a
    integer :: i, j

    do i = 1, n
        do j = 1, n
            a(j, i) = (real(i) * real(j)) / real(n)
        end do
    end do
end subroutine init_array
```

### C++ Unit Test

Now, let's create a C++ program that includes the `init_array` function and checks the results using assertions.

```cpp
#include <iostream>
#include <cassert>
#include <cmath>

// Function prototype
void init_array(int n, double** a);

int main() {
    int n = 5; // Example size
    double** a = nullptr; // Pointer to a pointer for the 2D array

    // Dynamically allocate memory for the 2D array
    a = new double*[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new double[n];
    }

    // Call the function to initialize the array
    init_array(n, a);

    // Unit test: Verify the array initialization
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            double expected = static_cast<double>(i + 1) * static_cast<double>(j + 1) / static_cast<double>(n);
            assert(std::fabs(a[i][j] - expected) < 1e-6); // Using a small threshold for floating point comparison
        }
    }

    std::cout << "Test passed." << std::endl;

    // Free the dynamically allocated memory
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

// Function definition
void init_array(int n, double** a) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            a[j][i] = static_cast<double>(i + 1) * static_cast<double>(j + 1) / static_cast<double>(n);
        }
    }
}
```

These unit tests will help verify that the array initialization logic in both the Fortran and C++ versions works as expected. The Fortran test is a simple program that checks the array values, while the C++ test uses `assert` to verify the correctness of the array initialization.
