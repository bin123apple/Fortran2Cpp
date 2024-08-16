Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <algorithm>
#include <iomanip>

void showall(double*** z, int n1, int n2, int n3) {
    int m1, m2, m3;

    m1 = std::min(n1, 18);
    m2 = std::min(n2, 14);
    m3 = std::min(n3, 18);

    std::cout << std::endl;

    for (int i3 = 0; i3 < m3; ++i3) {
        for (int i1 = 0; i1 < m1; ++i1) {
            for (int i2 = 0; i2 < m2; ++i2) {
                std::cout << std::setw(10) << z[i1][i2][i3] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << " - - - - - - - " << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    // Example usage
    const int n1 = 20, n2 = 15, n3 = 20;
    double*** z = new double**[n1];

    for (int i = 0; i < n1; ++i) {
        z[i] = new double*[n2];
        for (int j = 0; j < n2; ++j) {
            z[i][j] = new double[n3];
            for (int k = 0; k < n3; ++k) {
                z[i][j][k] = i + j + k; // Example initialization
            }
        }
    }

    showall(z, n1, n2, n3);

    // Clean up
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            delete[] z[i][j];
        }
        delete[] z[i];
    }
    delete[] z;

    return 0;
}
```

### Explanation:
1. **Function Definition**: The `showall` function takes a 3D array `z`, and its dimensions `n1`, `n2`, and `n3` as parameters.
2. **Dimension Calculations**: The dimensions `m1`, `m2`, and `m3` are calculated to ensure they do not exceed 18, 14, and 18 respectively.
3. **Output Formatting**: The `std::setw(10)` is used to set the width of each output field to 10 characters, mimicking the Fortran `format(15f6.3)`.
4. **Loop Constructs**: The nested loops iterate over the dimensions `m1`, `m2`, and `m3`, printing the elements of the array.
5. **Main Function**: An example `main` function demonstrates how to allocate memory for the 3D array and calls the `showall` function.

### Notes:
- The example usage initializes the array with a simple formula for demonstration purposes.
- Memory cleanup is essential to avoid memory leaks.
- The `std::min` function is used to ensure the dimensions do not exceed the specified limits.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_showall
    implicit none
    integer, parameter :: n1 = 20, n2 = 15, n3 = 20
    double precision, allocatable :: z(:,:,:)
    integer :: i, j, k

    allocate(z(n1,n2,n3))

    ! Initialize the array
    do k = 1, n3
        do j = 1, n2
            do i = 1, n1
                z(i,j,k) = i + j + k
            end do
        end do
    end do

    ! Call the subroutine
    call showall(z, n1, n2, n3)

    ! Deallocate the array
    deallocate(z)
end program test_showall

subroutine showall(z,n1,n2,n3)
    implicit none
    integer n1,n2,n3,i1,i2,i3
    double precision z(n1,n2,n3)
    integer m1, m2, m3

    m1 = min(n1,18)
    m2 = min(n2,14)
    m3 = min(n3,18)

    write(*,*)'  '
    do  i3=1,m3
        do  i1=1,m1
            write(*,6)(z(i1,i2,i3),i2=1,m2)
        enddo
        write(*,*)' - - - - - - - '
    enddo
    write(*,*)'  '

6   format(15f6.3)

    return
end
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <algorithm>
#include <iomanip>

void showall(double*** z, int n1, int n2, int n3) {
    int m1, m2, m3;

    m1 = std::min(n1, 18);
    m2 = std::min(n2, 14);
    m3 = std::min(n3, 18);

    std::cout << std::endl;

    for (int i3 = 0; i3 < m3; ++i3) {
        for (int i1 = 0; i1 < m1; ++i1) {
            for (int i2 = 0; i2 < m2; ++i2) {
                std::cout << std::setw(10) << z[i1][i2][i3] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << " - - - - - - - " << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    const int n1 = 20, n2 = 15, n3 = 20;
    double*** z = new double**[n1];

    for (int i = 0; i < n1; ++i) {
        z[i] = new double*[n2];
        for (int j = 0; j < n2; ++j) {
            z[i][j] = new double[n3];
            for (int k = 0; k < n3; ++k) {
                z[i][j][k] = i + j + k; // Example initialization
            }
        }
    }

    showall(z, n1, n2, n3);

    // Clean up
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            delete[] z[i][j];
        }
        delete[] z[i];
    }
    delete[] z;

    return 0;
}
```

### Explanation:

#### Fortran Unit Test Code:
1. **Program Initialization**: The program allocates a 3D array `z` with dimensions `n1`, `n2`, and `n3`.
2. **Array Initialization**: The array `z` is initialized with the formula `i + j + k`.
3. **Subroutine Call**: The `showall` subroutine is called with the array `z` and its dimensions.
4. **Memory Deallocation**: The array `z` is deallocated.

#### C++ Unit Test Code:
1. **Main Function**: The `main` function allocates a 3D array `z` with dimensions `n1`, `n2`, and `n3`.
2. **Array Initialization**: The array `z` is initialized with the formula `i + j + k`.
3. **Function Call**: The `show
