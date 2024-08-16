Translating the provided Fortran code to C++ involves several steps, including handling dynamic arrays, sorting, and checking for equality between arrays. Below is the translated C++ code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to sort an array
void sort(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

// Function to check if two arrays are the same
bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

// Function to find the common elements between two arrays
void common(const std::vector<int>& l1, const std::vector<int>& l2, std::vector<int>& out) {
    std::vector<int> temp(l1.size());
    size_t n = 0;

    for (size_t i = 0; i < l1.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < n; ++j) {
            if (temp[j] == l1[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            if (std::any_of(l2.begin(), l2.end(), [&l1, i](int val) { return val == l1[i]; })) {
                temp[n] = l1[i];
                ++n;
            }
        }
    }

    if (n > 0) {
        sort(temp);
        out = std::vector<int>(temp.begin(), temp.begin() + n);
    } else {
        out.clear();
    }
}

int main() {
    // Test case 1
    std::vector<int> l1 = {1, 4, 3, 34, 653, 2, 5};
    std::vector<int> l2 = {5, 7, 1, 5, 9, 653, 121};
    std::vector<int> expected = {1, 5, 653};
    std::vector<int> result;
    common(l1, l2, result);
    if (!issame(result, expected)) {
        std::cerr << "Test case 1 failed" << std::endl;
        return 1;
    }

    // Test case 2
    l1 = {5, 3, 2, 8};
    l2 = {3, 2};
    expected = {2, 3};
    common(l1, l2, result);
    if (!issame(result, expected)) {
        std::cerr << "Test case 2 failed" << std::endl;
        return 1;
    }

    // Test case 3
    l1 = {4, 3, 2, 8};
    l2 = {3, 2, 4};
    expected = {2, 3, 4};
    common(l1, l2, result);
    if (!issame(result, expected)) {
        std::cerr << "Test case 3 failed" << std::endl;
        return 1;
    }

    // Test case 4
    l1 = {4, 3, 2, 8};
    l2.clear();
    expected.clear();
    common(l1, l2, result);
    if (!issame(result, expected)) {
        std::cerr << "Test case 4 failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

This C++ code includes the necessary functions to perform the same operations as the Fortran code. It uses `std::vector` for dynamic arrays and `std::sort` for sorting. The `issame` function checks if two vectors are equal, and the `common` function finds the common elements between two arrays, similar to the Fortran version. The `main` function contains test cases to verify the correctness of the translation.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `common` and `sort` functions, as well as the `issame` function.

### Fortran Unit Test Code

```fortran
module common_module
    implicit none
    contains

    subroutine common(l1, l2, out)
        implicit none
        integer, intent(in) :: l1(:), l2(:)
        integer, allocatable, intent(out) :: out(:)
        integer :: i, j, n
        logical :: found
        integer, allocatable :: temp(:)

        allocate(temp(size(l1)))
        n = 0

        do i = 1, size(l1)
            found = .false.
            do j = 1, n
                if (temp(j) == l1(i)) then
                    found = .true.
                    exit
                end if
            end do
            if (.not. found) then
                if (any(l2 == l1(i))) then
                    n = n + 1
                    temp(n) = l1(i)
                end if
            end if
        end do

        if (n > 0) then
            call sort(temp(1:n))
            allocate(out(n))
            out = temp(1:n)
        else
            allocate(out(0))
        end if

        deallocate(temp)
    end subroutine common

    subroutine sort(arr)
        implicit none
        integer, intent(inout) :: arr(:)
        integer :: i, j, temp

        do i = 1, size(arr) - 1
            do j = i + 1, size(arr)
                if (arr(i) > arr(j)) then
                    temp = arr(i)
                    arr(i) = arr(j)
                    arr(j) = temp
                end if
            end do
        end do
    end subroutine sort

    logical function issame(a, b)
        implicit none
        integer, intent(in) :: a(:), b(:)
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

end module common_module

program test_common
    use common_module
    implicit none
    integer, allocatable :: l1(:), l2(:), result(:), expected(:)
    logical :: is_same

    ! Test case 1
    l1 = [1, 4, 3, 34, 653, 2, 5]
    l2 = [5, 7, 1, 5, 9, 653, 121]
    expected = [1, 5, 653]
    call common(l1, l2, result)
    is_same = issame(result, expected)
    if (.not. is_same) then
        write(*,*) "Test case 1 failed"
        call exit(1)
    end if

    ! Test case 2
    l1 = [5, 3, 2, 8]
    l2 = [3, 2]
    expected = [2, 3]
    call common(l1, l2, result)
    is_same = issame(result, expected)
    if (.not. is_same) then
        write(*,*) "Test case 2 failed"
        call exit(1)
    end if

    ! Test case 3
    l1 = [4, 3, 2, 8]
    l2 = [3, 2, 4]
    expected
