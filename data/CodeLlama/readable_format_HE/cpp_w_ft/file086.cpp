Translating the provided Fortran code to C++ involves several steps, including adapting the module and subroutine structure to a class with methods, handling dynamic arrays with vectors, and converting Fortran-specific features to their C++ equivalents. Here's how the code can be translated into C++:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Utils {
public:
    struct NumToType {
        int key;
        std::string value;

        NumToType(int key, const std::string& value) : key(key), value(value) {}
    };

    static void sort_array(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
    }

    static std::vector<std::string> by_length(const std::vector<int>& arr) {
        std::vector<std::string> out;
        std::vector<NumToType> numto = {
            NumToType(0, "Zero"), NumToType(1, "One"), NumToType(2, "Two"),
            NumToType(3, "Three"), NumToType(4, "Four"), NumToType(5, "Five"),
            NumToType(6, "Six"), NumToType(7, "Seven"), NumToType(8, "Eight"),
            NumToType(9, "Nine")
        };

        sort_array(const_cast<std::vector<int>&>(arr));

        for (int i = arr.size() - 1; i >= 0; --i) {
            if (arr[i] >= 1 && arr[i] <= 9) {
                out.push_back(numto[arr[i]].value);
            }
        }

        return out;
    }

    static bool issame(const std::vector<std::string>& a, const std::vector<std::string>& b) {
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
};

int main() {
    std::vector<int> arr = {2, 1, 1, 4, 5, 8, 2, 3};
    std::vector<std::string> result = Utils::by_length(arr);
    std::vector<std::string> expected1 = {"Eight", "Five", "Four", "Three", "Two", "Two", "One", "One"};

    if (!Utils::issame(result, expected1)) {
        std::cerr << "Test 1: assertion failed" << std::endl;
        return 1;
    }

    arr.clear();
    result = Utils::by_length(arr);
    std::vector<std::string> expected2 = {"One"};

    if (!Utils::issame(result, expected2)) {
        std::cerr << "Test 2: assertion failed" << std::endl;
        return 1;
    }

    arr = {1, -1, 55};
    result = Utils::by_length(arr);

    if (!Utils::issame(result, expected2)) {
        std::cerr << "Test 3: assertion failed" << std::endl;
        return 1;
    }

    arr = {1, -1, 3, 2};
    result = Utils::by_length(arr);
    std::vector<std::string> expected3 = {"Three", "Two", "One"};

    if (!Utils::issame(result, expected3)) {
        std::cerr << "Test 4: assertion failed" << std::endl;
        return 1;
    }

    arr = {9, 4, 8};
    result = Utils::by_length(arr);
    std::vector<std::string> expected4 = {"Nine", "Eight", "Four"};

    if (!Utils::issame(result, expected4)) {
        std::cerr << "Test 5: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
```

Key Points:
- The `Utils` class encapsulates the functionality of the Fortran module.
- The `NumToType` struct is used to represent the `numto_type` derived type.
- The `sort_array` method sorts the input vector using `std::sort`.
- The `by_length` method converts numbers to their string representations and sorts them according to the original Fortran logic.
- The `issame` method checks if two vectors of strings are equal.
- The `main` function contains unit tests similar to the Fortran program.

This C++ code should provide similar functionality to the original Fortran code, with adjustments for C++ syntax and conventions.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `by_length` and `issame` functions.

### Fortran Unit Test Code

```fortran
module utils
  implicit none
  type :: numto_type
    integer :: key
    character(len=10) :: value
  end type numto_type
contains
  subroutine sort_array(arr, n)
    integer, intent(inout) :: arr(:)
    integer, intent(in) :: n
    integer :: i, j, temp
    do i = 1, n-1
      do j = i+1, n
        if (arr(i) > arr(j)) then
          temp = arr(i)
          arr(i) = arr(j)
          arr(j) = temp
        end if
      end do
    end do
  end subroutine sort_array

  function by_length(arr, n) result(out)
    integer, intent(inout) :: arr(:)
    integer, intent(in) :: n
    character(len=10), allocatable :: out(:)
    type(numto_type), dimension(10) :: numto
    integer :: i, count

    numto = (/ numto_type(0, "Zero"), numto_type(1, "One"), numto_type(2, "Two"), &
               numto_type(3, "Three"), numto_type(4, "Four"), numto_type(5, "Five"), &
               numto_type(6, "Six"), numto_type(7, "Seven"), numto_type(8, "Eight"), &
               numto_type(9, "Nine") /)

    call sort_array(arr, n)

    count = 0
    do i = n, 1, -1
      if (arr(i) >= 1 .and. arr(i) <= 9) then
        count = count + 1
      end if
    end do

    allocate(out(count))
    count = 0
    do i = n, 1, -1
      if (arr(i) >= 1 .and. arr(i) <= 9) then
        count = count + 1
        out(count) = numto(arr(i) + 1)%value
      end if
    end do
  end function by_length

  logical function issame(a, b, n, m)
    character(len=10), intent(in) :: a(:)
    character(len=10), intent(in) :: b(:)
    integer, intent(in) :: n, m
    integer :: i

    if (n /= m) then
      issame = .false.
      return
    end if

    do i = 1, n
      if (a(i) /= b(i)) then
        issame = .false.
        return
      end if
    end do

    issame = .true.
  end function issame
end module utils

program test
  use utils
  implicit none
  character(len=10), allocatable :: result(:)
  character(len=10), dimension(8) :: expected1
  character(
