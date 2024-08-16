Certainly! Below is the translated C++ code from the provided Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to find the maximum element in a vector
float max_element(const std::vector<float>& arr) {
    float max_val = -10000.0f;
    for (float num : arr) {
        if (max_val < num) max_val = num;
    }
    return max_val;
}

int main() {
    // Test case 1
    std::vector<float> arr1 = {1.0f, 2.0f, 3.0f};
    float result1 = max_element(arr1);
    if (std::abs(result1 - 3.0f) > 1e-4f) {
        std::cerr << "Test case 1: assertion failed" << std::endl;
        return 1;
    }

    // Test case 2
    std::vector<float> arr2 = {5.0f, 3.0f, -5.0f, 2.0f, -3.0f, 3.0f, 9.0f, 0.0f, 124.0f, 1.0f, -10.0f};
    float result2 = max_element(arr2);
    if (std::abs(result2 - 124.0f) > 1e-4f) {
        std::cerr << "Test case 2: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}
```

### Explanation:
1. **Function Definition**: The `max_element` function is defined to find the maximum element in a `std::vector<float>`.
2. **Main Function**: The `main` function contains two test cases to verify the correctness of the `max_element` function.
3. **Test Cases**:
   - Test case 1 checks if the maximum element in the array `{1.0, 2.0, 3.0}` is correctly identified.
   - Test case 2 checks if the maximum element in the array `{5.0, 3.0, -5.0, 2.0, -3.0, 3.0, 9.0, 0.0, 124.0, 1.0, -10.0}` is correctly identified.
4. **Assertions**: The results are compared with the expected values using assertions. If the results do not match the expected values within a tolerance, the program prints an error message and exits with a non-zero status.

This C++ code should behave similarly to the provided Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
module max_module
  implicit none
contains
  function max_element(arr) result(max_val)
    implicit none
    real, dimension(:), intent(in) :: arr
    real :: max_val
    integer :: i

    max_val = -10000.0
    do i = 1, size(arr)
      if (max_val < arr(i)) max_val = arr(i)
    end do
  end function max_element
end module max_module

program main
  use max_module
  implicit none
  real :: result
  real, dimension(:), allocatable :: arr

  ! Test case 1
  if (allocated(arr)) deallocate(arr)
  allocate(arr(3))
  arr = [1.0, 2.0, 3.0]
  result = max_element(arr)
  if (abs(result - 3.0) > 1e-4) then
    write(*,*) "Test case 1: assertion failed"
    call exit(1)
  end if

  ! Test case 2
  if (allocated(arr)) deallocate(arr)
  allocate(arr(11))
  arr = [5.0, 3.0, -5.0, 2.0, -3.0, 3.0, 9.0, 0.0, 124.0, 1.0, -10.0]
  result = max_element(arr)
  if (abs(result - 124.0) > 1e-4) then
    write(*,*) "Test case 2: assertion failed"
    call exit(1)
  end if

  write(*,*) "All tests passed"
  if (allocated(arr)) deallocate(arr)
end program main
```

### C++ Unit Test Code

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to find the maximum element in a vector
float max_element(const std::vector<float>& arr) {
    float max_val = -10000.0f;
    for (float num : arr) {
        if (max_val < num) max_val = num;
    }
    return max_val;
}

int main() {
    // Test case 1
    std::vector<float> arr1 = {1.0f, 2.0f, 3.0f};
    float result1 = max_element(arr1);
    if (std::abs(result1 - 3.0f) > 1e-4f) {
        std::cerr << "Test case 1: assertion failed" << std::endl;
        return 1;
    }

    // Test case 2
    std::vector<float> arr2 = {5.0f, 3.0f, -5.0f, 2.0f, -3.0f, 3.0f, 9.0f, 0.0f, 124.0f, 1.0f, -10.0f};
    float result2 = max_element(arr2);
    if (std::abs(result2 - 124.0f) > 1e-4f) {
        std::cerr << "Test case 2: assertion failed" << std::endl;
        return 1;
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
   - The Fortran code defines a module `max_module` containing the `max_element` function.
   - The `main` program includes two test cases to verify the correctness of the `max_element` function.
   - It uses an allocatable array to test the function with different input arrays.
   - The results are compared with the expected values using assertions.

2. **C++ Unit Test**:
   - The C++ code defines a function `max_element` to find the maximum element in a vector.
   - The `main` function includes two test cases to verify the correctness of the `max_element` function.
   - It uses `std::vector<float>` to test the function with different input arrays.
   - The results are compared with the expected values using assertions.

These unit tests will help verify the correctness of both the original Fortran code and the translated C++ code.
