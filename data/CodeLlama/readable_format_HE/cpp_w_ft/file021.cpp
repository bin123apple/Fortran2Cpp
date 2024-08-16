Translating the provided Fortran code to C++ involves several steps, including converting the array handling and the logic for removing duplicates. Here's how you can translate the Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<int> remove_duplicates(const std::vector<int>& numbers) {
    std::vector<int> has1, has2, out;

    if (numbers.empty()) return out;

    for (int num : numbers) {
        bool found = false;
        for (int j : has2) {
            if (j == num) {
                found = true;
                break;
            }
        }
        if (found) continue;

        found = false;
        for (int j : has1) {
            if (j == num) {
                found = true;
                break;
            }
        }
        if (found) {
            has2.push_back(num);
        } else {
            has1.push_back(num);
        }
    }

    for (int num : numbers) {
        bool found = false;
        for (int j : has2) {
            if (j == num) {
                found = true;
                break;
            }
        }
        if (!found) {
            out.push_back(num);
        }
    }

    return out;
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void assert_condition(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    assert_condition(issame(remove_duplicates({1, 2, 3, 4}), {1, 2, 3, 4}));
    assert_condition(issame(remove_duplicates({1, 2, 3, 2, 4, 3, 5}), {1, 4, 5}));
    assert_condition(remove_duplicates({}).empty());

    return 0;
}
```

### Explanation:
1. **Array Handling**: In C++, we use `std::vector<int>` to handle arrays dynamically.
2. **Removing Duplicates**: The logic for removing duplicates is preserved, with `has1` and `has2` vectors to track seen numbers.
3. **Assertion**: The `assert_condition` function checks if the condition is true. If not, it prints an error message and exits the program.
4. **Test Cases**: The test cases are implemented directly in the `main` function.

This C++ code should behave similarly to the original Fortran code, ensuring the same functionality and logic for removing duplicates from an array.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program remove_duplicates_program
    implicit none
    integer, dimension(:), allocatable :: numbers, result
    integer :: i
    integer, dimension(0) :: empty_array

    ! Test cases
    call assert(issame(remove_duplicates([1, 2, 3, 4]), [1, 2, 3, 4]))
    call assert(issame(remove_duplicates([1, 2, 3, 2, 4, 3, 5]), [1, 4, 5]))
    call assert(issame(remove_duplicates(empty_array), empty_array))

contains

    function remove_duplicates(numbers) result(out)
        integer, dimension(:), intent(in) :: numbers
        integer, dimension(:), allocatable :: out
        integer, dimension(:), allocatable :: has1, has2
        integer :: i, j, num
        logical :: found

        allocate(has1(0))
        allocate(has2(0))
        allocate(out(0))

        if (size(numbers) == 0) return

        do i = 1, size(numbers)
            num = numbers(i)
            found = .false.
            do j = 1, size(has2)
                if (has2(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (found) cycle

            found = .false.
            do j = 1, size(has1)
                if (has1(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (found) then
                call append(has2, num)
            else
                call append(has1, num)
            end if
        end do

        do i = 1, size(numbers)
            num = numbers(i)
            found = .false.
            do j = 1, size(has2)
                if (has2(j) == num) then
                    found = .true.
                    exit
                end if
            end do
            if (.not. found) then
                call append(out, num)
            end if
        end do
    end function remove_duplicates

    subroutine append(array, value)
        integer, dimension(:), allocatable, intent(inout) :: array
        integer, intent(in) :: value
        integer, dimension(:), allocatable :: temp

        allocate(temp(size(array) + 1))
        temp(1:size(array)) = array
        temp(size(array) + 1) = value
        deallocate(array)
        allocate(array(size(temp)))
        array = temp
    end subroutine append

    function issame(a, b) result(is_equal)
        integer, dimension(:), intent(in) :: a, b
        logical :: is_equal
        integer :: i

        if (size(a) /= size(b)) then
            is_equal = .false.
            return
        end if

        is_equal = .true.
        do i = 1, size(a)
            if (a(i) /= b(i)) then
                is_equal = .false.
                exit
            end if
        end do
    end function issame

    subroutine assert(condition)
        logical, intent(in) :: condition
        if (.not. condition) then
            write(*,*) "Assertion failed"
            call exit(1)
        end if
    end subroutine assert

end program remove_duplicates_program
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<int> remove_duplicates(const std::vector<int>& numbers) {
    std::vector<int> has1, has2, out;

    if (numbers.empty()) return out;

    for (int num : numbers) {
        bool found = false;
        for (int j : has2) {
            if (j == num) {
                found = true;
                break;
            }
        }
        if (found) continue;

        found = false;
        for (int j : has1) {
            if (j == num) {
                found = true;
                break;
            }
        }
        if (found) {
            has2.push_back(num);
        } else {
            has1.push_back(num);
        }
    }

    for (int num : numbers) {
        bool found = false;
        for (int j : has2) {
            if (j == num) {
                found = true;
                break;
            }
        }
        if (!found) {
            out.push_back(num);
        }
    }

    return out;
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
