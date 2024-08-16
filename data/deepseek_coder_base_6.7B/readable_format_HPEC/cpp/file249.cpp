To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, data types, and the loop constructs. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, Fortran passes arrays to functions/subroutines by reference by default, which is akin to passing pointers in C++. Here's how the Fortran code can be translated to C++:

```cpp
#include <vector>

// Assuming DATA_TYPE is a float or double for this translation
using DATA_TYPE = double;

void kernel_reg_detect(int niter, int maxgrid, int length, 
                        std::vector<std::vector<DATA_TYPE>>& sumTang, 
                        std::vector<std::vector<DATA_TYPE>>& mean, 
                        std::vector<std::vector<DATA_TYPE>>& path, 
                        std::vector<std::vector<std::vector<DATA_TYPE>>>& diff, 
                        std::vector<std::vector<std::vector<DATA_TYPE>>>& sumDiff) {
    // Adjusting for 0-based indexing in C++
    niter -= 1;
    maxgrid -= 1;
    length -= 1;

    // Assuming the size of the vectors is already correctly set before this function is called
    // The actual size checking and resizing should be handled appropriately in the calling code

    // Loop constructs translated directly from Fortran to C++
    for (int t = 0; t <= niter; ++t) {
        for (int j = 0; j <= maxgrid; ++j) {
            for (int i = j; i <= maxgrid; ++i) {
                for (int cnt = 0; cnt <= length; ++cnt) {
                    diff[cnt][i][j] = sumTang[i][j];
                }
            }
        }
    }

    for (int j = 0; j <= maxgrid; ++j) {
        for (int i = j; i <= maxgrid; ++i) {
            sumDiff[0][i][j] = diff[0][i][j];
            for (int cnt = 1; cnt <= length; ++cnt) {
                sumDiff[cnt][i][j] = sumDiff[cnt - 1][i][j] + diff[cnt][i][j];
            }
            mean[i][j] = sumDiff[length][i][j];
        }
    }

    for (int i = 0; i <= maxgrid; ++i) {
        path[i][0] = mean[i][0];
    }

    for (int j = 1; j <= maxgrid; ++j) {
        for (int i = j; i <= maxgrid; ++i) {
            path[i][j] = path[i - 1][j - 1] + mean[i][j];
        }
    }
}
```

This translation assumes that the sizes of the vectors are correctly set before calling `kernel_reg_detect`. The original Fortran code uses `DATA_TYPE` as a placeholder for the data type, which should be replaced with the actual data type (e.g., `float` or `double`) in the C++ code. The loop constructs are directly translated from Fortran to C++, with adjustments for 0-based indexing.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the original Fortran code and the translated C++ code. These tests will help verify the correctness of the translation by comparing the outputs of both implementations.

### Fortran Unit Test

First, let's create a Fortran program that calls the `kernel_reg_detect` subroutine and prints the results for verification.

```fortran
program test_kernel_reg_detect
    implicit none
    integer, parameter :: niter = 2, maxgrid = 3, length = 3
    real, dimension(maxgrid, maxgrid) :: sumTang, mean
    real, dimension(length, maxgrid, maxgrid) :: sumDiff, diff
    real, dimension(maxgrid, maxgrid) :: path
    integer :: i, j, t, cnt

    ! Initialize arrays for testing
    sumTang = reshape([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], [maxgrid, maxgrid])
    diff = 0.0
    sumDiff = 0.0
    mean = 0.0
    path = 0.0

    ! Call the subroutine
    call kernel_reg_detect(niter, maxgrid, length, sumTang, mean, path, diff, sumDiff)

    ! Print results for verification
    print *, 'mean:'
    do i = 1, maxgrid
        print *, (mean(i, j), j = 1, maxgrid)
    end do

    print *, 'path:'
    do i = 1, maxgrid
        print *, (path(i, j), j = 1, maxgrid)
    end do
end program test_kernel_reg_detect
```

### C++ Unit Test

Now, let's create a C++ program that calls the `kernel_reg_detect` function and prints the results for verification.

```cpp
#include <iostream>
#include <vector>

// Include or copy the translated C++ function here

int main() {
    int niter = 2, maxgrid = 3, length = 3;
    std::vector<std::vector<double>> sumTang = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> mean(maxgrid, std::vector<double>(maxgrid, 0));
    std::vector<std::vector<double>> path(maxgrid, std::vector<double>(maxgrid, 0));
    std::vector<std::vector<std::vector<double>>> diff(length, std::vector<std::vector<double>>(maxgrid, std::vector<double>(maxgrid, 0)));
    std::vector<std::vector<std::vector<double>>> sumDiff(length, std::vector<std::vector<double>>(maxgrid, std::vector<double>(maxgrid, 0)));

    // Call the function
    kernel_reg_detect(niter, maxgrid, length, sumTang, mean, path, diff, sumDiff);

    // Print results for verification
    std::cout << "mean:" << std::endl;
    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            std::cout << mean[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "path:" << std::endl;
    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            std::cout << path[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

### Running the Tests

To run these tests, you'll need a Fortran compiler (e.g., `gfortran`) for the Fortran code and a C++ compiler (e.g., `g++`) for the C++ code.

1. **Fortran Test**:
    - Save the Fortran code in a file, e.g., `test_kernel_reg_detect.f90`.
    - Compile and run the Fortran code using a command like:
      ```sh
      gfortran test_kernel_reg_detect.f90 -o test_kernel_reg_detect
      ./test_kernel_reg_detect
      ```

2. **C++ Test**:
    - Save the C++ code in a file, e.g., `test_kernel_reg_detect.cpp`.
    - Compile and run the C++ code using a command like:
      ```sh
      g++ test_kernel_reg_detect.cpp -o test_kernel_reg_detect
      ./test_kernel_reg_detect
      ```

After running both tests, you should compare the output of the Fortran program with the output of the C++ program. The results should
