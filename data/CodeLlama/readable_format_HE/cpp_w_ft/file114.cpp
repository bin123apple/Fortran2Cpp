To translate the provided Fortran code to C++, we need to adapt the Fortran constructs to their C++ equivalents. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype> // For std::isdigit

class SpecialFilter {
public:
    static int specialFilter(const std::vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 10) {
                std::string w = std::to_string(nums[i]);
                if (std::isdigit(w[0]) && std::isdigit(w[w.length() - 1])) {
                    num += 1;
                }
            }
        }
        return num;
    }

    static int specialFilterEmpty() {
        return 0;
    }
};

int main() {
    // Test cases
    if (SpecialFilter::specialFilter({5, -2, 1, -5}) != 0) {
        std::cerr << "Test case 1 failed" << std::endl;
        return 1;
    }

    if (SpecialFilter::specialFilter({15, -73, 14, -15}) != 1) {
        std::cerr << "Test case 2 failed" << std::endl;
        return 1;
    }

    if (SpecialFilter::specialFilter({33, -2, -3, 45, 21, 109}) != 2) {
        std::cerr << "Test case 3 failed" << std::endl;
        return 1;
    }

    if (SpecialFilter::specialFilter({43, -12, 93, 125, 121, 109}) != 4) {
        std::cerr << "Test case 4 failed" << std::endl;
        return 1;
    }

    if (SpecialFilter::specialFilter({71, -2, -33, 75, 21, 19}) != 3) {
        std::cerr << "Test case 5 failed" << std::endl;
        return 1;
    }

    if (SpecialFilter::specialFilter({1}) != 0) {
        std::cerr << "Test case 6 failed" << std::endl;
        return 1;
    }

    // Handle empty array case separately
    if (SpecialFilter::specialFilterEmpty() != 0) {
        std::cerr << "Test case 7 failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

### Explanation:
1. **Class Definition**: The `SpecialFilter` class in C++ encapsulates the functionality of the Fortran module.
2. **Static Methods**: The `specialFilter` and `specialFilterEmpty` functions are defined as static methods within the `SpecialFilter` class. This allows them to be called without instantiating the class.
3. **Vector for Arrays**: Fortran arrays are translated to `std::vector<int>` in C++ for dynamic array handling.
4. **String Conversion**: The Fortran `write` statement used for string conversion is replaced by `std::to_string` in C++.
5. **Character Checks**: The Fortran character checks are replaced by `std::isdigit` from `<cctype>` in C++ to check if the first and last characters are digits.
6. **Test Cases**: The test cases are implemented directly in the `main` function.

This C++ code should provide the same functionality as the original Fortran code, with the necessary adaptations for the differences between the two languages.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
module special_filter_module
    implicit none
contains

    function specialFilter(nums) result(num)
        integer, dimension(:), intent(in) :: nums
        integer :: num
        integer :: i
        character(len=20) :: w

        num = 0
        do i = 1, size(nums)
            if (nums(i) > 10) then
                write(w, '(I0)') nums(i)
                if (mod(iachar(w(1:1)), 2) == 1 .and. mod(iachar(w(len_trim(w):len_trim(w))), 2) == 1) then
                    num = num + 1
                end if
            end if
        end do
    end function specialFilter

    function specialFilterEmpty() result(num)
        integer :: num
        num = 0
    end function specialFilterEmpty

end module special_filter_module

program special_filter_program
    use special_filter_module
    implicit none
    integer :: result

    ! Test cases
    result = specialFilter([5, -2, 1, -5])
    if (result /= 0) then
        write(*,*) "Test case 1 failed"
        call exit(1)
    end if

    result = specialFilter([15, -73, 14, -15])
    if (result /= 1) then
        write(*,*) "Test case 2 failed"
        call exit(1)
    end if

    result = specialFilter([33, -2, -3, 45, 21, 109])
    if (result /= 2) then
        write(*,*) "Test case 3 failed"
        call exit(1)
    end if

    result = specialFilter([43, -12, 93, 125, 121, 109])
    if (result /= 4) then
        write(*,*) "Test case 4 failed"
        call exit(1)
    end if

    result = specialFilter([71, -2, -33, 75, 21, 19])
    if (result /= 3) then
        write(*,*) "Test case 5 failed"
        call exit(1)
    end if

    result = specialFilter([1])
    if (result /= 0) then
        write(*,*) "Test case 6 failed"
        call exit(1)
    end if

    ! Handle empty array case separately
    result = specialFilterEmpty()
    if (result /= 0) then
        write(*,*) "Test case 7 failed"
        call exit(1)
    end if

    write(*,*) "All test cases passed"
end program special_filter_program
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cctype> // For std::isdigit

class SpecialFilter {
public:
    static int specialFilter(const std::vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 10) {
                std::string w = std::to_string(nums[i]);
                if (std::isdigit(w[0]) && std::isdigit(w[w.length() - 1])) {
                    num += 1;
                }
            }
        }
        return num;
    }

    static int specialFilterEmpty() {
        return 0;
    }
};

int main() {
    // Test cases
    if (SpecialFilter::specialFilter({5, -2, 1, -5}) != 0) {
        std::cerr << "Test case 1 failed" << std::endl;
        return 1;
    }

    if (SpecialFilter::specialFilter({15, -73, 14, -15}) != 1) {
        std::cerr << "Test case 2 failed" << std::endl;
        return 1;
    }

    if (SpecialFilter::specialFilter({33, -2, -3, 45, 21, 1
