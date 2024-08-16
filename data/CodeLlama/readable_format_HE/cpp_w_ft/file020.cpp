Certainly! Below is the equivalent C++ code for the provided Fortran program. This C++ code includes the necessary headers and uses standard library functions and containers to achieve the same functionality.

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void factorize(int n, std::vector<int>& out) {
    int m = n;
    int count = 0;
    out.clear();

    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); ++i) {
        if (m <= 1) break;
        while (m % i == 0) {
            m /= i;
            ++count;
            out.push_back(i);
        }
    }

    if (m > 1) {
        out.push_back(m);
    }
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    return std::equal(a.begin(), a.end(), b.begin());
}

int main() {
    std::vector<int> factors;
    bool result;

    factorize(2, factors);
    result = issame(factors, {2});
    if (!result) {
        std::cerr << "Assertion failed for factorize(2)" << std::endl;
        return 1;
    }

    factorize(4, factors);
    result = issame(factors, {2, 2});
    if (!result) {
        std::cerr << "Assertion failed for factorize(4)" << std::endl;
        return 1;
    }

    factorize(8, factors);
    result = issame(factors, {2, 2, 2});
    if (!result) {
        std::cerr << "Assertion failed for factorize(8)" << std::endl;
        return 1;
    }

    factorize(3 * 19, factors);
    result = issame(factors, {3, 19});
    if (!result) {
        std::cerr << "Assertion failed for factorize(3 * 19)" << std::endl;
        return 1;
    }

    factorize(3 * 19 * 3 * 19, factors);
    result = issame(factors, {3, 3, 19, 19});
    if (!result) {
        std::cerr << "Assertion failed for factorize(3 * 19 * 3 * 19)" << std::endl;
        return 1;
    }

    factorize(3 * 19 * 3 * 19 * 3 * 19, factors);
    result = issame(factors, {3, 3, 3, 19, 19, 19});
    if (!result) {
        std::cerr << "Assertion failed for factorize(3 * 19 * 3 * 19 * 3 * 19)" << std::endl;
        return 1;
    }

    factorize(3 * 19 * 19 * 19, factors);
    result = issame(factors, {3, 19, 19, 19});
    if (!result) {
        std::cerr << "Assertion failed for factorize(3 * 19 * 19 * 19)" << std::endl;
        return 1;
    }

    factorize(3 * 2 * 3, factors);
    result = issame(factors, {2, 3, 3});
    if (!result) {
        std::cerr << "Assertion failed for factorize(3 * 2 * 3)" << std::endl;
        return 1;
    }

    return 0;
}
```

This C++ code defines the `factorize` function to factorize a number into its prime factors and the `issame` function to compare two vectors of integers. The `main` function then tests the `factorize` function with various inputs and checks the results against expected outcomes.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `factorize` function and the `issame` function.

### Fortran Unit Test Code

```fortran
program test_factorize
    implicit none
    integer, allocatable :: factors(:)
    logical :: result

    ! Test 1: Factorize 2
    call factorize(2, factors)
    result = issame(factors, [2])
    if (.not. result) then
        write(*,*) "Test 1 failed for factorize(2)"
    else
        write(*,*) "Test 1 passed for factorize(2)"
    end if

    ! Test 2: Factorize 4
    call factorize(4, factors)
    result = issame(factors, [2, 2])
    if (.not. result) then
        write(*,*) "Test 2 failed for factorize(4)"
    else
        write(*,*) "Test 2 passed for factorize(4)"
    end if

    ! Test 3: Factorize 8
    call factorize(8, factors)
    result = issame(factors, [2, 2, 2])
    if (.not. result) then
        write(*,*) "Test 3 failed for factorize(8)"
    else
        write(*,*) "Test 3 passed for factorize(8)"
    end if

    ! Test 4: Factorize 3 * 19
    call factorize(3 * 19, factors)
    result = issame(factors, [3, 19])
    if (.not. result) then
        write(*,*) "Test 4 failed for factorize(3 * 19)"
    else
        write(*,*) "Test 4 passed for factorize(3 * 19)"
    end if

    ! Test 5: Factorize 3 * 19 * 3 * 19
    call factorize(3 * 19 * 3 * 19, factors)
    result = issame(factors, [3, 3, 19, 19])
    if (.not. result) then
        write(*,*) "Test 5 failed for factorize(3 * 19 * 3 * 19)"
    else
        write(*,*) "Test 5 passed for factorize(3 * 19 * 3 * 19)"
    end if

    ! Test 6: Factorize 3 * 19 * 3 * 19 * 3 * 19
    call factorize(3 * 19 * 3 * 19 * 3 * 19, factors)
    result = issame(factors, [3, 3, 3, 19, 19, 19])
    if (.not. result) then
        write(*,*) "Test 6 failed for factorize(3 * 19 * 3 * 19 * 3 * 19)"
    else
        write(*,*) "Test 6 passed for factorize(3 * 19 * 3 * 19 * 3 * 19)"
    end if

    ! Test 7: Factorize 3 * 19 * 19 * 19
    call factorize(3 * 19 * 19 * 19, factors)
    result = issame(factors, [3, 19, 19, 19])
    if (.not. result) then
        write(*,*) "Test 7 failed for factorize(3 * 19 * 19 * 19)"
    else
        write(*,*) "Test 7 passed for factorize(3 * 19 * 19 * 19)"
    end if

    ! Test 8: Factorize 3 * 2 * 3
    call factorize(3 * 2 * 3, factors)
    result = issame(factors, [2, 3, 3])
    if (.not. result) then
        write(*,*) "Test 8 failed for factorize(3 * 2 * 3)"
    else
        write(*,*)
