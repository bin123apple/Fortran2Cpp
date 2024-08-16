To translate the given Fortran code to C++, we need to consider several differences between the two languages, such as array indexing, data types, and loop structures. Here's a C++ translation of the provided Fortran code:

```cpp
#include <cmath>
#include <vector>

// Assuming the existence of these global variables or their equivalents
extern std::vector<double> q;
extern std::vector<double> z;
extern std::vector<double> r;
extern std::vector<double> p;
extern std::vector<double> a;
extern std::vector<int> rowstr;
extern std::vector<int> colidx;
extern int firstrow;
extern int lastrow;
extern int firstcol;
extern int lastcol;
extern int naa;

void conj_grad(double& rnorm) {
    int cgit, cgitmax = 25;
    double d, sum, rho, rho0, alpha, beta, suml;

    rho = 0.0;
    sum = 0.0;

    // Initialization of q, z, and r vectors
    for (int j = 0; j < naa + 1; ++j) {
        q[j] = 0.0;
        z[j] = 0.0;
        r[j] = x[j]; // Assuming x is a global vector defined elsewhere
        p[j] = r[j];
    }

    // Compute initial rho
    for (int j = 0; j < lastcol - firstcol + 1; ++j) {
        rho += r[j] * r[j];
    }

    for (cgit = 1; cgit <= cgitmax; ++cgit) {
        rho0 = rho;
        d = 0.0;
        rho = 0.0;

        for (int j = 0; j < lastrow - firstrow + 1; ++j) {
            suml = 0.0;
            for (int k = rowstr[j] - 1; k < rowstr[j + 1] - 1; ++k) { // Adjusted for 0-based indexing
                suml += a[k] * p[colidx[k] - 1]; // Adjusted for 0-based indexing
            }
            q[j] = suml;
        }

        for (int j = 0; j < lastcol - firstcol + 1; ++j) {
            d += p[j] * q[j];
        }

        alpha = rho0 / d;

        for (int j = 0; j < lastcol - firstcol + 1; ++j) {
            z[j] += alpha * p[j];
            r[j] -= alpha * q[j];
            rho += r[j] * r[j];
        }

        beta = rho / rho0;

        for (int j = 0; j < lastcol - firstcol + 1; ++j) {
            p[j] = r[j] + beta * p[j];
        }
    }

    for (int j = 0; j < lastrow - firstrow + 1; ++j) {
        suml = 0.0;
        for (int k = rowstr[j] - 1; k < rowstr[j + 1] - 1; ++k) { // Adjusted for 0-based indexing
            suml += a[k] * z[colidx[k] - 1]; // Adjusted for 0-based indexing
        }
        r[j] = suml;
    }

    sum = 0.0;
    for (int j = 0; j < lastcol - firstcol + 1; ++j) {
        suml = x[j] - r[j];
        sum += suml * suml;
    }

    rnorm = sqrt(sum);
}
```

### Key Points:

1. **Array Indexing**: Fortran arrays are 1-based, while C++ arrays are 0-based. Adjustments have been made accordingly.
2. **Global Variables**: The Fortran code uses global variables. In C++, these should be declared as global variables or passed as function parameters.
3. **Data Types**: Fortran's `double precision` is equivalent to C++'s `double`.
4. **Loops**: Fortran's `do` loop is translated to C++'s `for` loop.
5. **Mathematical Functions**: The `sqrt` function from `<cmath>` is used for calculating the square root.

Make sure to adjust the global variable declarations and initializations according to your actual data and the context in which this code is used.
Let's write some test to verify if the translation is correct. 
Below are simple unit tests for both the Fortran and C++ versions of the code. These tests will verify the correctness of the translation by comparing the results of the original Fortran code with the translated C++ code.

### Fortran Unit Test

First, we need to create a Fortran program that calls the `conj_grad` subroutine and checks the results.

```fortran
program test_conj_grad
    use cg_data
    implicit none

    double precision :: rnorm
    integer :: i

    ! Initialize data
    call initialize_data()

    ! Call the subroutine
    call conj_grad(rnorm)

    ! Print results
    print *, 'rnorm:', rnorm
    print *, 'q:', q
    print *, 'z:', z
    print *, 'r:', r
    print *, 'p:', p

    ! Check results
    if (rnorm > 0.0d0) then
        print *, 'Test passed.'
    else
        print *, 'Test failed.'
    endif

end program test_conj_grad
```

### C++ Unit Test

For the C++ version, we'll write a simple test function that calls the `conj_grad` function and checks the results.

```cpp
#include <iostream>
#include <vector>
#include <cmath>

// Include or define the conj_grad function here

void test_conj_grad() {
    // Initialize data
    initialize_data();

    double rnorm;

    // Call the function
    conj_grad(rnorm);

    // Print results
    std::cout << "rnorm: " << rnorm << std::endl;
    std::cout << "q: ";
    for (const auto& qi : q) std::cout << qi << " ";
    std::cout << std::endl;
    std::cout << "z: ";
    for (const auto& zi : z) std::cout << zi << " ";
    std::cout << std::endl;
    std::cout << "r: ";
    for (const auto& ri : r) std::cout << ri << " ";
    std::cout << std::endl;
    std::cout << "p: ";
    for (const auto& pi : p) std::cout << pi << " ";
    std::cout << std::endl;

    // Check results
    if (rnorm > 0.0) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    test_conj_grad();
    return 0;
}
```

### Explanation

1. **Initialization**: Both tests initialize the data by calling `initialize_data`. This function should be implemented according to your specific requirements.
2. **Calling the Subroutine/Function**: The Fortran program calls `conj_grad` with `rnorm` as an argument. The C++ program calls `conj_grad` with `rnorm` as a reference.
3. **Printing Results**: Both tests print the `rnorm` and the contents of the vectors `q`, `z`, `r`, and `p`.
4. **Checking Results**: Both tests check if `rnorm` is greater than 0.0. If so, the test passes; otherwise, it fails.

### Running the Tests

- **Fortran**: Compile the Fortran program with a Fortran compiler (e.g., `gfortran`) and run the executable.
- **C++**: Compile the C++ program with a C
