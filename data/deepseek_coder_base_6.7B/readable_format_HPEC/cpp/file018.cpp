To translate the given Fortran code to C++, we need to understand the structure and functionality of the original Fortran code and then replicate its behavior using C++ constructs. The Fortran code defines a module `DRB087` with a type `A` and a program that uses this module. It demonstrates the use of OpenMP for parallel regions and static data members in Fortran.

In C++, static data members can be used to maintain state across function calls, similar to how they are used in Fortran modules. We can use OpenMP in C++ in a similar manner as in Fortran.

Here's how the Fortran code can be translated to C++:

```cpp
#include <iostream>
#include <omp.h>

// Equivalent to the Fortran module 'DRB087'
class A {
public:
    int x, y;
    A(int x = 0, int y = 0) : x(x), y(y) {}
};

// Static data members in C++
class Counter {
public:
    static int counter;
    static int pcounter;
};

// Initialize static data members
int Counter::counter = 0;
int Counter::pcounter = 0;

int main() {
    // Equivalent to the Fortran type 'A' and its usage
    A c(0, 0);

    // Equivalent to the Fortran OpenMP parallel region
    #pragma omp parallel
    {
        // Increment counter and pcounter in the parallel region
        #pragma omp atomic
        Counter::counter++;
        #pragma omp atomic
        Counter::pcounter++;
    }

    // Print the values of counter and pcounter
    std::cout << Counter::counter << " " << Counter::pcounter << std::endl;

    return 0;
}
```

### Explanation:
1. **Class `A`**:
   - This class is equivalent to the Fortran type `A`.
   - It contains two member variables `x` and `y`, both initialized to 0 by default.

2. **Static Data Members in Class `Counter`**:
   - `counter` and `pcounter` are declared as `static` members of the `Counter` class.
   - This means they belong to the class itself rather than to any instance of the class.
   - They are initialized outside the class definition.

3. **OpenMP Pragmas**:
   - `#pragma omp parallel`: This is the equivalent of the Fortran OpenMP parallel region.
   - `#pragma omp atomic`: This ensures that the increment operations on `counter` and `pcounter` are atomic.

4. **Main Function**:
   - Creates an instance of class `A`, named `c`, initializing it with default values.
   - Enters a parallel region using OpenMP.
   - Inside the parallel region, it increments `counter` and `pcounter` using `#pragma omp atomic`.
   - After the parallel region, it prints the values of `counter` and `pcounter`.

This C++ code replicates the functionality of the original Fortran code, including the use of OpenMP for parallelism and static data members to maintain state across function calls.
Let's write some test to verify if the translation is correct. 
To verify the correctness of both the original Fortran code and the translated C++ code, we can write unit tests. For Fortran, we can use a simple approach to test the functionality since Fortran doesn't have a built-in unit testing framework like some other languages. For C++, we can use the Google Test framework, which is widely used and provides a rich set of assertions.

### Fortran Unit Test

Since Fortran doesn't have a built-in unit testing framework, we'll write a simple test procedure within the program. This test will check if the `counter` and `pcounter` are incremented correctly in the parallel region.

```fortran
program test_DRB087
    use omp_lib
    use DRB087
    implicit none

    type(A) :: c
    integer :: expected_counter, expected_pcounter
    integer :: i

    ! Initialize counters
    counter = 0
    pcounter = 0

    ! Expected values after parallel execution
    expected_counter = 1
    expected_pcounter = 1

    !$omp parallel
    counter = counter + 1
    pcounter = pcounter + 1
    !$omp end parallel

    ! Check results
    if (counter == expected_counter .and. pcounter == expected_pcounter) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_DRB087
```

### C++ Unit Test with Google Test

First, ensure you have Google Test installed and set up in your project. The following example assumes you have Google Test set up.

```cpp
#include <gtest/gtest.h>
#include <omp.h>

// Assuming the translated C++ code is in a separate file, e.g., `translated_code.cpp`
// and the declaration of class A and Counter are in `translated_code.h`
#include "translated_code.h"

// Test fixture for Counter
class CounterTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset counters before each test
        Counter::counter = 0;
        Counter::pcounter = 0;
    }
};

// Test to verify the increment in parallel region
TEST_F(CounterTest, IncrementInParallel) {
    // Expected values after parallel execution
    int expected_counter = 1;
    int expected_pcounter = 1;

    // Execute the parallel region
    #pragma omp parallel
    {
        #pragma omp atomic
        Counter::counter++;
        #pragma omp atomic
        Counter::pcounter++;
    }

    // Check results
    EXPECT_EQ(Counter::counter, expected_counter);
    EXPECT_EQ(Counter::pcounter, expected_pcounter);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### Running the Tests

- **Fortran**: Compile and run the Fortran test program as you would with any Fortran program. The output will indicate whether the test passed.
  
  ```sh
  gfortran -fopenmp test_DRB087.f90 -o test_DRB087
  ./test_DRB087
  ```

- **C++ with Google Test**:
  1. Ensure Google Test is installed and set up in your project.
  2. Compile the test code along with the Google Test library. The exact command depends on your setup, but it might look something like this:

     ```sh
     g++ -fopenmp -lgtest -lgtest_main -pthread test_translated_code.cpp -o test_translated_code
     ```

  3. Run the compiled test executable:

     ```sh
     ./test_translated_code
     ```

This setup will run the unit tests for both the Fortran and C++ versions, verifying that the translation maintains the intended functionality.
