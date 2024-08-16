Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <omp.h>

int main() {
    int var = 0;
    int sum1 = 0;
    int sum2 = 0;

    #pragma omp parallel reduction(+: var)
    {
        #pragma omp for schedule(static) reduction(+: sum1)
        for (int i = 1; i <= 5; ++i) {
            sum1 += i;
        }

        #pragma omp for schedule(static) reduction(+: sum2)
        for (int i = 1; i <= 5; ++i) {
            sum2 += i;
        }

        #pragma omp critical
        {
            var = sum1 + sum2;
        }
    }

    std::cout << "var = " << var << std::endl;

    return 0;
}
```

### Explanation:
1. **Include necessary headers**:
   - `#include <iostream>` for input/output operations.
   - `#include <omp.h>` for OpenMP functionalities.

2. **Declare variables**:
   - `int var = 0;`
   - `int sum1 = 0;`
   - `int sum2 = 0;`

3. **Parallel region with reduction**:
   - `#pragma omp parallel reduction(+: var)`

4. **First for loop with reduction**:
   - `#pragma omp for schedule(static) reduction(+: sum1)`
   - The loop iterates from 1 to 5 and updates `sum1`.

5. **Second for loop with reduction**:
   - `#pragma omp for schedule(static) reduction(+: sum2)`
   - The loop iterates from 1 to 5 and updates `sum2`.

6. **Critical section**:
   - `#pragma omp critical`
   - This ensures that only one thread can access `var` at a time, which is necessary to avoid race conditions.

7. **Compute `var`**:
   - `var = sum1 + sum2;`

8. **Print the result**:
   - `std::cout << "var = " << var << std::endl;`

This C++ code should produce the same output as the original Fortran code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

To test the Fortran code, you can use a simple script that runs the program and checks the output.

```fortran
program test_drb121_reduction_orig_no
    implicit none
    integer :: var, expected_var
    character(len=100) :: command, output

    ! Run the Fortran program
    command = 'a.out'
    call execute_command_line(command)

    ! Read the output
    open(unit=10, file='output.txt', status='old', action='read')
    read(10, *) output, var
    close(10)

    ! Expected value of var
    expected_var = 30

    ! Check if the output is as expected
    if (var == expected_var) then
        print *, 'Test passed.'
    else
        print *, 'Test failed. Expected:', expected_var, 'Got:', var
    end if
end program test_drb121_reduction_orig_no
```

### C++ Unit Test Code

To test the C++ code, you can use a similar approach. This example uses a simple script to compile and run the program, then checks the output.

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    // Compile the C++ program
    system("g++ -fopenmp -o test_drb121_reduction_orig_no test_drb121_reduction_orig_no.cpp");

    // Run the compiled program
    system("./test_drb121_reduction_orig_no > output.txt");

    // Read the output
    std::ifstream file("output.txt");
    std::string line;
    std::getline(file, line);
    file.close();

    // Expected value of var
    int expected_var = 30;

    // Extract the value of var from the output
    int var = std::stoi(line.substr(line.find("=") + 1));

    // Check if the output is as expected
    if (var == expected_var) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected: " << expected_var << " Got: " << var << std::endl;
    }

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_drb121_reduction_orig_no` program runs the original Fortran code.
   - It reads the output from the `output.txt` file and checks if the value of `var` matches the expected value.

2. **C++ Unit Test Code**:
   - The `test_drb121_reduction_orig_no.cpp` program compiles the translated C++ code using OpenMP.
   - It runs the compiled program and saves the output to `output.txt`.
   - It reads the output from `output.txt` and extracts the value of `var`.
   - It checks if the value of `var` matches the expected value.

### Running the Tests:

1. **Fortran**:
   - Save the Fortran code in a file named `drb121_reduction_orig_no.f90`.
   - Save the Fortran unit test code in a file named `test_drb121_reduction_orig_no.f90`.
   - Compile and run the Fortran unit test code:
     ```sh
     gfortran -fopenmp drb121_reduction_orig_no.f90 test_drb121_reduction_orig_no.f90 -o test_drb121_reduction_orig_no
     ./test_drb121_reduction_orig_no
     ```

2. **C++**:
   - Save the C++ code in a file named `test_drb121_reduction_orig_no.cpp`.
   - Compile and run the C++ unit test code:
     ```sh
     g++ -fopenmp test_drb121_reduction_orig_no.cpp -o test_drb121_reduction_orig_no
     ./test_drb121_reduction_orig_no
     ```

Both tests should output "Test passed." if the translation is correct.
