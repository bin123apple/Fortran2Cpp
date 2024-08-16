Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>

void init_array(int n, std::vector<std::vector<double>>& path) {
    // Resize the path vector to have dimensions n x n
    path.resize(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            path[j][i] = static_cast<double>((i + 1) * (j + 1)) / static_cast<double>(n);
        }
    }
}
```

### Explanation:
1. **Function Signature**: The subroutine in Fortran is translated to a function in C++. The function `init_array` takes two parameters: an integer `n` and a reference to a 2D vector `path`.
2. **Vector Resizing**: The `path` vector is resized to have dimensions `n x n` using the `resize` method of the `std::vector`.
3. **Nested Loops**: The nested loops in Fortran are translated to nested loops in C++. The loops run from `0` to `n-1` because C++ uses 0-based indexing.
4. **Calculation**: The calculation inside the nested loops is directly translated from Fortran to C++. Note that Fortran uses 1-based indexing, so when translating to C++, `i + 1` and `j + 1` are used to match the Fortran logic.

This C++ function should behave similarly to the provided Fortran subroutine.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

First, let's create a Fortran program to test the `init_array` subroutine:

```fortran
program test_init_array
    implicit none
    integer :: n
    parameter (n=5)
    double precision, dimension(n,n) :: path
    integer :: i, j

    call init_array(n, path)

    do i=1, n
        do j=1, n
            print *, 'path(', j, ',', i, ') = ', path(j, i)
        end do
    end do
end program test_init_array

subroutine init_array(n, path)
    implicit none
    double precision, dimension(n,n) :: path
    integer :: i, j, n

    do i=1, n
        do j=1, n
            path(j, i) = (DBLE(i * j))/ DBLE(n)
        end do
    end do
end subroutine init_array
```

### C++ Unit Test

Now, let's create a C++ program to test the `init_array` function:

```cpp
#include <iostream>
#include <vector>

void init_array(int n, std::vector<std::vector<double>>& path) {
    path.resize(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            path[j][i] = static_cast<double>((i + 1) * (j + 1)) / static_cast<double>(n);
        }
    }
}

int main() {
    int n = 5;
    std::vector<std::vector<double>> path;

    init_array(n, path);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "path(" << j << "," << i << ") = " << path[j][i] << std::endl;
        }
    }

    return 0;
}
```

### Explanation:

1. **Fortran Test Program**:
   - The `test_init_array` program defines a 2D array `path` and initializes it using the `init_array` subroutine.
   - It prints the values of the `path` array to verify the correctness of the subroutine.

2. **C++ Test Program**:
   - The `main` function defines a 2D vector `path` and initializes it using the `init_array` function.
   - It prints the values of the `path` vector to verify the correctness of the function.

### Running the Tests:

To run the Fortran test, you can compile and execute the Fortran program using a Fortran compiler like `gfortran`:

```sh
gfortran -o test_init_array test_init_array.f90
./test_init_array
```

To run the C++ test, you can compile and execute the C++ program using a C++ compiler like `g++`:

```sh
g++ -o test_init_array test_init_array.cpp
./test_init_array
```

Both programs should output the same values for the `path` array/vector, verifying that the translation is correct.
