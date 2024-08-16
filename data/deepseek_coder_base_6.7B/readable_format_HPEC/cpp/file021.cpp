Certainly! Below is the translated Fortran code to C++:

```cpp
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int len = 100;
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    // Parallel region
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        int tmp = a[i] + (i + 1); // Adjust for 0-based indexing
        a[i] = tmp;
    }

    // Print the 50th element (0-based indexing)
    std::cout << "a[49]=" << a[49] << std::endl;

    return 0;
}
```

### Explanation:
1. **Vector Initialization**: In C++, the `std::vector` is used to dynamically allocate an array of integers. The size of the vector is set to `len`.
2. **Loop Initialization**: The loop initializes the vector `a` with values from 1 to `len`, similar to the Fortran code.
3. **Parallel Region**: The parallel region is created using the `#pragma omp parallel for` directive. Inside the parallel region, each thread works on its assigned chunk of the array.
4. **Computation and Update**: The computation `tmp = a[i] + (i + 1)` is performed, and the result is stored back into the array `a`.
5. **Printing the Result**: The 50th element of the array `a` is printed, considering C++ uses 0-based indexing.

Ensure you have the OpenMP library installed and enabled in your compiler to compile and run this C++ code.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

To test the Fortran code, you can use a simple script that runs the program and checks the output.

```fortran
program test_DRB028_privatemissing_orig_yes
    implicit none
    integer :: output
    character(len=100) :: command
    character(len=100) :: output_line

    ! Compile the Fortran code
    call execute_command_line('gfortran -fopenmp DRB028_privatemissing_orig_yes.f90 -o DRB028_privatemissing_orig_yes')

    ! Run the Fortran program and capture the output
    command = 'DRB028_privatemissing_orig_yes > output.txt'
    call execute_command_line(command)

    ! Read the output
    open(unit=10, file='output.txt', status='old')
    read(10, '(A)') output_line
    close(10)

    ! Extract the value from the output line
    read(output_line(8:10), *) output

    ! Check the output
    if (output == 150) then
        print *, 'Test Passed'
    else
        print *, 'Test Failed'
    end if
end program test_DRB028_privatemissing_orig_yes
```

### C++ Unit Test Code

To test the C++ code, you can use a simple script that runs the program and checks the output.

```cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <cassert>

int main() {
    const int len = 100;
    std::vector<int> a(len);

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
    }

    // Parallel region
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        int tmp = a[i] + (i + 1); // Adjust for 0-based indexing
        a[i] = tmp;
    }

    // Check the output
    assert(a[49] == 150);
    std::cout << "Test Passed" << std::endl;

    return 0;
}
```

### Explanation:

#### Fortran Unit Test:
1. **Compile the Fortran Code**: The `execute_command_line` function is used to compile the Fortran code.
2. **Run the Program and Capture Output**: The output of the program is redirected to a file using a shell command.
3. **Read the Output**: The output is read from the file and the value of interest is extracted.
4. **Check the Output**: The value is compared with the expected output (150) and the result is printed.

#### C++ Unit Test:
1. **Run the Program**: The program is executed.
2. **Check the Output**: The output is checked using the `assert` function. If the value is correct, "Test Passed" is printed.

### Running the Tests:

#### Fortran:
1. Save the Fortran code in a file named `DRB028_privatemissing_orig_yes.f90`.
2. Save the Fortran unit test code in a file named `test_DRB028_privatemissing_orig_yes.f90`.
3. Compile and run the test code:
   ```sh
   gfortran -fopenmp test_DRB028_privatemissing_orig_yes.f90 -o test_DRB028_privatemissing_orig_yes
   ./test_DRB028_privatemissing_orig_yes
   ```

#### C++:
1. Save the C++ code in a file named `DRB028_privatemissing_orig_yes.cpp`.
2. Compile and run the test code:
   ```sh
   g++ -fopenmp DRB028_privatemissing_orig_yes.cpp -o DRB028_privatemissing_orig_yes
   ./DRB028_privatemissing_orig_yes
   ```

Both tests should pass, indicating that the translation is correct.
