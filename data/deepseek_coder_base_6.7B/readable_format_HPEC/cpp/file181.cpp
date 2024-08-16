Certainly! Below is the equivalent C++ code for the provided Fortran subroutine. Note that in Fortran, subroutines are similar to functions in C++, but without a return value. The `call` statements in Fortran correspond to function calls in C++.

Fortran code:
```fortran
subroutine adi

call compute_rhs
call x_solve
call y_solve
call z_solve
call add

return
end
```

Translated C++ code:
```cpp
#include <iostream>

// Assuming the existence of these functions in C++
void compute_rhs();
void x_solve();
void y_solve();
void z_solve();
void add();

void adi() {
    compute_rhs();
    x_solve();
    y_solve();
    z_solve();
    add();
}

int main() {
    adi();
    return 0;
}
```

In this C++ code:
- The Fortran `subroutine` is translated to a C++ function `adi()`.
- The `call` statements in Fortran are translated to function calls in C++.
- The `return` statement in Fortran is not needed in C++ because the end of the function is reached by reaching the end of the function body.
- The `main` function is added to demonstrate how you might call the `adi` function in C++.

Please ensure that the definitions of the functions `compute_rhs`, `x_solve`, `y_solve`, `z_solve`, and `add` are provided in your C++ codebase.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will simply print a message to verify that each function is called.

### Fortran Unit Test Code

First, let's create a Fortran program that calls the `adi` subroutine. We'll also define the subroutines `compute_rhs`, `x_solve`, `y_solve`, `z_solve`, and `add`.

**Fortran Code (adi_test.f90):**
```fortran
program adi_test
    implicit none

    call adi

contains

    subroutine adi
        call compute_rhs
        call x_solve
        call y_solve
        call z_solve
        call add
    end subroutine adi

    subroutine compute_rhs
        print *, "compute_rhs called"
    end subroutine compute_rhs

    subroutine x_solve
        print *, "x_solve called"
    end subroutine x_solve

    subroutine y_solve
        print *, "y_solve called"
    end subroutine y_solve

    subroutine z_solve
        print *, "z_solve called"
    end subroutine z_solve

    subroutine add
        print *, "add called"
    end subroutine add

end program adi_test
```

To compile and run this Fortran code, you can use the following commands (assuming you have a Fortran compiler like gfortran installed):
```sh
gfortran adi_test.f90 -o adi_test
./adi_test
```

### C++ Unit Test Code

Now, let's create a C++ program that calls the `adi` function. We'll also define the functions `compute_rhs`, `x_solve`, `y_solve`, `z_solve`, and `add`.

**C++ Code (adi_test.cpp):**
```cpp
#include <iostream>

// Function declarations
void compute_rhs();
void x_solve();
void y_solve();
void z_solve();
void add();

void adi() {
    compute_rhs();
    x_solve();
    y_solve();
    z_solve();
    add();
}

int main() {
    adi();
    return 0;
}

// Function definitions
void compute_rhs() {
    std::cout << "compute_rhs called" << std::endl;
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

To compile and run this C++ code, you can use the following commands (assuming you have a C++ compiler like g++ installed):
```sh
g++ adi_test.cpp -o adi_test
./adi_test
```

These unit tests will print messages to the console to verify that each function is called in both the Fortran and C++ versions of the code. This approach is a simple way to ensure that the translated C++ code behaves as expected and matches the functionality of the original Fortran code.
