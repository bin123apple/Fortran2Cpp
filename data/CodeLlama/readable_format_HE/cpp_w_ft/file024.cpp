Translating the provided Fortran code to C++ involves several steps, including adapting the array handling and string manipulation to C++ conventions. Here's a C++ version of the Fortran code:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> filter_by_prefix(const std::vector<std::string>& strings, const std::string& prefix) {
    std::vector<std::string> out;
    for (const auto& str : strings) {
        if (str.substr(0, prefix.size()) == prefix) {
            out.push_back(str);
        }
    }
    return out;
}

void add_to_array(std::vector<std::string>& array, const std::string& element) {
    array.push_back(element);
}

bool issame(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    return std::equal(a.begin(), a.end(), b.begin());
}

void test_cases() {
    // Test case 1
    std::vector<std::string> strings;
    std::string prefix = "john";
    auto result = filter_by_prefix(strings, prefix);
    if (!issame(result, strings)) {
        std::cerr << "Assertion failed: filter_by_prefix({}, 'john')" << std::endl;
        std::exit(1);
    }

    // Test case 2
    strings = {"xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     "};
    prefix = "xxx";
    result = filter_by_prefix(strings, prefix);
    std::vector<std::string> expected = {"xxx     ", "xxxAAA  ", "xxx     "};
    if (!issame(result, expected)) {
        std::cerr << "Assertion failed: filter_by_prefix({'xxx', 'asd', 'xxy', 'john doe', 'xxxAAA', 'xxx'}, 'xxx')" << std::endl;
        std::exit(1);
    }
}

int main() {
    test_cases();
    return 0;
}
```

### Key Points:

1. **Array Handling**: C++ uses `std::vector` for dynamic arrays, which is more flexible and safer than raw arrays.
2. **String Handling**: C++'s `std::string` is used for string manipulation, which simplifies operations like substring comparison.
3. **Functions**: The `filter_by_prefix` function filters strings based on the given prefix. The `add_to_array` function appends a string to a vector, similar to the Fortran version. The `issame` function checks if two vectors of strings are equal.
4. **Test Cases**: The `test_cases` function runs the unit tests, comparing the output of `filter_by_prefix` against expected results.

This C++ code should behave similarly to the original Fortran code, ensuring the same logic and output for the given test cases.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `filter_by_prefix` function and the `add_to_array` subroutine.

### Fortran Unit Test Code

To compile and run this Fortran code, you might need a Fortran compiler like `gfortran`. Save the following code to a file, say `test_fortran.f90`, and then compile and run it using the command line.

```fortran
program test_main
    implicit none
    character(len=8), allocatable :: result(:)
    character(len=8), allocatable :: expected(:)
    character(len=8), allocatable :: strings(:)
    character(len=:), allocatable :: prefix

    ! Test case 1
    allocate(strings(0))
    prefix = "john"
    result = filter_by_prefix(strings, prefix)
    if (.not. issame(result, strings)) then
        write(*,*) "Test case 1 failed: filter_by_prefix({}, 'john')"
        stop
    end if
    deallocate(strings)
    deallocate(result)

    ! Test case 2
    allocate(strings(6))
    strings = ["xxx     ", "asd     ", "xxy     ", "john doe", "xxxAAA  ", "xxx     "]
    prefix = "xxx"
    result = filter_by_prefix(strings, prefix)
    allocate(expected(3))
    expected = ["xxx     ", "xxxAAA  ", "xxx     "]
    if (.not. issame(result, expected)) then
        write(*,*) "Test case 2 failed: filter_by_prefix({'xxx', 'asd', 'xxy', 'john doe', 'xxxAAA', 'xxx'}, 'xxx')"
        stop
    end if
    deallocate(strings)
    deallocate(result)
    deallocate(expected)

    write(*,*) "All tests passed."

contains

    function filter_by_prefix(strings, prefix) result(out)
        character(len=8), allocatable, dimension(:) :: strings
        character(len=:), allocatable :: prefix
        character(len=8), allocatable, dimension(:) :: out
        integer :: i, count

        count = 0
        allocate(out(0))
        do i = 1, size(strings)
            if (strings(i)(1:len(prefix)) == prefix) then
                count = count + 1
                call add_to_array(out, strings(i))
            end if
        end do
    end function filter_by_prefix

    subroutine add_to_array(array, element)
        character(len=8), allocatable, dimension(:) :: array
        character(len=8), intent(in) :: element
        character(len=8), allocatable, dimension(:) :: temp_array
        integer :: n

        n = size(array)
        allocate(temp_array(n + 1), mold=array)
        if (n > 0) temp_array(1:n) = array
        temp_array(n + 1) = element
        deallocate(array)
        array = temp_array
    end subroutine add_to_array

    function issame(a, b) result(is_equal)
        character(len=8), allocatable, dimension(:) :: a, b
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

end program test_main
```

### C++ Unit Test Code

To compile and run this C++ code, you might need a C++ compiler like `g++`. Save the following code to a file, say `test_cpp.cpp`, and then compile and run it using the command line.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> filter_by_prefix(const std::vector<std::string>& strings, const std::string& prefix) {
    std::vector<std::string> out;
    for (const auto& str : strings) {
        if (str.substr(0, prefix.size()) == prefix) {
            out.push_back(str);
        }
    }
    return out;
}

void add_to_array(std::vector<std::string>& array, const std::string& element) {
    array.push_back(element);
}

bool issame(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    return std::equal(a.begin(), a.end(), b.begin());
}

void test
