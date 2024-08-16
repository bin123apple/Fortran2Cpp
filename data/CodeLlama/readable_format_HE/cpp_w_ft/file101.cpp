Translating the provided Fortran code to C++ involves several steps, including changing the syntax for loops, arrays, and function definitions. Here's how the Fortran code could be translated into C++:

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

std::string intersection(const std::pair<int, int>& interval1, const std::pair<int, int>& interval2) {
    int inter1 = std::max(interval1.first, interval2.first);
    int inter2 = std::min(interval1.second, interval2.second);
    int l = inter2 - inter1;

    if (l < 2) {
        return "NO";
    }

    for (int i = 2; i <= static_cast<int>(std::sqrt(l)); ++i) {
        if (l % i == 0) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    std::pair<int, int> interval1, interval2;
    std::string result;

    // Test cases
    interval1 = {1, 2};
    interval2 = {2, 3};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        std::cerr << "Assertion failed: intersection([1, 2], [2, 3]) == 'NO'" << std::endl;
        return 1;
    }

    interval1 = {-1, 1};
    interval2 = {0, 4};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        std::cerr << "Assertion failed: intersection([-1, 1], [0, 4]) == 'NO'" << std::endl;
        return 1;
    }

    interval1 = {-3, -1};
    interval2 = {-5, 5};
    result = intersection(interval1, interval2);
    if (result != "YES") {
        std::cerr << "Assertion failed: intersection([-3, -1], [-5, 5]) == 'YES'" << std::endl;
        return 1;
    }

    interval1 = {-2, 2};
    interval2 = {-4, 0};
    result = intersection(interval1, interval2);
    if (result != "YES") {
        std::cerr << "Assertion failed: intersection([-2, 2], [-4, 0]) == 'YES'" << std::endl;
        return 1;
    }

    interval1 = {-11, 2};
    interval2 = {-1, -1};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        std::cerr << "Assertion failed: intersection([-11, 2], [-1, -1]) == 'NO'" << std::endl;
        return 1;
    }

    interval1 = {1, 2};
    interval2 = {3, 5};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        std::cerr << "Assertion failed: intersection([1, 2], [3, 5]) == 'NO'" << std::endl;
        return 1;
    }

    interval1 = {1, 2};
    interval2 = {1, 2};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        std::cerr << "Assertion failed: intersection([1, 2], [1, 2]) == 'NO'" << std::endl;
        return 1;
    }

    interval1 = {-2, -2};
    interval2 = {-3, -2};
    result = intersection(interval1, interval2);
    if (result != "NO") {
        std::cerr << "Assertion failed: intersection([-2, -2], [-3, -2]) == 'NO'" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

Key Points in the Translation:
- The `std::pair<int, int>` type is used to represent the intervals.
- The `std::max` and `std::min` functions are used to find the maximum and minimum values, respectively.
- The `std::sqrt` function is used to calculate the square root.
- The `std::string` type is used to handle the result string.
- The `std::cerr` is used for error output, similar to the `write(*,*)` statement in Fortran.
- The `return` statements are used to exit the function early if a condition is met, similar to the Fortran version.
- The `main` function contains the test cases, which are translated into C++ using `std::pair` for the intervals and `std::string` for the result.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `intersection` function in both languages.

### Fortran Unit Test Code

```fortran
program test_intersection
    implicit none
    character(len=3) :: result
    integer, dimension(2) :: interval1, interval2

    ! Test case 1
    interval1 = [1, 2]
    interval2 = [2, 3]
    result = intersection(interval1, interval2)
    if (result /= 'NO') then
        write(*,*) "Test case 1 failed: Expected 'NO', got '", result, "'"
        stop 1
    end if

    ! Test case 2
    interval1 = [-1, 1]
    interval2 = [0, 4]
    result = intersection(interval1, interval2)
    if (result /= 'NO') then
        write(*,*) "Test case 2 failed: Expected 'NO', got '", result, "'"
        stop 1
    end if

    ! Test case 3
    interval1 = [-3, -1]
    interval2 = [-5, 5]
    result = intersection(interval1, interval2)
    if (result /= 'YES') then
        write(*,*) "Test case 3 failed: Expected 'YES', got '", result, "'"
        stop 1
    end if

    ! Test case 4
    interval1 = [-2, 2]
    interval2 = [-4, 0]
    result = intersection(interval1, interval2)
    if (result /= 'YES') then
        write(*,*) "Test case 4 failed: Expected 'YES', got '", result, "'"
        stop 1
    end if

    ! Test case 5
    interval1 = [-11, 2]
    interval2 = [-1, -1]
    result = intersection(interval1, interval2)
    if (result /= 'NO') then
        write(*,*) "Test case 5 failed: Expected 'NO', got '", result, "'"
        stop 1
    end if

    ! Test case 6
    interval1 = [1, 2]
    interval2 = [3, 5]
    result = intersection(interval1, interval2)
    if (result /= 'NO') then
        write(*,*) "Test case 6 failed: Expected 'NO', got '", result, "'"
        stop 1
    end if

    ! Test case 7
    interval1 = [1, 2]
    interval2 = [1, 2]
    result = intersection(interval1, interval2)
    if (result /= 'NO') then
        write(*,*) "Test case 7 failed: Expected 'NO', got '", result, "'"
        stop 1
    end if

    ! Test case 8
    interval1 = [-2, -2]
    interval2 = [-3, -2]
    result = intersection(interval1, interval2)
    if (result /= 'NO') then
        write(*,*) "Test case 8 failed: Expected 'NO', got '", result, "'"
        stop 1
    end if

    write(*,*) "All tests passed."
end program test_intersection

function intersection(interval1, interval2) result(res)
    implicit none
    integer, dimension(2), intent(in) :: interval1,
