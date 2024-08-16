Translating the given Fortran code to C++ involves several steps, including handling dynamic arrays, searching, and module functionalities. Below is the translated C++ code:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Utility functions
void extend_array(std::vector<std::vector<int>>& array, int new_size) {
    std::vector<std::vector<int>> temp(array.size(), std::vector<int>(new_size));
    for (size_t i = 0; i < array.size(); ++i) {
        for (size_t j = 0; j < array[i].size(); ++j) {
            temp[i][j] = array[i][j];
        }
    }
    array = temp;
}

int search(const std::vector<int>& lst) {
    std::vector<std::vector<int>> freq(2, std::vector<int>(0));
    int max = -1;
    bool has;

    for (int i = 0; i < lst.size(); ++i) {
        has = false;
        for (size_t j = 0; j < freq[1].size(); ++j) {
            if (lst[i] == freq[0][j]) {
                freq[1][j] += 1;
                has = true;
                if (freq[1][j] >= freq[0][j] && freq[0][j] > max) {
                    max = freq[0][j];
                }
            }
        }
        if (!has) {
            freq[0].push_back(lst[i]);
            freq[1].push_back(1);
            if (max == -1 && lst[i] == 1) {
                max = 1;
            }
        }
    }
    return max;
}

int main() {
    std::vector<int> test_case1 = {5, 5, 5, 5, 1};
    if (search(test_case1) != 1) {
        std::cerr << "Assertion failed: search([5, 5, 5, 5, 1]) == 1" << std::endl;
        return 1;
    }

    std::vector<int> test_case2 = {4, 1, 4, 1, 4, 4};
    if (search(test_case2) != 4) {
        std::cerr << "Assertion failed: search([4, 1, 4, 1, 4, 4]) == 4" << std::endl;
        return 1;
    }

    std::vector<int> test_case3 = {3, 3};
    if (search(test_case3) != -1) {
        std::cerr << "Assertion failed: search([3, 3]) == -1" << std::endl;
        return 1;
    }

    std::vector<int> test_case4 = {8, 8, 8, 8, 8, 8, 8, 8};
    if (search(test_case4) != 8) {
        std::cerr << "Assertion failed: search([8, 8, 8, 8, 8, 8, 8, 8]) == 8" << std::endl;
        return 1;
    }

    std::vector<int> test_case5 = {2, 3, 3, 2, 2};
    if (search(test_case5) != 2) {
        std::cerr << "Assertion failed: search([2, 3, 3, 2, 2]) == 2" << std::endl;
        return 1;
    }

    // Add more test cases as needed...

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

### Explanation:

1. **Dynamic Arrays**: In C++, `std::vector` is used to handle dynamic arrays. The `extend_array` function extends the 2D vector by adding a new column.

2. **Search Function**: The `search` function iterates through the input array and updates the frequency map. It returns the maximum element that occurs more than once.

3. **Main Function**: The `main` function contains several test cases to verify the correctness of the `search` function.

This C++ code should provide the same functionality as the original Fortran code. You can add more test cases to further verify the correctness of the translation.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
module utils
    implicit none
contains
    subroutine extend_array(array, new_size)
        implicit none
        integer, dimension(:,:), allocatable, intent(inout) :: array
        integer, intent(in) :: new_size
        integer, dimension(:,:), allocatable :: temp

        allocate(temp(size(array, 1), new_size))
        temp(:, 1:size(array, 2)) = array
        array = temp
    end subroutine extend_array

    function search(lst) result(max)
        implicit none
        integer, dimension(:), intent(in) :: lst
        integer :: max
        integer, dimension(:,:), allocatable :: freq
        integer :: i, j, n, freq_size
        logical :: has

        max = -1
        freq_size = 0
        allocate(freq(2, 0))

        do i = 1, size(lst)
            has = .false.
            do j = 1, freq_size
                if (lst(i) == freq(1, j)) then
                    freq(2, j) = freq(2, j) + 1
                    has = .true.
                    if (freq(2, j) >= freq(1, j) .and. freq(1, j) > max) max = freq(1, j)
                end if
            end do
            if (.not. has) then
                freq_size = freq_size + 1
                call extend_array(freq, freq_size)
                freq(1, freq_size) = lst(i)
                freq(2, freq_size) = 1
                if (max == -1 .and. lst(i) == 1) max = 1
            end if
        end do
    end function search
end module utils

program main
    use utils
    implicit none
    integer :: result

    result = search([5, 5, 5, 5, 1])
    if (result /= 1) then
        write(*,*) "Assertion failed: search([5, 5, 5, 5, 1]) == 1"
        call exit(1)
    end if

    result = search([4, 1, 4, 1, 4, 4])
    if (result /= 4) then
        write(*,*) "Assertion failed: search([4, 1, 4, 1, 4, 4]) == 4"
        call exit(1)
    end if

    result = search([3, 3])
    if (result /= -1) then
        write(*,*) "Assertion failed: search([3, 3]) == -1"
        call exit(1)
    end if

    result = search([8, 8, 8, 8, 8, 8, 8, 8])
    if (result /= 8) then
        write(*,*) "Assertion failed: search([8, 8, 8, 8, 8, 8, 8, 8]) == 8"
        call exit(1)
    end if

    result = search([2, 3, 3, 2, 2])
    if (result /= 2) then
        write(*,*) "Assertion failed: search([2, 3, 3, 2, 2]) == 2"
        call exit(1)
    end if

    ! Add more assertions as needed...

    write(*,*) "All
