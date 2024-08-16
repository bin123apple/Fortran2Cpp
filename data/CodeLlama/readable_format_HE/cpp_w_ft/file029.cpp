Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void unique(const std::vector<int>& input, std::vector<int>& result) {
    std::vector<int> temp;
    std::sort(input.begin(), input.end()); // Sort the input array

    // Remove duplicates
    for (int num : input) {
        if (temp.empty() || num != temp.back()) {
            temp.push_back(num);
        }
    }

    result = temp;
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
    std::vector<int> input = {5, 3, 5, 2, 3, 3, 9, 0, 123};
    std::vector<int> expected = {0, 2, 3, 5, 9, 123};
    std::vector<int> result;

    unique(input, result);

    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: result is not as expected" << std::endl;
        return 1;
    }

    return 0;
}
```

### Explanation:
1. **unique Function**: This function removes duplicates from the input vector and stores the unique elements in the result vector. It uses a sorted input vector to efficiently find and remove duplicates.
2. **issame Function**: This function checks if two vectors are identical.
3. **main Function**: The main function initializes the input vector, calls the `unique` function to remove duplicates, and then checks if the result matches the expected vector.

### Notes:
- The `std::sort` function is used to sort the input vector before removing duplicates to ensure that duplicates are adjacent, making it easier to remove them.
- The `issame` function checks if the sizes of the vectors are the same and then compares each element to ensure they are identical.
- The `std::vector` is used to handle dynamic arrays, which is a common practice in C++ for similar scenarios to Fortran's allocatable arrays.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_unique
    implicit none
    integer, allocatable :: input(:), expected(:), result(:)
    logical :: is_same

    ! Input array
    input = [5, 3, 5, 2, 3, 3, 9, 0, 123]
    ! Expected result
    expected = [0, 2, 3, 5, 9, 123]

    ! Call the unique function
    call unique(input, result)

    ! Check if the result is the same as expected
    is_same = issame(result, expected)
    if (.not. is_same) then
        write(*,*) "Assertion failed: result is not as expected"
        call exit(1)
    else
        write(*,*) "Test passed: result is as expected"
    end if

contains

    subroutine unique(l, out)
        integer, intent(in) :: l(:)
        integer, allocatable, intent(out) :: out(:)
        integer, allocatable :: temp(:)
        integer :: i, j, n, count

        ! Allocate temporary array
        allocate(temp(size(l)))
        count = 0

        ! Remove duplicates
        do i = 1, size(l)
            if (.not. any(temp(1:count) == l(i))) then
                count = count + 1
                temp(count) = l(i)
            end if
        end do

        ! Allocate output array with the correct size
        allocate(out(count))
        out = temp(1:count)

        ! Sort the output array
        call sort(out)
    end subroutine unique

    subroutine sort(arr)
        integer, intent(inout) :: arr(:)
        integer :: i, j, temp

        ! Simple bubble sort
        do i = 1, size(arr) - 1
            do j = 1, size(arr) - i
                if (arr(j) > arr(j + 1)) then
                    temp = arr(j)
                    arr(j) = arr(j + 1)
                    arr(j + 1) = temp
                end if
            end do
        end do
    end subroutine sort

    logical function issame(a, b)
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

end program test_unique
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void unique(const std::vector<int>& input, std::vector<int>& result) {
    std::vector<int> temp;
    std::sort(input.begin(), input.end()); // Sort the input array

    // Remove duplicates
    for (int num : input) {
        if (temp.empty() || num != temp.back()) {
            temp.push_back(num);
        }
    }

    result = temp;
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
    std::vector<int> input = {5, 3, 5, 2, 3, 3, 9, 0, 123};
    std::vector<int> expected = {0, 2, 3, 5, 9, 123};
    std::vector<int> result;

    unique(input, result);

    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: result is not as expected" << std::endl;
        return 1;
    } else {
        std::cout << "Test passed: result is as expected" << std::endl;
    }

    return 0;
}
```

### Explanation:
- **Fortran Unit Test**: The Fortran unit test code initializes the input array, calls the `unique` subroutine to remove duplicates, and then checks if the result matches the expected array.
- **C++ Unit Test**: The C++ unit test code does the same operations and checks if the result matches the expected array.

### Compilation and Execution:
- **Fortran**: You can compile the Fortran code using a Fortran compiler like `gfortran`:
  ```sh
  gfortran -o test_unique test_unique.f90
  ./test_unique
  ```
- **C++**: You can compile the C++ code using a C++ compiler like `g++`:
  ```sh
  g++ -o test_unique test_unique.cpp
  ./test_unique
  ```

Both unit tests should output "Test passed: result is as expected" if the implementations are correct.
