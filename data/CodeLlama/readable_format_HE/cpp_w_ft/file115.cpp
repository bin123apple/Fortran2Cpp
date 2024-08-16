Translating the provided Fortran code to C++ involves several steps, including changing the syntax for loops, arrays, and functions. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <vector>

class MatrixTriples {
public:
    static int getMatrixTriples(int n) {
        std::vector<int> a(n);
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(3, 0));
        std::vector<std::vector<int>> sum2(n + 1, std::vector<int>(3, 0));

        // Initialize arrays
        sum = std::vector<std::vector<int>>(n + 1, std::vector<int>(3, 0));
        sum2 = std::vector<std::vector<int>>(n + 1, std::vector<int>(3, 0));

        // Fill array 'a' and compute initial sums
        for (int i = 0; i < n; ++i) {
            a[i] = (i * i - i + 1) % 3;
            for (int j = 0; j < 3; ++j) {
                sum[i + 1][j] = sum[i][j];
            }
            sum[i + 1][a[i]] += 1;
        }

        // Compute sums for times = 1 and 2
        for (int times = 1; times <= 2; ++times) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    sum2[i + 1][j] = sum2[i][j];
                }
                for (int j = -1; j <= 1; ++j) {
                    sum2[i + 1][(a[i] + j + 3) % 3] += sum[i][(j + 1) % 3];
                }
            }
            sum = sum2;
            sum2 = std::vector<std::vector<int>>(n + 1, std::vector<int>(3, 0));
        }

        return sum[n][0];
    }
};

int main() {
    // Test cases
    if (MatrixTriples::getMatrixTriples(5) != 1) {
        std::cerr << "Assertion failed: getMatrixTriples(5) == 1" << std::endl;
        return 1;
    }

    if (MatrixTriples::getMatrixTriples(6) != 4) {
        std::cerr << "Assertion failed: getMatrixTriples(6) == 4" << std::endl;
        return 1;
    }

    if (MatrixTriples::getMatrixTriples(10) != 36) {
        std::cerr << "Assertion failed: getMatrixTriples(10) == 36" << std::endl;
        return 1;
    }

    if (MatrixTriples::getMatrixTriples(100) != 53361) {
        std::cerr << "Assertion failed: getMatrixTriples(100) == 53361" << std::endl;
        return 1;
    }

    return 0;
}
```

### Key Changes:

1. **Module to Class**: Fortran modules are used to encapsulate functions and data, which is similar to classes in C++. The `getMatrixTriples` function is made static to allow calling it without instantiating the class.

2. **Arrays**: Fortran's allocatable arrays are replaced with `std::vector` in C++ for dynamic array allocation. This also handles memory deallocation automatically.

3. **Loop Indices**: Fortran arrays are 1-based, while C++ arrays are 0-based. Adjustments are made accordingly.

4. **Function Arguments**: The function `getMatrixTriples` now takes `n` as an argument and returns the result directly.

5. **Mathematical Operations**: The modulus operation `%` is used in C++ instead of Fortran's `mod`.

6. **Output and Exit**: Error messages are printed to `std::cerr` and the program exits with a non-zero status if an assertion fails, similar to the Fortran `write` and `exit` statements.

This C++ code should now provide the same functionality as the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by comparing the outputs for the same input values.

### Fortran Unit Test Code

```fortran
module matrix_triples_module
  implicit none
contains

  integer function get_matrix_triples(n)
    integer, intent(in) :: n
    integer :: i, j, times
    integer, dimension(:), allocatable :: a
    integer, dimension(:,:), allocatable :: sum, sum2

    allocate(a(n))
    allocate(sum(n+1, 3))
    allocate(sum2(n+1, 3))

    ! Initialize arrays
    sum = 0
    sum2 = 0

    ! Fill array 'a' and compute initial sums
    do i = 1, n
      a(i) = mod(i*i - i + 1, 3)
      sum(i+1, :) = sum(i, :)
      sum(i+1, a(i)+1) = sum(i+1, a(i)+1) + 1
    end do

    ! Compute sums for times = 1 and 2
    do times = 1, 2
      do i = 1, n
        sum2(i+1, :) = sum2(i, :)
        do j = 0, 2
          sum2(i+1, mod(a(i) + j, 3) + 1) = sum2(i+1, mod(a(i) + j, 3) + 1) + sum(i, j+1)
        end do
      end do
      sum = sum2
      sum2 = 0
    end do

    get_matrix_triples = sum(n+1, 1)
  end function get_matrix_triples

end module matrix_triples_module

program matrix_triples
  use matrix_triples_module
  implicit none
  integer :: n, result

  ! Test cases
  result = get_matrix_triples(5)
  if (result /= 1) then
    write(*,*) "Assertion failed: get_matrix_triples(5) == 1"
    call exit(1)
  end if

  result = get_matrix_triples(6)
  if (result /= 4) then
    write(*,*) "Assertion failed: get_matrix_triples(6) == 4"
    call exit(1)
  end if

  result = get_matrix_triples(10)
  if (result /= 36) then
    write(*,*) "Assertion failed: get_matrix_triples(10) == 36"
    call exit(1)
  end if

  result = get_matrix_triples(100)
  if (result /= 53361) then
    write(*,*) "Assertion failed: get_matrix_triples(100) == 53361"
    call exit(1)
  end if

end program matrix_triples
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>

class MatrixTriples {
public:
    static int getMatrixTriples(int n) {
        std::vector<int> a(n);
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(3, 0));
        std::vector<std::vector<int>> sum2(n + 1, std::vector<int>(3, 0));

        // Initialize arrays
        sum = std::vector<std::vector<int>>(n + 1, std::vector<int>(3, 0));
        sum2 = std::vector<std::vector<int>>(n + 1,
