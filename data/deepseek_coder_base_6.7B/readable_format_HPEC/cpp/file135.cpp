Certainly! Below is the translated Fortran code to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int count = 0;

    #pragma omp parallel shared(count)
    {
        #pragma omp single
        {
            count = count + 1;
        }
    }

    std::cout << "count = " << count << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The `main` function is the entry point of the C++ program.
3. **Variable Declaration**: The variable `count` is declared as an integer.
4. **Initialization**: The variable `count` is initialized to 0.
5. **Parallel Region**: The `#pragma omp parallel shared(count)` directive is used to start a parallel region with the shared variable `count`.
6. **Single Region**: The `#pragma omp single` directive is used to ensure that only one thread executes the code inside the single region.
7. **Increment**: The variable `count` is incremented inside the single region.
8. **Output**: The value of `count` is printed to the standard output.

This C++ code should behave similarly to the provided Fortran code, with the addition of OpenMP directives for parallelism.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code to verify the correctness of the translation.

### Fortran Unit Test Code

To test the Fortran code, you can use a simple script that runs the program multiple times and checks if the output is consistent.

```fortran
program test_drb077
    implicit none
    integer :: count
    integer :: i
    integer :: errors

    errors = 0

    ! Run the program multiple times
    do i = 1, 10
        call run_program(count)
        if (count /= 1) then
            print *, "Test failed for iteration ", i
            errors = errors + 1
        end if
    end do

    if (errors == 0) then
        print *, "All tests passed."
    else
        print *, "Number of failed tests: ", errors
    end if

contains

    subroutine run_program(count)
        use omp_lib
        implicit none
        integer, intent(out) :: count
        count = 0

        !$omp parallel shared(count)
            !$omp single
            count = count + 1
            !$omp end single
        !$omp end parallel
    end subroutine run_program

end program test_drb077
```

### C++ Unit Test Code

To test the C++ code, you can use a similar approach by running the program multiple times and checking the output.

```cpp
#include <omp.h>
#include <iostream>
#include <vector>

void run_program(int& count) {
    count = 0;

    #pragma omp parallel shared(count)
    {
        #pragma omp single
        {
            count = count + 1;
        }
    }
}

int main() {
    int count = 0;
    int errors = 0;

    // Run the program multiple times
    for (int i = 0; i < 10; ++i) {
        run_program(count);
        if (count != 1) {
            std::cout << "Test failed for iteration " << i << std::endl;
            errors++;
        }
    }

    if (errors == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Number of failed tests: " << errors << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_drb077` program initializes a counter `errors` to 0.
   - It then runs the `run_program` subroutine 10 times.
   - If the output of `count` is not 1, it prints a failure message and increments `errors`.
   - After running all iterations, it prints whether all tests passed or the number of failed tests.

2. **C++ Unit Test Code**:
   - The `main` function initializes a counter `errors` to 0.
   - It then calls the `run_program` function 10 times.
   - If the output of `count` is not 1, it prints a failure message and increments `errors`.
   - After running all iterations, it prints whether all tests passed or the number of failed tests.

By running these unit tests, you can verify that the translated C++ code behaves the same as the original Fortran code.
