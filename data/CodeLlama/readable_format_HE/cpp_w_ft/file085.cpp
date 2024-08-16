Translating the provided Fortran code to C++ involves several steps, including adapting the module and subroutine structure to a class and methods structure, converting Fortran intrinsic functions and I/O operations to their C++ equivalents, and handling dynamic memory allocation for the output string. Here's how the Fortran code can be translated into C++:

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

class Utils {
public:
    static std::string rounded_avg(int n, int m) {
        if (n > m) {
            return "-1";
        }

        int num = (m + n) / 2;
        std::string temp_out = "";
        while (num > 0) {
            int remainder = num % 2;
            temp_out = std::string(1, static_cast<char>(remainder + '0')) + temp_out;
            num = num / 2;
        }

        if (temp_out.empty()) {
            temp_out = "0";
        }

        return temp_out;
    }

    static void assert(bool condition, const std::string& message) {
        if (!condition) {
            std::cerr << message << std::endl;
            exit(1);
        }
    }
};

int main() {
    // Main program
    Utils::assert(Utils::rounded_avg(1, 5) == "11", "Assertion failed: rounded_avg(1, 5) == '11'");
    Utils::assert(Utils::rounded_avg(7, 13) == "1010", "Assertion failed: rounded_avg(7, 13) == '1010'");
    Utils::assert(Utils::rounded_avg(964, 977) == "1111001010", "Assertion failed: rounded_avg(964, 977) == '1111001010'");
    Utils::assert(Utils::rounded_avg(996, 997) == "1111100100", "Assertion failed: rounded_avg(996, 997) == '1111100100'");
    Utils::assert(Utils::rounded_avg(560, 851) == "1011000001", "Assertion failed: rounded_avg(560, 851) == '1011000001'");
    Utils::assert(Utils::rounded_avg(185, 546) == "101101101", "Assertion failed: rounded_avg(185, 546) == '101101101'");
    Utils::assert(Utils::rounded_avg(362, 496) == "110101101", "Assertion failed: rounded_avg(362, 496) == '110101101'");
    Utils::assert(Utils::rounded_avg(350, 902) == "1001110010", "Assertion failed: rounded_avg(350, 902) == '1001110010'");
    Utils::assert(Utils::rounded_avg(197, 233) == "11010111", "Assertion failed: rounded_avg(197, 233) == '11010111'");
    Utils::assert(Utils::rounded_avg(7, 5) == "-1", "Assertion failed: rounded_avg(7, 5) == '-1'");
    Utils::assert(Utils::rounded_avg(5, 1) == "-1", "Assertion failed: rounded_avg(5, 1) == '-1'");
    Utils::assert(Utils::rounded_avg(5, 5) == "101", "Assertion failed: rounded_avg(5, 5) == '101'");

    return 0;
}
```

Key Points in the Translation:
- The Fortran module `utils` is translated into a C++ class `Utils`.
- The Fortran function `rounded_avg` and subroutine `assert` are translated into static member functions of the `Utils` class.
- The Fortran `character(len=:), allocatable` type is translated to `std::string` in C++, which automatically manages memory and can be dynamically resized.
- The Fortran `write` statement used for converting an integer to a string is replaced with a simple cast to `char` and concatenation with the `temp_out` string.
- The `exit` function in Fortran is replaced with `std::exit` in C++.
- The main program logic remains largely unchanged, but is now encapsulated within the `main` function of the C++ program.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests. These tests will call the `rounded_avg` function with various inputs and check if the outputs match the expected results.

### Fortran Unit Tests

For Fortran, we can use a simple approach to test the function by adding test cases directly in the program. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll manually check the results.

```fortran
! Add this inside the program rounded_avg_program
subroutine test_rounded_avg()
    implicit none
    character(len=32) :: result

    ! Test case 1
    result = rounded_avg(1, 5)
    call assert(result == "11", "Test case 1 failed")

    ! Add more test cases as needed...

    print *, "All tests passed."
end subroutine test_rounded_avg

! Call the test subroutine at the end of the program
call test_rounded_avg()
```

### C++ Unit Tests

For C++, we can use a testing framework like Google Test for more comprehensive and automated testing. However, for simplicity, I'll show a basic approach similar to the Fortran example.

```cpp
#include <iostream>
#include <string>
#include <cstdlib> // For exit()

// Include the Utils class definition here

void test_rounded_avg(const std::string& test_case, int n, int m, const std::string& expected) {
    std::string result = Utils::rounded_avg(n, m);
    Utils::assert(result == expected, "Test case " + test_case + " failed: Expected " + expected + ", got " + result);
}

int main() {
    // Test case 1
    test_rounded_avg("1", 1, 5, "11");

    // Add more test cases as needed...

    std::cout << "All tests passed." << std::endl;

    return 0;
}
```

### Running the Tests

- **For Fortran**: Compile the Fortran program with a Fortran compiler (e.g., `gfortran`) and run the executable. If all tests pass, it will print "All tests passed."

  ```bash
  gfortran -o rounded_avg_test rounded_avg_program.f90
  ./rounded_avg_test
  ```

- **For C++**: Compile the C++ program with a C++ compiler (e.g., `g++`) and run the executable. If all tests pass, it will print "All tests passed."

  ```bash
  g++ -o rounded_avg_test rounded_avg_program.cpp
  ./rounded_avg_test
  ```

These tests will help ensure that the `rounded_avg` function behaves as expected in both the original Fortran code and the translated C++ code.
