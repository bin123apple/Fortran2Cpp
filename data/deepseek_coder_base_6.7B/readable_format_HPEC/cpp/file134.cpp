To translate the given Fortran code to C++, we need to consider several aspects, including array indexing, memory allocation, and OpenMP directives. Fortran arrays are 1-based, while C++ arrays are 0-based. We'll use `std::vector` from the C++ Standard Library for dynamic arrays, and OpenMP will be used similarly to the Fortran code.

Here's the translated C++ code:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len), b(len);
    int tmp = 0; // 'save' attribute in Fortran is not needed in C++ as static storage duration is the default.
    int tmp2 = 0;

    // Initializing arrays
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusting for 0-based indexing
        b[i] = i + 1; // Adjusting for 0-based indexing
    }

    // Parallel region for updating 'a'
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        tmp = a[i] + (i + 1); // Adjusting for 0-based indexing
        a[i] = tmp;
    }

    // Parallel region for updating 'b'
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        tmp2 = b[i] + (i + 1); // Adjusting for 0-based indexing
        b[i] = tmp2;
    }

    // Printing the 50th element of each array (adjusting for 0-based indexing)
    std::cout << a[49] << " " << b[49] << std::endl;

    // No need to explicitly deallocate vectors in C++, they will be automatically deallocated when they go out of scope.
    return 0;
}
```

Key Points:
- We use `std::vector<int>` for dynamic arrays, which automatically handles memory management.
- OpenMP directives are used similarly to the Fortran code, but with `#pragma omp` instead of `!$omp`.
- The loop indices and array accesses are adjusted for C++'s 0-based indexing.
- The `print` statement in Fortran is replaced with `std::cout` in C++.
- The `save` attribute in Fortran is not needed in C++ as variables with static storage duration (i.e., global or static variables) are initialized only once, and their values persist for the lifetime of the program.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the final state of the arrays `a` and `b` after the parallel operations. However, it's important to note that the operations within the parallel regions are not deterministic, and the final results depend on the number of threads and their scheduling. For a fair comparison, we'll assume a deterministic outcome for the sake of testing.

### Fortran Unit Test

For the Fortran code, we can modify the program to include checks after the operations to ensure the arrays `a` and `b` are as expected. However, due to the nature of parallel execution, the exact output might not be predictable without knowing the specific parallel execution details.

### C++ Unit Test

For C++, we can use a simple test framework like Google Test to verify the correctness of the operations. This example assumes you have Google Test set up in your environment.

First, ensure you have Google Test installed and set up in your project. Then, you can write a test case like the following:

```cpp
#include <gtest/gtest.h>
#include <vector>
#include <omp.h>

// Function to perform the operations as in the main program
void performOperations(std::vector<int>& a, std::vector<int>& b) {
    const int len = 100;
    int tmp = 0;
    int tmp2 = 0;

    // Parallel region for updating 'a'
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        tmp = a[i] + (i + 1);
        a[i] = tmp;
    }

    // Parallel region for updating 'b'
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        tmp2 = b[i] + (i + 1);
        b[i] = tmp2;
    }
}

// Test case
TEST(DRB090Test, ArrayOperations) {
    std::vector<int> a(100), b(100);
    for (int i = 0; i < 100; ++i) {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    performOperations(a, b);

    // Expected values after operations
    std::vector<int> expectedA(100), expectedB(100);
    for (int i = 0; i < 100; ++i) {
        expectedA[i] = i + 2; // a(i) = i + 1 + i + 1
        expectedB[i] = i + 2; // b(i) = i + 1 + i + 1
    }

    for (int i = 0; i < 100; ++i) {
        EXPECT_EQ(a[i], expectedA[i]);
        EXPECT_EQ(b[i], expectedB[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

This test initializes two arrays `a` and `b`, performs the operations as in the main program, and then checks if the arrays `a` and `b` are equal to the expected values after the operations.

### Running the Tests

- For the Fortran code, you would compile and run it as usual, and manually verify the output against expected values.
- For the C++ code, you need to compile the test with Google Test linked. The exact compilation command depends on your setup, but it might look something like this:

```sh
g++ -std=c++11 -fopenmp your_test_file.cpp -lgtest -lgtest_main -pthread -o test_program
./test_program
```

This command compiles the test program with OpenMP support, links it with Google Test, and runs the resulting executable. The output will indicate whether the test passed or failed.
