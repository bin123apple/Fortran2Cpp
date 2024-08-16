Certainly! Below is the equivalent C++ code for the provided Fortran program. This C++ code uses the standard library and algorithms to achieve the same functionality.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

void parse_nested_parens(const std::string& paren_string, std::vector<int>& all_levels) {
    int level = 0;
    int max_level = 0;
    all_levels.clear();

    for (char chr : paren_string) {
        if (chr == '(') {
            level++;
            if (level > max_level) max_level = level;
        } else if (chr == ')') {
            level--;
            if (level == 0) {
                all_levels.push_back(max_level);
                max_level = 0;
            }
        }
    }
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    return std::equal(a.begin(), a.end(), b.begin());
}

int main() {
    std::string paren_string;
    std::vector<int> result;
    std::vector<int> expected1 = {2, 3, 1, 3};
    std::vector<int> expected2 = {1, 2, 3, 4};
    std::vector<int> expected3 = {4};
    bool is_same;

    paren_string = "(()()) ((())) () ((())()())";
    parse_nested_parens(paren_string, result);
    is_same = issame(result, expected1);
    if (!is_same) {
        std::cerr << "Assertion failed for test case 1" << std::endl;
        return 1;
    }

    paren_string = "() (()) ((())) (((())))";
    parse_nested_parens(paren_string, result);
    is_same = issame(result, expected2);
    if (!is_same) {
        std::cerr << "Assertion failed for test case 2" << std::endl;
        return 1;
    }

    paren_string = "(()(())((())))";
    parse_nested_parens(paren_string, result);
    is_same = issame(result, expected3);
    if (!is_same) {
        std::cerr << "Assertion failed for test case 3" << std::endl;
        return 1;
    }

    return 0;
}
```

This C++ code defines a function `parse_nested_parens` to parse the nested parentheses in a string and another function `issame` to compare two vectors. The `main` function contains the test cases similar to the Fortran program.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `parse_nested_parens` function and the `issame` function.

### Fortran Unit Test Code

Here is the Fortran unit test code that you can compile and run to test the functionality:

```fortran
program test_nested_parens
    implicit none
    character(len=100) :: paren_string
    integer, dimension(:), allocatable :: result
    integer, dimension(4) :: expected1 = [2, 3, 1, 3]
    integer, dimension(4) :: expected2 = [1, 2, 3, 4]
    integer, dimension(1) :: expected3 = [4]
    logical :: is_same

    ! Test case 1
    paren_string = '(()()) ((())) () ((())()())'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected1)
    if (.not. is_same) then
        write(*,*) "Test case 1 failed"
    else
        write(*,*) "Test case 1 passed"
    end if

    ! Test case 2
    paren_string = '() (()) ((())) (((())))'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected2)
    if (.not. is_same) then
        write(*,*) "Test case 2 failed"
    else
        write(*,*) "Test case 2 passed"
    end if

    ! Test case 3
    paren_string = '(()(())((())))'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected3)
    if (.not. is_same) then
        write(*,*) "Test case 3 failed"
    else
        write(*,*) "Test case 3 passed"
    end if

contains

    subroutine parse_nested_parens(paren_string, all_levels)
        character(len=*), intent(in) :: paren_string
        integer, dimension(:), allocatable, intent(out) :: all_levels
        integer :: level, max_level, i, n
        character(len=1) :: chr
        integer, dimension(:), allocatable :: temp_levels

        level = 0
        max_level = 0
        n = len_trim(paren_string)
        allocate(temp_levels(n))
        temp_levels = 0

        do i = 1, n
            chr = paren_string(i:i)
            if (chr == '(') then
                level = level + 1
                if (level > max_level) max_level = level
            else if (chr == ')') then
                level = level - 1
                if (level == 0) then
                    temp_levels(i) = max_level
                    max_level = 0
                end if
            end if
        end do

        ! Filter out zeros and allocate the result array
        allocate(all_levels(count(temp_levels /= 0)))
        all_levels = pack(temp_levels, temp_levels /= 0)
    end subroutine parse_nested_parens

    logical function issame(a, b)
        integer, dimension(:), intent(in) :: a, b
        integer :: i

        if (size(a) /= size(b)) then
            issame = .false.
            return
        end if

        do i = 1, size(a)
            if (a(i) /= b(i)) then
                issame = .false.
                return
            end if
        end do

        issame = .true.
    end function issame

end program test_nested_parens
```

### C++ Unit Test Code

Here is the C++ unit test code that you can compile and run to test the functionality:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

void parse_nested_parens(const std::string& paren_string, std::vector<int>& all_levels) {
    int level = 0;
    int max_level = 0;
    all_levels.clear();

    for (char chr : paren_string) {
        if (chr == '(') {
            level++;
            if (level > max_level) max_level = level;
        } else if (chr == ')') {
            level--;
            if (level == 0) {
                all_levels.push_back(max_level);
                max_level = 0;
            }
        }
    }
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    return std::equal(a.begin(), a.end(), b.begin());
}

void run_test(const std::string& paren_string, const std::vector<int>& expected, const std::string& test_name) {
    std::vector<int> result;
    parse_nested_parens(paren_string, result);
    if (
