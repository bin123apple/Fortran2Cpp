To translate the given Fortran code to C++, we need to understand the structure and the purpose of each Fortran statement and then find the equivalent or similar constructs in C++. The Fortran code uses OpenMP for parallelism and task dependencies. The equivalent C++ code would also use OpenMP for parallelism and task dependencies.

Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                i = 1;
            }
            #pragma omp task depend(in:i)
            {
                i = 2;
            }
        }
    }

    if (i != 2) {
        std::cout << "i is not equal to 2" << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Variable Declaration**: The variable `i` is declared as an integer and initialized to 0.
3. **Parallel Region**: The `#pragma omp parallel` directive is used to start a parallel region.
4. **Single Region**: The `#pragma omp single` directive is used to ensure that only one thread executes the enclosed code.
5. **Tasks**: The `#pragma omp task depend` directive is used to specify task dependencies. The `out:i` clause indicates that the task modifies `i`, and the `in:i` clause indicates that the task depends on the modification of `i`.
6. **Conditional Check**: The `if` statement checks if `i` is not equal to 2 and prints a message if true.

### Notes:
- **Task Dependencies**: In C++, task dependencies are specified using `#pragma omp task depend`. The syntax is similar to Fortran, but the directives are slightly different.
- **Parallel and Single Regions**: These are used similarly in C++ as they are in Fortran. The parallel region is executed in parallel, and the single region ensures that only one thread executes the enclosed code.
- **OpenMP Directives**: The OpenMP directives used in C++ (`#pragma omp`) are similar to those in Fortran (`!$omp`), but the syntax is different.

This C++ code should exhibit the same behavior as the original Fortran code, using OpenMP for parallelism and task dependencies as intended.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write simple unit tests. For Fortran, we can use a simple approach to check the value of `i` after the parallel execution. For C++, we can use a similar approach, but we'll also demonstrate a more structured approach using a testing framework like Google Test.

### Fortran Unit Test

Since Fortran doesn't have a built-in unit testing framework like some other languages, we'll write a simple test by checking the value of `i` after the parallel execution.

```fortran
program test_DRB072_taskdep1_orig_no
    use omp_lib
    implicit none

    integer :: i
    i = 0

    !$omp parallel
        !$omp single
            !$omp task depend (out:i)
            i = 1
            !$omp end task
            !$omp task depend (in:i)
            i = 2
            !$omp end task
        !$omp end single
    !$omp end parallel

    if (i == 2) then
        print*, 'Test Passed: i is equal to 2'
    else
        print*, 'Test Failed: i is not equal to 2'
    end if
end program test_DRB072_taskdep1_orig_no
```

### C++ Unit Test with Google Test

First, you need to install Google Test. You can find the installation instructions [here](https://github.com/google/googletest).

Here's how you can write a unit test for the translated C++ code using Google Test:

```cpp
#include <gtest/gtest.h>
#include <omp.h>

TEST(DRB072TaskDep1OrigNoTest, TestValueOfI) {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                i = 1;
            }
            #pragma omp task depend(in:i)
            {
                i = 2;
            }
        }
    }

    EXPECT_EQ(i, 2) << "The value of i should be 2 after the parallel execution.";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### Running the Tests

#### Fortran

To run the Fortran test, you can compile and execute it using a Fortran compiler that supports OpenMP, such as `gfortran`:

```sh
gfortran -fopenmp test_DRB072_taskdep1_orig_no.f90 -o test_DRB072_taskdep1_orig_no
./test_DRB072_taskdep1_orig_no
```

#### C++

To run the C++ test with Google Test, you need to link against the Google Test library. Here's an example command using `g++`:

```sh
g++ -fopenmp test_DRB072_taskdep1_orig_no.cpp -lgtest -lgtest_main -pthread -o test_DRB072_taskdep1_orig_no
./test_DRB072_taskdep1_orig_no
```

### Explanation

- **Fortran Test**: The Fortran test checks if `i` is equal to 2 after the parallel execution. If `i` is 2, it prints "Test Passed"; otherwise, it prints "Test Failed".
- **C++ Test with Google Test**: The C++ test uses Google Test to verify that the value of `i` is 2 after the parallel execution. It uses `EXPECT_EQ` to check if `i` equals 2. If the test passes, it prints a success message.

These tests will help verify that the translated C++ code behaves the same way as the original Fortran code, using OpenMP for parallelism and task dependencies as intended.
