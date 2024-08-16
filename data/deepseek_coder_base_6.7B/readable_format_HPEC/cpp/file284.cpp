Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>

// Assuming the existence of these functions based on the Fortran code
extern void timer_start(int t_add);
extern void timer_stop(int t_add);

// Assuming the existence of these variables based on the Fortran code
extern bool timeron;
extern int nx2, ny2, nz2;
extern std::vector<std::vector<std::vector<std::vector<double>>>> u;
extern std::vector<std::vector<std::vector<std::vector<double>>>> rhs;

void add() {
    if (timeron) timer_start(1); // Assuming t_add is 1 in the Fortran code

    for (int k = 1; k <= nz2; ++k) {
        for (int j = 1; j <= ny2; ++j) {
            for (int i = 1; i <= nx2; ++i) {
                for (int m = 1; m <= 5; ++m) {
                    u[m-1][i-1][j-1][k-1] += rhs[m-1][i-1][j-1][k-1];
                }
            }
        }
    }

    if (timeron) timer_stop(1); // Assuming t_add is 1 in the Fortran code
}

int main() {
    // Example initialization of variables
    timeron = true;
    nx2 = 10;
    ny2 = 10;
    nz2 = 10;
    u.resize(5, std::vector<std::vector<std::vector<double>>>(nx2, std::vector<std::vector<double>>(ny2, std::vector<double>(nz2, 0.0))));
    rhs.resize(5, std::vector<std::vector<std::vector<double>>>(nx2, std::vector<std::vector<double>>(ny2, std::vector<double>(nz2, 1.0))));

    add();

    return 0;
}
```

### Explanation:
1. **Function Declarations**:
   - `timer_start` and `timer_stop` are assumed to be external functions based on the Fortran code.
   - `timeron`, `nx2`, `ny2`, `nz2` are assumed to be global variables based on the Fortran code.
   - `u` and `rhs` are assumed to be 4D arrays (vectors of vectors) based on the Fortran code.

2. **add Function**:
   - The `add` function performs the same operations as the Fortran subroutine.
   - It checks if `timeron` is true, starts the timer (assuming `t_add` is 1), and then performs the addition.
   - After the loop, it checks if `timeron` is true, and if so, stops the timer.

3. **Main Function**:
   - An example `main` function is provided to initialize the variables and call the `add` function.

### Assumptions:
- The indices in the `u` and `rhs` arrays are adjusted by `-1` to match C++'s 0-based indexing.
- The `timer_start` and `timer_stop` functions are placeholders and need to be implemented according to your specific requirements.
- The `timeron` variable and other variables are initialized with example values. You should adjust these values according to your actual use case.

This translation assumes that the `timer_start` and `timer_stop` functions are correctly implemented and that the variables `u` and `rhs` are properly initialized before calling the `add` function.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_add
    use sp_data
    implicit none

    integer :: nx2, ny2, nz2
    logical :: timeron
    integer :: t_add
    real, dimension(:,:,:,:), allocatable :: u, rhs

    ! Initialize variables
    nx2 = 10
    ny2 = 10
    nz2 = 10
    timeron = .true.
    t_add = 1

    allocate(u(5, nx2, ny2, nz2))
    allocate(rhs(5, nx2, ny2, nz2))

    ! Initialize arrays
    u = 0.0
    rhs = 1.0

    ! Call the subroutine
    call add

    ! Clean up
    deallocate(u)
    deallocate(rhs)

contains

    subroutine add
        integer :: i, j, k, m

        if (timeron) call timer_start(t_add)
        do k = 1, nz2
            do j = 1, ny2
                do i = 1, nx2
                    do m = 1, 5
                        u(m, i, j, k) = u(m, i, j, k) + rhs(m, i, j, k)
                    end do
                end do
            end do
        end do
        if (timeron) call timer_stop(t_add)
    end subroutine add

    subroutine timer_start(t_add)
        integer :: t_add
        print *, "Timer started for task ", t_add
    end subroutine timer_start

    subroutine timer_stop(t_add)
        integer :: t_add
        print *, "Timer stopped for task ", t_add
    end subroutine timer_stop

end program test_add
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <cassert>

// Assuming the existence of these functions based on the Fortran code
void timer_start(int t_add) {
    std::cout << "Timer started for task " << t_add << std::endl;
}

void timer_stop(int t_add) {
    std::cout << "Timer stopped for task " << t_add << std::endl;
}

// Assuming the existence of these variables based on the Fortran code
bool timeron;
int nx2, ny2, nz2;
std::vector<std::vector<std::vector<std::vector<double>>>> u;
std::vector<std::vector<std::vector<std::vector<double>>>> rhs;

void add() {
    if (timeron) timer_start(1); // Assuming t_add is 1 in the Fortran code

    for (int k = 1; k <= nz2; ++k) {
        for (int j = 1; j <= ny2; ++j) {
            for (int i = 1; i <= nx2; ++i) {
                for (int m = 1; m <= 5; ++m) {
                    u[m-1][i-1][j-1][k-1] += rhs[m-1][i-1][j-1][k-1];
                }
            }
        }
    }

    if (timeron) timer_stop(1); // Assuming t_add is 1 in the Fortran code
}

int main() {
    // Initialize variables
    timeron = true;
    nx2 = 10;
    ny2 = 10;
    nz2 = 10;
    u.resize(5, std::vector<std::vector<std::vector<double>>>(nx2, std::vector<std::vector<double>>(ny2, std::vector<double>(nz2, 0.0))));
    rhs.resize(5, std::vector<std::vector<std::vector<double>>>(nx2, std::vector<std::vector<double>>(ny2, std::vector<double>(nz2, 1.0))));

    add();

    // Check results
    for (int m = 0; m < 5; ++m) {
        for (int i = 0; i < nx2; ++i) {
            for (int j = 0; j < ny2; ++j) {
                for (int k = 0; k <
