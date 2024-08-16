Certainly! Below is the translated Fortran code to C++:

```cpp
#include <vector>

void vecset(int n, std::vector<double>& v, std::vector<int>& iv, int& nzv, int i, double val) {
    bool set = false;
    for (int k = 0; k < nzv; ++k) {
        if (iv[k] == i) {
            v[k] = val;
            set = true;
            break;
        }
    }
    if (!set) {
        nzv++;
        if (nzv > n) {
            // Handle error or resize vector if necessary
            // For simplicity, we'll just ignore the resize for now
            return;
        }
        v[nzv - 1] = val;
        iv[nzv - 1] = i;
    }
}

int main() {
    // Example usage
    int n = 10; // Size of the vectors
    std::vector<double> v(n);
    std::vector<int> iv(n);
    int nzv = 0; // Number of non-zero values
    int i = 5; // Example index
    double val = 1.23; // Example value

    vecset(n, v, iv, nzv, i, val);

    // Output the results for demonstration
    for (int k = 0; k < nzv; ++k) {
        std::cout << "iv[" << k << "] = " << iv[k] << ", v[" << k << "] = " << v[k] << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Function Signature**: The Fortran subroutine is translated to a C++ function with the same name. The parameters are passed by reference to modify them within the function.
2. **Vectors**: The Fortran arrays `v` and `iv` are translated to `std::vector<double>` and `std::vector<int>` in C++, respectively.
3. **Logical Variable**: The Fortran logical variable `set` is translated to a C++ boolean variable.
4. **Loop and Conditions**: The Fortran `do` loop and `if` conditions are translated to C++ `for` loop and `if` statements.
5. **Resizing Logic**: The Fortran code checks if `nzv` exceeds `n` and handles the resize. In C++, this is simplified by checking the size before accessing the vectors.

This C++ code should behave similarly to the original Fortran subroutine.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code.

### Fortran Unit Test

Create a Fortran program to test the `vecset` subroutine:

```fortran
program test_vecset
    implicit none
    integer, parameter :: n = 10
    double precision, dimension(n) :: v
    integer, dimension(n) :: iv
    integer :: nzv, i, k
    double precision :: val
    logical :: set

    ! Initialize vectors
    nzv = 0
    do i = 1, n
        iv(i) = 0
        v(i) = 0.0
    end do

    ! Test case 1: Set a value
    i = 5
    val = 1.23
    call vecset(n, v, iv, nzv, i, val)
    print *, 'Test case 1: nzv =', nzv, 'iv =', iv, 'v =', v

    ! Test case 2: Update a value
    i = 5
    val = 4.56
    call vecset(n, v, iv, nzv, i, val)
    print *, 'Test case 2: nzv =', nzv, 'iv =', iv, 'v =', v

    ! Test case 3: Add a new value
    i = 11
    val = 7.89
    call vecset(n, v, iv, nzv, i, val)
    print *, 'Test case 3: nzv =', nzv, 'iv =', iv, 'v =', v

end program test_vecset
```

### C++ Unit Test

Create a C++ program to test the `vecset` function:

```cpp
#include <iostream>
#include <vector>

void vecset(int n, std::vector<double>& v, std::vector<int>& iv, int& nzv, int i, double val);

int main() {
    // Example usage
    int n = 10; // Size of the vectors
    std::vector<double> v(n, 0.0);
    std::vector<int> iv(n, 0);
    int nzv = 0; // Number of non-zero values

    // Test case 1: Set a value
    int i = 5; // Example index
    double val = 1.23; // Example value
    vecset(n, v, iv, nzv, i, val);
    std::cout << "Test case 1: nzv = " << nzv << ", iv = ";
    for (int k = 0; k < nzv; ++k) std::cout << iv[k] << " ";
    std::cout << ", v = ";
    for (int k = 0; k < nzv; ++k) std::cout << v[k] << " ";
    std::cout << std::endl;

    // Test case 2: Update a value
    i = 5; // Example index
    val = 4.56; // Example value
    vecset(n, v, iv, nzv, i, val);
    std::cout << "Test case 2: nzv = " << nzv << ", iv = ";
    for (int k = 0; k < nzv; ++k) std::cout << iv[k] << " ";
    std::cout << ", v = ";
    for (int k = 0; k < nzv; ++k) std::cout << v[k] << " ";
    std::cout << std::endl;

    // Test case 3: Add a new value
    i = 11; // Example index
    val = 7.89; // Example value
    vecset(n, v, iv, nzv, i, val);
    std::cout << "Test case 3: nzv = " << nzv << ", iv = ";
    for (int k = 0; k < nzv; ++k) std::cout << iv[k] << " ";
    std::cout << ", v = ";
    for (int k = 0; k < nzv; ++k) std::cout << v[k] << " ";
    std::cout << std::endl;

    return 0;
}

void vecset(int n, std::vector<double>& v, std::vector<int>& iv, int& nzv, int i, double val) {
    bool set = false;
    for (int k = 0; k < nzv; ++k) {
        if (iv[k] == i) {
            v[k] = val;
            set = true;
            break;
        }
    }
    if (!set) {
        nzv++;
        if (nzv > n) {
            // Handle error or resize vector if necessary
            // For simplicity, we'll just ignore the resize for now
            return;
        }
        v[nzv - 1] = val;
        iv[nzv - 1] = i;
    }
}
```

### Explanation:

1. **Fortran Test Program**:
   - Initializes the vectors `v` and `iv`.
   - Runs three test cases:
     - Sets a value for the first time.
     - Updates an existing value.
     - Adds a new value.
   - Prints the results for each test case.

2. **C++ Test Program**:
   - Initializes the vectors `v` and `iv`.
   - Runs the same three test cases as the Fortran program.
   - Prints the results for each test case.

### Compilation and Execution:

- **
