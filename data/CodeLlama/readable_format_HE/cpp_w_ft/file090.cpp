Translating the provided Fortran code to C++ involves several steps, including adapting the module and program structure, converting Fortran intrinsic functions and control structures to their C++ equivalents, and handling array allocation and deallocation. Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

bool move_one_ball(const std::vector<int>& arr) {
    int num = 0;
    if (arr.size() == 0) {
        return true;
    }

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            num++;
        }
    }

    if (arr.back() > arr[0]) {
        num++;
    }

    return num < 2;
}

int main() {
    std::vector<int> arr;
    bool result;

    // Test cases
    arr = {3, 4, 5, 1, 2};
    result = move_one_ball(arr);
    if (!result) {
        std::cerr << "Assertion failed for {3, 4, 5, 1, 2}" << std::endl;
        std::exit(1);
    }

    arr = {3, 5, 10, 1, 2};
    result = move_one_ball(arr);
    if (!result) {
        std::cerr << "Assertion failed for {3, 5, 10, 1, 2}" << std::endl;
        std::exit(1);
    }

    arr = {4, 3, 1, 2};
    result = move_one_ball(arr);
    if (result) {
        std::cerr << "Assertion failed for {4, 3, 1, 2}" << std::endl;
        std::exit(1);
    }

    arr = {3, 5, 4, 1, 2};
    result = move_one_ball(arr);
    if (result) {
        std::cerr << "Assertion failed for {3, 5, 4, 1, 2}" << std::endl;
        std::exit(1);
    }

    arr = {}; // Empty vector
    result = move_one_ball(arr);
    if (!result) {
        std::cerr << "Assertion failed for {}" << std::endl;
        std::exit(1);
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

Key Points in the Translation:

1. **Module and Program Structure**: Fortran modules are translated to C++ functions or classes. The `main` program is the `main` function in C++.

2. **Array Handling**: Fortran's array handling is replaced with `std::vector<int>` in C++ for dynamic array functionality.

3. **Looping and Conditionals**: Fortran's `do` loop and `if` statements are replaced with C++ `for` loop and `if` statements.

4. **Logical Function**: The Fortran logical function `move_one_ball` is translated to a C++ function returning `bool`.

5. **Error Handling**: Fortran's `write` and `exit` are replaced with `std::cerr` for error output and `std::exit` for terminating the program with an error code.

6. **Array Allocation and Deallocation**: In C++, `std::vector` handles memory allocation and deallocation automatically.

This translation maintains the logic and structure of the original Fortran code while adapting it to C++ conventions and idioms.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `move_one_ball` function in both languages.

### Fortran Unit Test Code

```fortran
module ball_module
  implicit none
contains
  logical function move_one_ball(arr)
    implicit none
    integer, dimension(:), intent(in) :: arr
    integer :: i, num

    num = 0
    if (size(arr) == 0) then
      move_one_ball = .true.
      return
    end if

    do i = 2, size(arr)
      if (arr(i) < arr(i-1)) num = num + 1
    end do

    if (arr(size(arr)) > arr(1)) num = num + 1

    if (num < 2) then
      move_one_ball = .true.
    else
      move_one_ball = .false.
    end if
  end function move_one_ball
end module ball_module

program main
  use ball_module
  implicit none
  integer, dimension(:), allocatable :: arr
  logical :: result

  ! Test cases
  allocate(arr(5))
  arr = [3, 4, 5, 1, 2]
  result = move_one_ball(arr)
  if (.not. result) then
    write(*,*) "Assertion failed for {3, 4, 5, 1, 2}"
    call exit(1)
  end if

  deallocate(arr)
  allocate(arr(5))
  arr = [3, 5, 10, 1, 2]
  result = move_one_ball(arr)
  if (.not. result) then
    write(*,*) "Assertion failed for {3, 5, 10, 1, 2}"
    call exit(1)
  end if

  deallocate(arr)
  allocate(arr(4))
  arr = [4, 3, 1, 2]
  result = move_one_ball(arr)
  if (result) then
    write(*,*) "Assertion failed for {4, 3, 1, 2}"
    call exit(1)
  end if

  deallocate(arr)
  allocate(arr(5))
  arr = [3, 5, 4, 1, 2]
  result = move_one_ball(arr)
  if (result) then
    write(*,*) "Assertion failed for {3, 5, 4, 1, 2}"
    call exit(1)
  end if

  deallocate(arr)
  allocate(arr(0))
  result = move_one_ball(arr)
  if (.not. result) then
    write(*,*) "Assertion failed for {}"
    call exit(1)
  end if

  write(*,*) "All tests passed."
end program main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

bool move_one_ball(const std::vector<int>& arr) {
    int num = 0;
    if (arr.size() == 0) {
        return true;
    }

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            num++;
        }
    }

    if (arr.back() > arr[0]) {
        num++;
    }

    return num < 2;
}

int main() {
    std::vector<int> arr;
    bool result;

    // Test cases
    arr = {3, 4, 5, 1, 2};
    result = move_one_ball(arr);
    if (!result) {
        std::cerr << "Assertion failed for {3, 4, 5, 1, 2}" << std::endl;
        std::exit(1);
    }

    arr = {3, 5, 10, 1, 2};
    result = move_one_ball(arr);
    if (!result) {
        std::cerr << "Assertion failed for {3, 5, 10, 1, 2}" << std::endl;
        std::exit(1);
    }

    arr = {4, 3, 1,
