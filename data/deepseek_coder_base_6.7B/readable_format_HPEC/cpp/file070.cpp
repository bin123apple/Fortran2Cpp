To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, parallel processing with OpenMP, and I/O operations. Fortran arrays are 1-based, while C++ arrays are 0-based. Also, OpenMP directives in Fortran and C++ have different syntax. Here's a C++ version of the Fortran code using OpenMP for parallel processing:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    const int inLen = 1000;
    int input[inLen];
    int output[inLen];
    int outLen = 1;

    // Initialize input array
    for (int i = 0; i < inLen; ++i) {
        input[i] = i + 1; // Adjusting for 0-based indexing
    }

    // Parallel processing
    #pragma omp parallel for
    for (int i = 0; i < inLen; ++i) {
        output[inLen - outLen] = input[i]; // Adjusting for 0-based indexing and reversing the output
        outLen++;
    }

    // Print the 500th element of the output array
    std::cout << "output(500)=" << output[499] << std::endl; // Adjusting for 0-based indexing

    return 0;
}
```

Key Points in the Translation:

1. **Array Indexing**: Adjusted the array indexing to start from 0 in C++, as opposed to starting from 1 in Fortran.
2. **Parallel Processing**: Used OpenMP's `#pragma omp parallel for` directive to parallelize the loop. This directive tells the compiler to parallelize the loop across multiple threads.
3. **Output Array Construction**: Reversed the construction of the `output` array to mimic the original Fortran code's behavior. In the original Fortran code, elements are added to the `output` array in reverse order, which is achieved by using `inLen - outLen + 1` as the index. In the C++ translation, this is achieved by using `inLen - outLen`.
4. **I/O Operations**: Used `std::cout` for output, formatting the output string to match the Fortran `print` statement's output.

Make sure to compile this C++ code with OpenMP support enabled. For example, if you're using `g++`, you can compile the code with the `-fopenmp` flag:

```sh
g++ -fopenmp your_program.cpp -o your_program
```
Let's write some test to verify if the translation is correct. 
Below are examples of how you could write unit tests for both the original Fortran code and the translated C++ code. These tests will verify the correctness of the output array construction.

### Fortran Unit Test

For Fortran, we'll use a simple approach to test the output array. Fortran doesn't have a built-in unit testing framework like some other languages, so we'll manually check the output.

```fortran
program test_drb018_plusplus_orig_yes
    use omp_lib
    implicit none

    integer :: i, inLen, outLen
    integer :: input(1000)
    integer :: output(1000)
    logical :: test_passed

    inLen = 1000
    outLen = 1

    ! Initialize input array
    do i = 1, inLen
        input(i) = i
    end do

    !$omp parallel do
    do i = 1, inLen
        output(outLen) = input(i)
        outLen = outLen + 1
    end do
    !$omp end parallel do

    ! Test if output(500) is correct
    test_passed = .true.
    if (output(500) /= 500) then
        test_passed = .false.
    end if

    if (test_passed) then
        print *, "Test passed: output(500) is correct."
    else
        print *, "Test failed: output(500) is incorrect."
    end if

end program test_drb018_plusplus_orig_yes
```

### C++ Unit Test

For C++, we can use a unit testing framework like Google Test for more comprehensive testing. Below is an example using Google Test.

First, you need to install Google Test. Then, you can write the test as follows:

```cpp
#include <gtest/gtest.h>
#include <omp.h>

// Function to be tested
void reverseArray(int* input, int* output, int inLen, int outLen) {
    #pragma omp parallel for
    for (int i = 0; i < inLen; ++i) {
        output[inLen - outLen] = input[i];
        outLen++;
    }
}

// Test case
TEST(DRB018PlusPlusOrigYesTest, OutputCorrectness) {
    const int inLen = 1000;
    int input[inLen];
    int output[inLen];
    int outLen = 1;

    // Initialize input array
    for (int i = 0; i < inLen; ++i) {
        input[i] = i + 1; // Adjusting for 0-based indexing
    }

    // Call the function to be tested
    reverseArray(input, output, inLen, outLen);

    // Check if output(500) is correct
    EXPECT_EQ(output[499], 500); // Adjusting for 0-based indexing
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

To compile and run the C++ test, you'll need to link against the Google Test library. Assuming you have Google Test installed and your file is named `test_drb018_plusplus_orig_yes.cpp`, the compilation command might look something like this:

```sh
g++ -fopenmp test_drb018_plusplus_orig_yes.cpp -lgtest -lgtest_main -pthread -o test_drb018_plusplus_orig_yes
./test_drb018_plusplus_orig_yes
```

This will compile and run the test, checking if the output array construction is correct.
