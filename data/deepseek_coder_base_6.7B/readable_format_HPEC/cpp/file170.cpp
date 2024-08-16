Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>

// Forward declarations of the functions
void compute_rhs();
void txinvr();
void x_solve();
void y_solve();
void z_solve();
void add();

// The main function that calls the other functions
int main() {
    compute_rhs();
    txinvr();
    x_solve();
    y_solve();
    z_solve();
    add();
    return 0;
}

// Definition of the functions
void compute_rhs() {
    // Function implementation
}

void txinvr() {
    // Function implementation
}

void x_solve() {
    // Function implementation
}

void y_solve() {
    // Function implementation
}

void z_solve() {
    // Function implementation
}

void add() {
    // Function implementation
}
```

### Explanation:
1. **Function Declarations:** In C++, functions are declared before the `main` function or any other function. This is done by specifying the return type (`void` in this case since the functions do not return any value), the function name, and the parameters (if any).

2. **Main Function:** The `main` function is the entry point of the C++ program. It calls the other functions in the same order as they are defined.

3. **Function Definitions:** The actual implementation of the functions is not provided in the original Fortran code snippet, so I've left them empty in the C++ translation. You would fill in the function bodies with the appropriate logic.

4. **Return Statement:** In C++, the `return 0;` statement at the end of the `main` function indicates that the program has executed successfully.

Remember to fill in the actual implementations of the functions `compute_rhs`, `txinvr`, `x_solve`, `y_solve`, `z_solve`, and `add` with the appropriate logic as per your requirements.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the translation by checking if the functions are called in the correct order.

### Fortran Unit Test Code

```fortran
program test_adi
    implicit none

    call adi

contains

    subroutine adi
        call compute_rhs
        call txinvr
        call x_solve
        call y_solve
        call z_solve
        call add
    end subroutine adi

    subroutine compute_rhs
        print *, 'compute_rhs called'
    end subroutine compute_rhs

    subroutine txinvr
        print *, 'txinvr called'
    end subroutine txinvr

    subroutine x_solve
        print *, 'x_solve called'
    end subroutine x_solve

    subroutine y_solve
        print *, 'y_solve called'
    end subroutine y_solve

    subroutine z_solve
        print *, 'z_solve called'
    end subroutine z_solve

    subroutine add
        print *, 'add called'
    end subroutine add

end program test_adi
```

### C++ Unit Test Code

```cpp
#include <iostream>

// Forward declarations of the functions
void compute_rhs();
void txinvr();
void x_solve();
void y_solve();
void z_solve();
void add();

// The main function that calls the other functions
int main() {
    compute_rhs();
    txinvr();
    x_solve();
    y_solve();
    z_solve();
    add();
    return 0;
}

// Definition of the functions
void compute_rhs() {
    std::cout << "compute_rhs called" << std::endl;
}

void txinvr() {
    std::cout << "txinvr called" << std::endl;
}

void x_solve() {
    std::cout << "x_solve called" << std::endl;
}

void y_solve() {
    std::cout << "y_solve called" << std::endl;
}

void z_solve() {
    std::cout << "z_solve called" << std::endl;
}

void add() {
    std::cout << "add called" << std::endl;
}
```

### Explanation:

1. **Fortran Unit Test Code:**
    - The `test_adi` program calls the `adi` subroutine.
    - The `adi` subroutine calls the other subroutines in the correct order.
    - Each subroutine prints a message to verify that it has been called.

2. **C++ Unit Test Code:**
    - The `main` function calls the other functions in the correct order.
    - Each function prints a message to verify that it has been called.

### Running the Tests:

- **Fortran:**
    - Save the Fortran code to a file, e.g., `test_adi.f90`.
    - Compile the code using a Fortran compiler, e.g., `gfortran -o test_adi test_adi.f90`.
    - Run the executable, e.g., `./test_adi`.

- **C++:**
    - Save the C++ code to a file, e.g., `test_adi.cpp`.
    - Compile the code using a C++ compiler, e.g., `g++ -o test_adi test_adi.cpp`.
    - Run the executable, e.g., `./test_adi`.

### Expected Output:

For both Fortran and C++, the expected output should be:

```
compute_rhs called
txinvr called
x_solve called
y_solve called
z_solve called
add called
```

This output verifies that the functions are called in the correct order, confirming the correctness of the translation.
