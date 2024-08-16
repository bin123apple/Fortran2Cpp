To translate the given Fortran code to C++, we need to adapt the Fortran constructs to their C++ equivalents. Here's a C++ version of the code, including the necessary functions and test cases:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to get the Collatz sequence for an odd number
std::vector<int> get_odd_collatz(int n) {
    std::vector<int> out = {1};
    int temp = n;
    int count = 1;
    std::vector<int> temp_array;

    while (temp != 1) {
        if (temp % 2 == 1) {
            count++;
            temp_array.resize(count);
            std::copy(out.begin(), out.end(), temp_array.begin());
            temp_array[count - 1] = temp;
            out = temp_array;
            temp = temp * 3 + 1;
        } else {
            temp = temp / 2;
        }
    }

    std::sort(out.begin(), out.end());
    return out;
}

// Function to check if two vectors are the same
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

// Subroutine to sort a vector
void sort(std::vector<int>& array) {
    std::sort(array.begin(), array.end());
}

// Test function for the odd Collatz sequence
void test_odd_collatz(int n, const std::vector<int>& expected) {
    std::vector<int> result = get_odd_collatz(n);
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed for n = " << n << std::endl;
        std::exit(1);
    }
}

int main() {
    // Test cases
    test_odd_collatz(14, {1, 5, 7, 11, 13, 17});
    test_odd_collatz(5, {1, 5});
    test_odd_collatz(12, {1, 3, 5});
    test_odd_collatz(1, {1});

    return 0;
}
```

This C++ code includes the necessary functions and test cases to replicate the behavior of the original Fortran code. The `get_odd_collatz` function generates the Collatz sequence for an odd number, `issame` checks if two vectors are equal, and `sort` sorts a vector using the standard library's `std::sort` function. The `test_odd_collatz` function runs the test cases, comparing the generated sequence with the expected results, and exits the program with an error if the test fails.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `get_odd_collatz` function in both languages.

### Fortran Unit Test Code

```fortran
program test_collatz
  implicit none

  ! Test cases
  call test_odd_collatz(14, [1, 5, 7, 11, 13, 17])
  call test_odd_collatz(5, [1, 5])
  call test_odd_collatz(12, [1, 3, 5])
  call test_odd_collatz(1, [1])

contains

  subroutine test_odd_collatz(n, expected)
    integer, intent(in) :: n
    integer, dimension(:), intent(in) :: expected
    integer, allocatable :: result(:)
    logical :: is_same

    result = get_odd_collatz(n)
    is_same = issame(result, expected)
    if (.not. is_same) then
      write(*,*) "Assertion failed for n =", n
      call exit(1)
    end if
  end subroutine test_odd_collatz

  function get_odd_collatz(n) result(out)
    integer, intent(in) :: n
    integer, allocatable :: out(:)
    integer :: temp, i, count
    integer, allocatable :: temp_array(:)

    allocate(out(1))
    out(1) = 1
    temp = n
    count = 1

    do while (temp /= 1)
      if (mod(temp, 2) == 1) then
        count = count + 1
        if (allocated(temp_array)) deallocate(temp_array)
        allocate(temp_array(count))
        temp_array(1:count-1) = out
        temp_array(count) = temp
        deallocate(out)
        out = temp_array
        temp = temp * 3 + 1
      else
        temp = temp / 2
      end if
    end do

    call sort(out)
  end function get_odd_collatz

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
        return
      end if
    end do
  end function issame

  subroutine sort(array)
    integer, dimension(:), intent(inout) :: array
    integer :: i, j, temp

    do i = 1, size(array) - 1
      do j = i + 1, size(array)
        if (array(i) > array(j)) then
          temp = array(i)
          array(i) = array(j)
          array(j) = temp
        end if
      end do
    end do
  end subroutine sort

end program test_collatz
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to get the Collatz sequence for an odd number
std::vector<int> get_odd_collatz(int n) {
    std::vector<int> out = {1};
    int temp = n;
    int count = 1;
    std::vector<int> temp_array;

    while (temp != 1) {
        if (temp % 2 == 1) {
            count++;
            temp_array.resize(count);
            std::copy(out.begin(), out.end(), temp_array.begin());
            temp_array[count - 1] = temp;
            out = temp_array;
            temp = temp * 3 + 1;
        } else {
            temp = temp / 2;
        }
    }

    std::sort(out.begin(), out.end());
    return out;
}

// Function to check if two vectors are the same
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

// Subroutine to sort a vector
void sort(std::vector<int>& array) {
    std::sort(array.begin(), array.end());
}

// Test function for the odd Collatz sequence
void test_odd_collatz(int n, const std::vector<int>& expected) {
    std::vector<int> result = get_odd_collatz(n);
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed for n = " << n << std::endl;
