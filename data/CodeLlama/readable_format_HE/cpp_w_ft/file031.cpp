Translating the given Fortran code to C++ involves several steps, including changing the syntax, converting the loop structures, and adjusting the function and subroutine calls to match C++ conventions. Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <cstdlib> // For exit()

// Function prototype
int fizz_buzz(int n);
void assert(bool condition, const std::string& message);

int main() {
    int result;

    // Main program logic
    result = fizz_buzz(50);
    assert(result == 0, "fizz_buzz(50) == 0: assertion failed");

    result = fizz_buzz(78);
    assert(result == 2, "fizz_buzz(78) == 2: assertion failed");

    result = fizz_buzz(79);
    assert(result == 3, "fizz_buzz(79) == 3: assertion failed");

    result = fizz_buzz(100);
    assert(result == 3, "fizz_buzz(100) == 3: assertion failed");

    result = fizz_buzz(200);
    assert(result == 6, "fizz_buzz(200) == 6: assertion failed");

    result = fizz_buzz(4000);
    assert(result == 192, "fizz_buzz(4000) == 192: assertion failed");

    result = fizz_buzz(10000);
    assert(result == 639, "fizz_buzz(10000) == 639: assertion failed");

    result = fizz_buzz(100000);
    assert(result == 8026, "fizz_buzz(100000) == 8026: assertion failed");

    return 0;
}

int fizz_buzz(int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 11 == 0 || i % 13 == 0) {
            int q = i;
            while (q > 0) {
                if (q % 10 == 7) {
                    ++count;
                }
                q /= 10;
            }
        }
    }
    return count;
}

void assert(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << message << std::endl;
        std::exit(1);
    }
}
```

### Key Changes:

1. **Function and Subroutine Definitions:** Fortran's `function` and `subroutine` are replaced with C++ functions. The `assert` subroutine is converted to a C++ function that takes a condition and a message.

2. **Loop Syntax:** Fortran's `do` loop is replaced with C++'s `for` loop. The loop variable `i` starts from 0 and goes up to `n-1` to match Fortran's 1-based indexing.

3. **Modulus Operator:** The Fortran modulus operator `.mod.` is replaced with C++'s `%` operator.

4. **Program Logic:** The main program logic remains largely unchanged, but the syntax is adapted to C++.

5. **Assertion:** The `assert` function checks the condition and prints an error message if the condition is false, then exits the program with a non-zero status.

6. **Standard Library Includes:** `<iostream>` is included for input/output operations, and `<cstdlib>` is included for the `exit` function.

This C++ code should behave similarly to the original Fortran code, performing the same calculations and checks.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests. For Fortran, we'll use a simple approach to test the function, as Fortran doesn't have a built-in unit testing framework like some other languages. For C++, we can use the Google Test framework, which is widely used and supports a variety of testing features.

### Fortran Unit Tests

Since Fortran doesn't have a built-in unit testing framework, we'll write a simple test procedure within the program. This is not as robust or scalable as using a dedicated testing framework but serves for demonstration purposes.

```fortran
program test_fizz_buzz
    implicit none

    call test_fizz_buzz_function()

contains

    subroutine test_fizz_buzz_function()
        integer :: expected, result

        ! Test case 1
        expected = 0
        result = fizz_buzz(50)
        call assert(result == expected, "Test case 1 failed: fizz_buzz(50) != 0")

        ! Test case 2
        expected = 2
        result = fizz_buzz(78)
        call assert(result == expected, "Test case 2 failed: fizz_buzz(78) != 2")

        ! Test case 3
        expected = 3
        result = fizz_buzz(79)
        call assert(result == expected, "Test case 3 failed: fizz_buzz(79) != 3")

        ! Add more test cases as needed

        print *, "All tests passed."
    end subroutine test_fizz_buzz_function

    ! Include the fizz_buzz function and assert subroutine here

end program test_fizz_buzz
```

### C++ Unit Tests with Google Test

First, ensure you have Google Test installed and set up in your project. The following example assumes you have Google Test set up.

```cpp
#include <gtest/gtest.h>

// Include or directly paste the fizz_buzz function here

TEST(FizzBuzzTest, TestCases) {
    EXPECT_EQ(fizz_buzz(50), 0);
    EXPECT_EQ(fizz_buzz(78), 2);
    EXPECT_EQ(fizz_buzz(79), 3);
    // Add more test cases as needed
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### Running the Tests

- **For Fortran:** Compile and run the Fortran program as you would normally. If all assertions pass, it will print "All tests passed."

- **For C++ with Google Test:**
  1. Ensure Google Test is properly set up in your project.
  2. Compile the test file along with the Google Test library. This typically involves linking against the Google Test library and including the Google Test headers.
  3. Run the compiled test executable. Google Test will automatically run all tests and report the results.

These unit tests will help ensure that both the Fortran and C++ implementations of the Fizz Buzz function behave as expected across a range of inputs.
