To translate the given Fortran code to C++, we need to adapt the Fortran-specific features to their C++ equivalents. Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string encode_shift(const std::string& s) {
    std::string out = s;
    for (size_t i = 0; i < s.length(); ++i) {
        int w = (s[i] + 5 - 'a') % 26 + 'a';
        out[i] = static_cast<char>(w);
    }
    return out;
}

std::string decode_shift(const std::string& s) {
    std::string out = s;
    for (size_t i = 0; i < s.length(); ++i) {
        int w = (s[i] + 21 - 'a') % 26 + 'a';
        out[i] = static_cast<char>(w);
    }
    return out;
}

int main() {
    std::srand(std::time(nullptr));

    for (int i = 0; i < 100; ++i) {
        int l = 10 + std::rand() % 11;
        std::string str = "";
        for (int j = 0; j < l; ++j) {
            int chr = 'a' + std::rand() % 26;
            str += static_cast<char>(chr);
        }

        std::string encoded_str = encode_shift(str);
        std::string decoded_str = decode_shift(encoded_str);

        if (str != decoded_str) {
            std::cerr << "Assertion failed: decoded string does not match original" << std::endl;
            return 1;
        }
    }

    return 0;
}
```

### Explanation:
1. **Random Number Generation**:
   - In Fortran, `call random_seed()` and `call random_number(rand_val)` are used to generate random numbers.
   - In C++, `std::srand(std::time(nullptr));` initializes the random number generator and `std::rand()` generates random numbers.

2. **String Handling**:
   - Fortran's `character(len=21) :: str, encoded_str, decoded_str` is translated to `std::string` in C++.

3. **Character Encoding and Decoding**:
   - The `encode_shift` and `decode_shift` functions in Fortran are translated to C++ functions that return `std::string`.
   - The character encoding and decoding logic remains the same, using modular arithmetic to shift characters.

4. **Loop Constructs**:
   - Fortran's `do` loops are translated to `for` loops in C++.

5. **Assertion**:
   - The Fortran `if` statement and `write` statement are replaced with an `if` statement and `std::cerr` for error output in C++.

This C++ code should behave similarly to the original Fortran code, performing the same operations and checks.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can create unit tests. These tests will run a series of checks to ensure that the encoding and decoding functions work as expected.

### Fortran Unit Test

For the Fortran code, we can create a simple test program that calls the `encode_shift` and `decode_shift` functions with predefined inputs and checks the results.

```fortran
program test_encode_decode_shift
    implicit none
    character(len=21) :: test_str, encoded_str, decoded_str

    ! Test 1
    test_str = "hello"
    encoded_str = encode_shift(test_str)
    decoded_str = decode_shift(encoded_str)
    if (trim(decoded_str) /= trim(test_str)) then
        write(*,*) "Test 1 failed: ", trim(test_str), " != ", trim(decoded_str)
    else
        write(*,*) "Test 1 passed"
    end if

    ! Test 2
    test_str = "world"
    encoded_str = encode_shift(test_str)
    decoded_str = decode_shift(encoded_str)
    if (trim(decoded_str) /= trim(test_str)) then
        write(*,*) "Test 2 failed: ", trim(test_str), " != ", trim(decoded_str)
    else
        write(*,*) "Test 2 passed"
    end if

contains
    function encode_shift(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 5 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function encode_shift

    function decode_shift(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 21 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function decode_shift
end program test_encode_decode_shift
```

### C++ Unit Test

For the C++ code, we can use a simple test framework like Google Test or just write a basic test function. Here, I'll show a basic approach without an external framework:

```cpp
#include <iostream>
#include <string>
#include <cassert>

std::string encode_shift(const std::string& s);
std::string decode_shift(const std::string& s);

void test_encode_decode_shift() {
    // Test 1
    std::string test_str = "hello";
    std::string encoded_str = encode_shift(test_str);
    std::string decoded_str = decode_shift(encoded_str);
    assert(test_str == decoded_str && "Test 1 failed");
    std::cout << "Test 1 passed" << std::endl;

    // Test 2
    test_str = "world";
    encoded_str = encode_shift(test_str);
    decoded_str = decode_shift(encoded_str);
    assert(test_str == decoded_str && "Test 2 failed");
    std::cout << "Test 2 passed" << std::endl;
}

int main() {
    test_encode_decode_shift();
    return 0;
}
```

### Explanation:

1. **Fortran Unit Test**:
   - The program defines two tests, "hello" and "world", and checks if the decoded string matches the original.
   - The `encode_shift` and `decode_shift` functions are included within the program for completeness.

2. **C++ Unit Test**:
   - The `test_encode_decode_shift` function defines two tests similar to the Fortran version.
   - The `assert` function is used to check if the decoded string matches the original. If the assertion fails, it will terminate the program and print an error message.
   - The `main` function calls `test_encode_decode_shift` to run the tests.

These unit tests will help verify that the encoding and decoding functions work as expected in both the Fortran and C++ implementations.
