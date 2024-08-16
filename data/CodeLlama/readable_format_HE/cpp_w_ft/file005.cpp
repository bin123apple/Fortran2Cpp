Certainly! Below is the translated C++ code from the provided Fortran code.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sum_product(const std::vector<int>& numbers) {
    int sum = 0;
    int product = 1;

    for (int num : numbers) {
        sum += num;
        product *= num;
    }

    return {sum, product};
}

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

int main() {
    std::vector<int> empty_array;
    std::vector<int> array1 = {1, 1, 1};
    std::vector<int> array2 = {100, 0};
    std::vector<int> array3 = {3, 5, 7};
    std::vector<int> array4 = {10};

    // Test cases
    auto result = sum_product(empty_array);
    if (!issame(result, {0, 1})) {
        std::cerr << "Test case 1 failed" << std::endl;
        return 1;
    }

    result = sum_product(array1);
    if (!issame(result, {3, 1})) {
        std::cerr << "Test case 2 failed" << std::endl;
        return 1;
    }

    result = sum_product(array2);
    if (!issame(result, {100, 0})) {
        std::cerr << "Test case 3 failed" << std::endl;
        return 1;
    }

    result = sum_product(array3);
    if (!issame(result, {3 + 5 + 7, 3 * 5 * 7})) {
        std::cerr << "Test case 4 failed" << std::endl;
        return 1;
    }

    result = sum_product(array4);
    if (!issame(result, {10, 10})) {
        std::cerr << "Test case 5 failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;

    return 0;
}
```

This C++ code includes the `sum_product` function and the `issame` function, which are analogous to the Fortran module's functions. The `main` function contains test cases that verify the correctness of the `sum_product` function and the `issame` function.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `sum_product` and `issame` functions.

### Fortran Unit Test Code

```fortran
module utils
    implicit none
contains
    function sum_product(numbers) result(res)
        implicit none
        integer, dimension(:), intent(in) :: numbers
        integer, dimension(2) :: res
        integer :: i, sum, product

        sum = 0
        product = 1

        do i = 1, size(numbers)
            sum = sum + numbers(i)
            product = product * numbers(i)
        end do

        res = [sum, product]
    end function sum_product

    logical function issame(a, b)
        implicit none
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
end module utils

program main
    use utils
    implicit none
    integer, dimension(:), allocatable :: result
    integer, dimension(:), allocatable :: empty_array
    integer, dimension(3) :: array1 = [1, 1, 1]
    integer, dimension(2) :: array2 = [100, 0]
    integer, dimension(3) :: array3 = [3, 5, 7]
    integer, dimension(1) :: array4 = [10]

    ! Allocate empty array with size 0
    allocate(empty_array(0))

    ! Test cases
    result = sum_product(empty_array)
    if (.not. issame(result, [0, 1])) then
        write(*,*) "Test case 1 failed"
        call exit(1)
    end if

    result = sum_product(array1)
    if (.not. issame(result, [3, 1])) then
        write(*,*) "Test case 2 failed"
        call exit(1)
    end if

    result = sum_product(array2)
    if (.not. issame(result, [100, 0])) then
        write(*,*) "Test case 3 failed"
        call exit(1)
    end if

    result = sum_product(array3)
    if (.not. issame(result, [3 + 5 + 7, 3 * 5 * 7])) then
        write(*,*) "Test case 4 failed"
        call exit(1)
    end if

    result = sum_product(array4)
    if (.not. issame(result, [10, 10])) then
        write(*,*) "Test case 5 failed"
        call exit(1)
    end if

    write(*,*) "All test cases passed"
end program main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sum_product(const std::vector<int>& numbers) {
    int sum = 0;
    int product = 1;

    for (int num : numbers) {
        sum += num;
        product *= num;
    }

    return {sum, product};
}

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

int main() {
    std::vector<int> empty_array;
    std::vector<int> array1 = {1, 1, 1};
    std::vector<int> array2 = {100, 0};
    std::vector<int> array3 = {3, 5, 7};
    std::vector<int> array4 = {10};

    // Test cases
    auto result = sum_product(empty_array);
    if (!issame(result, {0, 1})) {
        std::cerr << "Test case 1 failed" << std::endl;
        return 1;
    }

    result = sum_product(array1);
    if (!issame(result, {3, 1})) {
        std::cerr << "Test case 2 failed" << std::endl;
        return 1;
    }

    result = sum_product(array2);
    if (!issame(result, {100, 0})) {
        std::cerr << "Test case 3 failed" << std::endl;
        return 1;
    }

    result = sum_product(array3);
    if (!issame(result, {3 + 5 + 7, 3 * 5 * 7})) {
        std::cerr << "Test case 4 failed" << std::endl;
        return 1;
    }

    result = sum_product(array4);
