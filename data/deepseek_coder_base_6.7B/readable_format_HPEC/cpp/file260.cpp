Certainly! Below is the translated Fortran code to C++. Note that in C++, arrays are zero-indexed, unlike Fortran which is one-indexed. Also, I'm assuming `DATA_TYPE` is a placeholder for a specific data type (e.g., `float`, `double`, etc.), and `DATA_PRINTF_MODIFIER` is a format string for printing the data. You'll need to replace `DATA_TYPE` and `DATA_PRINTF_MODIFIER` with the actual data type and format string in your C++ code.

```cpp
#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for a specific data type (e.g., float, double, etc.)
using DATA_TYPE = double;

void print_array(int nx, int ny, const std::vector<DATA_TYPE>& s, const std::vector<DATA_TYPE>& q) {
    // Assuming DATA_PRINTF_MODIFIER is a format string for printing the data.
    // You need to replace "%.6f" with the actual format string in your C++ code.
    const char* DATA_PRINTF_MODIFIER = "%.6f";

    for (int i = 0; i < ny; ++i) {
        std::cout << DATA_PRINTF_MODIFIER << s[i] << std::endl;
        if ((i + 1) % 80 == 0) {
            std::cout << std::endl;
        }
    }

    for (int i = 0; i < nx; ++i) {
        std::cout << DATA_PRINTF_MODIFIER << q[i] << std::endl;
        if ((i + 1) % 80 == 0) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}

int main() {
    // Example usage
    int nx = 100; // Example value for nx
    int ny = 100; // Example value for ny
    std::vector<DATA_TYPE> s(ny); // Example initialization
    std::vector<DATA_TYPE> q(nx); // Example initialization

    // Populate s and q with example data
    for (int i = 0; i < ny; ++i) {
        s[i] = static_cast<DATA_TYPE>(i); // Example data
    }

    for (int i = 0; i < nx; ++i) {
        q[i] = static_cast<DATA_TYPE>(i * 2); // Example data
    }

    print_array(nx, ny, s, q);

    return 0;
}
```

This C++ code defines a function `print_array` that takes the dimensions of the arrays (`nx` and `ny`) and the arrays themselves (`s` and `q`). It then iterates over the arrays and prints the elements, formatted according to the `DATA_PRINTF_MODIFIER` format string, with a newline after each element. If the index is a multiple of 80, it also prints a newline to match the Fortran behavior.

Remember to replace `DATA_TYPE` and `DATA_PRINTF_MODIFIER` with the actual data type and format string in your specific use case.
Let's write some test to verify if the translation is correct. 
Below are examples of unit tests for both the original Fortran code and the translated C++ code. These tests will verify the functionality of the `print_array` subroutine/function by comparing their outputs against expected values.

### Fortran Unit Test

For the Fortran code, we'll create a simple program that calls the `print_array` subroutine and captures its output. Note that capturing output in Fortran for comparison purposes is not as straightforward as in C++, so this example will focus on calling the subroutine and ensuring it runs without errors.

```fortran
program test_print_array
    implicit none
    integer, parameter :: nx = 10, ny = 10
    real, dimension(ny) :: s
    real, dimension(nx) :: q
    integer :: i

    ! Initialize arrays
    do i = 1, ny
        s(i) = real(i)
    end do

    do i = 1, nx
        q(i) = real(i * 2)
    end do

    ! Call the subroutine
    call print_array(nx, ny, s, q)

end program test_print_array

subroutine print_array(nx, ny, s, q)
    implicit none
    real, dimension(ny) :: s
    real, dimension(nx) :: q
    integer :: nx, ny
    integer :: i

    do i = 1, ny
        write(*, '(F6.2)') s(i)
        if (mod(i - 1, 80) == 0) then
            write(*, *)
        end if
    end do

    do i = 1, nx
        write(*, '(F6.2)') q(i)
        if (mod(i - 1, 80) == 0) then
            write(*, *)
        end if
    end do

    write(*, *)
end subroutine print_array
```

This Fortran program initializes two arrays `s` and `q`, calls the `print_array` subroutine, and prints the results. You would need to manually verify the output against expected values.

### C++ Unit Test

For the C++ code, we can use a testing framework like Google Test for more automated testing. This example assumes you have Google Test set up in your environment.

```cpp
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

// Assuming the print_array function is defined in print_array.h
#include "print_array.h"

TEST(PrintArrayTest, CorrectOutput) {
    int nx = 10;
    int ny = 10;
    std::vector<double> s(ny);
    std::vector<double> q(nx);

    // Initialize s and q with example data
    for (int i = 0; i < ny; ++i) {
        s[i] = static_cast<double>(i);
    }

    for (int i = 0; i < nx; ++i) {
        q[i] = static_cast<double>(i * 2);
    }

    // Capture the output
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Call the function
    print_array(nx, ny, s, q);

    // Restore the original buffer
    std::cout.rdbuf(prevcoutbuf);

    // Define the expected output
    std::string expectedOutput = "0.000000
1.000000
2.000000
3.000000
4.000000
5.000000
6.000000
7.000000
8.000000
9.000000
0.000000
2.000000
4.000000
6.000000
8.000000
10.000000
12.000000
14.000000
16.000000
18.000000
20.000000
22.000000
24.000000
26.000000
28.000000
30.000000
32.000000
34.000000
36.000000
38.000000
40.000000
42.000000
44.000000
