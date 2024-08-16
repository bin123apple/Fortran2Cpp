Translating the provided Fortran code to C++ involves converting the module and subroutine into a class with member functions, and handling dynamic arrays with vectors or list containers from the Standard Template Library (STL). Here's how the translation might look:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Utilities {
public:
    static int next_smallest(const std::vector<int>& lst) {
        if (lst.empty()) {
            return -1;
        }

        std::vector<int> sorted_lst = lst;
        std::sort(sorted_lst.begin(), sorted_lst.end());

        int res = -1;
        for (size_t i = 1; i < sorted_lst.size(); ++i) {
            if (sorted_lst[i] != sorted_lst[i - 1]) {
                res = sorted_lst[i];
                break;
            }
        }
        return res;
    }

    static void sort(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
    }
};

int main() {
    std::vector<int> lst;
    int result;

    // Test case 1
    lst = {1, 2, 3, 4, 5};
    result = Utilities::next_smallest(lst);
    if (result != 2) {
        std::cerr << "Test case 1 failed" << std::endl;
        return 1;
    }

    // Test case 2
    lst = {5, 1, 4, 3, 2};
    result = Utilities::next_smallest(lst);
    if (result != 2) {
        std::cerr << "Test case 2 failed" << std::endl;
        return 1;
    }

    // Test case 3
    lst = {};
    result = Utilities::next_smallest(lst);
    if (result != -1) {
        std::cerr << "Test case 3 failed" << std::endl;
        return 1;
    }

    // Test case 4
    lst = {1, 1};
    result = Utilities::next_smallest(lst);
    if (result != -1) {
        std::cerr << "Test case 4 failed" << std::endl;
        return 1;
    }

    // Test case 5
    lst = {1, 1, 1, 1, 0};
    result = Utilities::next_smallest(lst);
    if (result != 1) {
        std::cerr << "Test case 5 failed" << std::endl;
        return 1;
    }

    // Test case 6
    lst = {-35, 34, 12, -45};
    result = Utilities::next_smallest(lst);
    if (result != -35) {
        std::cerr << "Test case 6 failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
```

This C++ code defines a `Utilities` class with static member functions `next_smallest` and `sort`, which correspond to the Fortran module's functions. The `main` function contains test cases similar to the Fortran program, ensuring that the translated code behaves as expected. Note that in C++, vectors are used to handle dynamic arrays, which provides more flexibility and safety compared to raw arrays.
Let's write some test to verify if the translation is correct. 
Below are examples of how you might write unit tests for both the Fortran and C++ versions of the code. These tests will verify the correctness of the `next_smallest` function under various conditions.

### Fortran Unit Tests

For Fortran, you can use a simple testing approach by adding test cases directly in the program. Fortran lacks a built-in unit testing framework, so we'll manually check the results and print out messages accordingly.

```fortran
program test_utilities
    use utilities
    implicit none
    integer, dimension(:), allocatable :: lst
    integer :: result

    ! Test case 1
    lst = [1, 2, 3, 4, 5]
    result = next_smallest(lst)
    if (result == 2) then
        write(*,*) "Test case 1 passed"
    else
        write(*,*) "Test case 1 failed"
    end if

    ! Test case 2
    lst = [5, 1, 4, 3, 2]
    result = next_smallest(lst)
    if (result == 2) then
        write(*,*) "Test case 2 passed"
    else
        write(*,*) "Test case 2 failed"
    end if

    ! Add more test cases as needed...

end program test_utilities
```

### C++ Unit Tests

For C++, you can use a unit testing framework like Google Test for more comprehensive testing. Here's how you might set up a basic test suite using Google Test.

First, you need to install Google Test. The setup might vary depending on your system and IDE.

Then, you can write the test cases as follows:

```cpp
#include <gtest/gtest.h>
#include "Utilities.h" // Assume the Utilities class is defined in this header

TEST(UtilitiesTest, NextSmallest) {
    std::vector<int> lst = {1, 2, 3, 4, 5};
    EXPECT_EQ(Utilities::next_smallest(lst), 2);

    lst = {5, 1, 4, 3, 2};
    EXPECT_EQ(Utilities::next_smallest(lst), 2);

    lst = {}; // Empty vector
    EXPECT_EQ(Utilities::next_smallest(lst), -1);

    lst = {1, 1};
    EXPECT_EQ(Utilities::next_smallest(lst), -1);

    lst = {1, 1, 1, 1, 0};
    EXPECT_EQ(Utilities::next_smallest(lst), 1);

    lst = {-35, 34, 12, -45};
    EXPECT_EQ(Utilities::next_smallest(lst), -35);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

This C++ code uses Google Test to define a test case for each scenario you want to test. Each `EXPECT_EQ` macro checks if the `next_smallest` function returns the expected value for a given input.

To run these tests, you'll need to compile the C++ test file with Google Test libraries linked, and then execute the resulting binary. The exact compilation command depends on your setup, but it might look something like this:

```bash
g++ -std=c++11 -isystem /path/to/gtest/include -pthread path/to/your_test_file.cpp path/to/your_utilities_file.cpp /path/to/gtest_main.a -o your_test_executable
./your_test_executable
```

Replace `/path/to/...` with the actual paths to your files and libraries.

These tests will help ensure that both the Fortran and C++ implementations of the `next_smallest` function behave as expected under various conditions.
