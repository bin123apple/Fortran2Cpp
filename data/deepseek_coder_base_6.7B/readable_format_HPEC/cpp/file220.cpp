Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>
#include <iostream>

// Define the data type for the arrays
using DataType = double;

void init_array(int length, std::vector<std::vector<DataType>>& c, std::vector<std::vector<DataType>>& w) {
    // Resize the arrays to the specified length
    c.resize(length, std::vector<DataType>(length));
    w.resize(length, std::vector<DataType>(length));

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            c[j][i] = static_cast<DataType>((i * j) % 2);
            w[j][i] = static_cast<DataType>((i - j) / static_cast<double>(length));
        }
    }
}

int main() {
    int length = 5; // Example length
    std::vector<std::vector<DataType>> c, w;

    init_array(length, c, w);

    // Print the arrays for verification
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << "c[" << i << "][" << j << "] = " << c[i][j] << ", ";
            std::cout << "w[" << i << "][" << j << "] = " << w[i][j] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Data Type Definition**: The `DataType` is defined as `double` to match the `DBLE` type in Fortran.
2. **Array Initialization**: The `init_array` function takes the length of the arrays and references to the `c` and `w` arrays. It resizes the arrays to the specified length and fills them with the appropriate values.
3. **Loops**: The nested loops iterate over the arrays, calculating the values as per the Fortran code.
4. **Main Function**: The `main` function demonstrates how to call `init_array` and print the arrays for verification.

This C++ code should produce the same output as the provided Fortran code for the given input `length`.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program that tests the `init_array` subroutine.

```fortran
program test_init_array
    implicit none
    integer, parameter :: length = 5
    integer :: i, j
    real, dimension(length, length) :: c, w

    call init_array(length, c, w)

    do i = 1, length
        do j = 1, length
            print *, 'c(', j, ',', i, ') = ', c(j, i), ', w(', j, ',', i, ') = ', w(j, i)
        end do
    end do
end program test_init_array

subroutine init_array(length, c, w)
    implicit none
    integer, intent(in) :: length
    real, dimension(length, length), intent(out) :: c, w
    integer :: i, j

    do i = 1, length
        do j = 1, length
            c(j, i) = mod((i-1)*(j-1), 2)
            w(j, i) = (real((i - 1) - (j - 1))) / real(length)
        end do
    end do
end subroutine init_array
```

### C++ Unit Test

Next, let's create a C++ program that tests the `init_array` function.

```cpp
#include <vector>
#include <iostream>
#include <cmath>

// Define the data type for the arrays
using DataType = double;

void init_array(int length, std::vector<std::vector<DataType>>& c, std::vector<std::vector<DataType>>& w) {
    // Resize the arrays to the specified length
    c.resize(length, std::vector<DataType>(length));
    w.resize(length, std::vector<DataType>(length));

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            c[j][i] = static_cast<DataType>((i * j) % 2);
            w[j][i] = static_cast<DataType>((i - j) / static_cast<double>(length));
        }
    }
}

int main() {
    int length = 5; // Example length
    std::vector<std::vector<DataType>> c, w;

    init_array(length, c, w);

    // Print the arrays for verification
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << "c[" << i << "][" << j << "] = " << c[i][j] << ", ";
            std::cout << "w[" << i << "][" << j << "] = " << w[i][j] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Fortran Unit Test**:
    - The `test_init_array` program initializes the arrays `c` and `w` using the `init_array` subroutine.
    - It prints the values of `c` and `w` for verification.

2. **C++ Unit Test**:
    - The `main` function initializes the arrays `c` and `w` using the `init_array` function.
    - It prints the values of `c` and `w` for verification.

### Running the Tests:
1. **Fortran**:
    - Save the Fortran code in a file, e.g., `test_init_array.f90`.
    - Compile and run the Fortran code using a Fortran compiler, e.g., `gfortran`:
      ```sh
      gfortran test_init_array.f90 -o test_init_array
      ./test_init_array
      ```

2. **C++**:
    - Save the C++ code in a file, e.g., `test_init_array.cpp`.
    - Compile and run the C++ code using a C++ compiler, e.g., `g++`:
      ```sh
      g++ test_init_array.cpp -o test_init_array
      ./test_init_array
      ```

### Verification:
- Compare the output of both programs to ensure they are identical.
- The output should show the same values for `c` and `w` for each `i` and `j`.

By running these tests, you can verify that the translation from Fortran to C++ is correct.
