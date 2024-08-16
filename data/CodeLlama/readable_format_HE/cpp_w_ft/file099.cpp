Translating the given Fortran code to C++ involves several steps, including adapting the syntax, converting the functions, and handling the assertions. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Function to check if a date is valid
bool valid_date(const std::string& date);

// Function to pad a string with spaces to make it 10 characters long
std::string pad(const std::string& str);

// Assertion function to mimic the Fortran assert
void assert(bool condition);

int main() {
    // Test cases
    assert(valid_date("03-11-2000") == true);
    assert(valid_date("15-01-2012") == false);
    assert(valid_date("04-0-2040") == false);
    assert(valid_date("06-04-2020") == true);
    assert(valid_date("01-01-2007") == true);
    assert(valid_date("03-32-2011") == false);
    assert(valid_date("") == false);
    assert(valid_date("04-31-3000") == false);
    assert(valid_date("06-06-2005") == true);
    assert(valid_date("21-31-2000") == false);
    assert(valid_date("04-12-2003") == true);
    assert(valid_date("04122003") == false); // Note: This case is not correctly formatted for comparison
    assert(valid_date("20030412") == false); // Note: This case is not correctly formatted for comparison
    assert(valid_date("2003-04") == false); // Note: This case is not correctly formatted for comparison
    assert(valid_date("2003-04-12") == false); // Note: This case is not correctly formatted for comparison
    assert(valid_date("04-2003") == false); // Note: This case is not correctly formatted for comparison

    return 0;
}

bool valid_date(const std::string& date) {
    if (date.length() != 10) {
        return false;
    }

    for (size_t i = 0; i < date.length(); ++i) {
        if ((i == 2 || i == 5) && date[i] != '-') {
            return false;
        } else if (date[i] < '0' || date[i] > '9') {
            return false;
        }
    }

    int mm, dd, yy;
    std::sscanf(date.substr(0, 2).c_str(), "%d", &mm);
    std::sscanf(date.substr(3, 2).c_str(), "%d", &dd);
    std::sscanf(date.substr(6, 4).c_str(), "%d", &yy);

    if (mm < 1 || mm > 12) {
        return false;
    }

    if (dd < 1 || dd > 31) {
        return false;
    }

    if ((dd == 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11)) || (dd == 30 && mm == 2)) {
        return false;
    }

    return true;
}

std::string pad(const std::string& str) {
    std::string padded_str = str;
    padded_str.append(10 - padded_str.length(), ' ');
    return padded_str;
}

void assert(bool condition) {
    if (!condition) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(1);
    }
}
```

This C++ code includes the necessary headers and defines the functions `valid_date`, `pad`, and `assert` to mimic the behavior of the Fortran code. Note that the `assert` function in C++ is part of the `<cassert>` header, but it's defined here to closely match the Fortran version's behavior. Also, the handling of strings and their manipulation is done using the `std::string` class, which simplifies the operations compared to the Fortran character handling.
Let's write some test to verify if the translation is correct. 
Below are the unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the `valid_date` function in both languages.

### Fortran Unit Tests

To compile and run the Fortran unit tests, you can use a Fortran compiler like `gfortran`. Here is how you can set up the unit tests:

```fortran
! valid_date_tests.f90
program valid_date_tests
    implicit none
    logical :: result

    ! Test cases
    result = valid_date("03-11-2000")
    call assert(result .eqv. .true.)

    result = valid_date("15-01-2012")
    call assert(result .eqv. .false.)

    result = valid_date("04-0-2040")
    call assert(result .eqv. .false.)

    result = valid_date("06-04-2020")
    call assert(result .eqv. .true.)

    result = valid_date("01-01-2007")
    call assert(result .eqv. .true.)

    result = valid_date("03-32-2011")
    call assert(result .eqv. .false.)

    result = valid_date("")
    call assert(result .eqv. .false.)

    result = valid_date("04-31-3000")
    call assert(result .eqv. .false.)

    result = valid_date("06-06-2005")
    call assert(result .eqv. .true.)

    result = valid_date("21-31-2000")
    call assert(result .eqv. .false.)

    result = valid_date("04-12-2003")
    call assert(result .eqv. .true.)

    result = valid_date("04122003")
    call assert(result .eqv. .false.)

    result = valid_date("20030412")
    call assert(result .eqv. .false.)

    result = valid_date("2003-04")
    call assert(result .eqv. .false.)

    result = valid_date("2003-04-12")
    call assert(result .eqv. .false.)

    result = valid_date("04-2003")
    call assert(result .eqv. .false.)

contains

    logical function valid_date(date)
        character(len=10), intent(in) :: date
        integer :: mm, dd, yy
        integer :: i

        if (len_trim(date) /= 10) then
            valid_date = .false.
            return
        end if

        do i = 1, 10
            if (i == 3 .or. i == 6) then
                if (date(i:i) /= '-') then
                    valid_date = .false.
                    return
                end if
            else
                if (iachar(date(i:i)) < 48 .or. iachar(date(i:i)) > 57) then
                    valid_date = .false.
                    return
                end if
            end if
        end do

        read(date(1:2), '(I2)') mm
        read(date(4:5), '(I2)') dd
        read(date(7:10), '(I4)') yy

        if (mm < 1 .or. mm > 12) then
            valid_date = .false.
            return
        end if

        if (dd < 1
