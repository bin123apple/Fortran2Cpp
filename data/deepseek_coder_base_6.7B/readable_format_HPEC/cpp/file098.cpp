To translate the given Fortran code to C++, we need to understand the functionality of the Fortran code and then replicate that functionality in C++. The Fortran code uses OpenMP for parallel processing and writes an array to a file. Here's how you can translate it to C++:

```cpp
#include <iostream>
#include <fstream>
#include <omp.h>

int main() {
    const int len = 1000;
    int a[len];
    bool exist;
    std::string filename = "mytempfile.txt";

    // Populate the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1;
    }

    // Check if the file exists
    std::ifstream file(filename);
    exist = file.good();
    file.close();

    // Open the file
    std::ofstream outFile;
    if (exist) {
        outFile.open(filename, std::ios_base::app); // Append if file exists
    } else {
        outFile.open(filename); // Create new file
    }

    if (!outFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // Write the array to the file in parallel
    #pragma omp parallel for
    for (int i = 0; i < len; ++i) {
        outFile << a[i] << std::endl;
    }

    outFile.close();

    // Delete the file if successful
    if (outFile.good()) {
        if (std::remove(filename.c_str()) != 0) {
            std::cerr << "Error deleting the file." << std::endl;
        }
    }

    return 0;
}
```

### Explanation:
1. **Include Libraries**: We include `<iostream>` for input/output operations, `<fstream>` for file operations, and `<omp.h>` for OpenMP.
2. **Constants and Variables**: We define the length of the array and the filename.
3. **Populate the Array**: We fill the array with values from 1 to 1000.
4. **Check File Existence**: We check if the file `mytempfile.txt` exists using an `std::ifstream`.
5. **Open the File**: We open the file in append mode if it exists or create a new file if it doesn't.
6. **Write to File in Parallel**: We use OpenMP to parallelize the writing operation. Each thread writes its portion of the array to the file.
7. **Close and Delete the File**: We close the file and delete it if successful.

### Compilation:
To compile this C++ code with OpenMP support, you can use a command similar to the following (assuming you have a C++ compiler that supports OpenMP, such as g++):

```sh
g++ -fopenmp -o DRB049_fprintf_orig_no DRB049_fprintf_orig_no.cpp
```

This command enables OpenMP and compiles the C++ code into an executable named `DRB049_fprintf_orig_no`.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the Fortran and C++ code involves checking the functionality of file creation, writing to file, and deletion. Below are the unit test codes for both languages.

### Fortran Unit Test Code

To test the Fortran code, you can create a simple test program that calls the original program and checks if the file `mytempfile.txt` is created and contains the correct data.

```fortran
program test_DRB049_fprintf_orig_no
    implicit none
    integer :: i, len, stat
    integer, allocatable :: a(:)
    logical :: exist
    character(len=100) :: line
    character(len=100) :: filename

    filename = "mytempfile.txt"
    len = 1000
    allocate(a(len))

    ! Call the original program
    call execute_command_line("DRB049_fprintf_orig_no")

    ! Check if the file exists
    inquire(file=filename, exist=exist)
    if (.not. exist) then
        print *, "Test failed: File does not exist."
        stop
    end if

    ! Read the file and check the contents
    open(unit=10, file=filename, status="old", action="read")
    do i = 1, len
        read(10, *) a(i)
        if (a(i) /= i) then
            print *, "Test failed: Incorrect data in file."
            stop
        end if
    end do
    close(10)

    ! Delete the file
    open(unit=11, file=filename, status="old", action="delete")
    close(11, status="delete")

    print *, "Test passed: File created and data written correctly."
end program test_DRB049_fprintf_orig_no
```

### C++ Unit Test Code

For the C++ code, you can use a testing framework like Google Test to create a unit test. However, for simplicity, the following code uses basic file operations to check the functionality.

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

bool checkFileContent(const std::string& filename, int len) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return false;
    }

    std::string line;
    int i = 0;
    while (std::getline(file, line)) {
        if (std::stoi(line) != i + 1) {
            file.close();
            return false;
        }
        ++i;
    }

    file.close();
    return true;
}

int main() {
    const int len = 1000;
    std::string filename = "mytempfile.txt";

    // Call the original program
    system("./DRB049_fprintf_orig_no");

    // Check if the file exists and has the correct content
    if (!checkFileContent(filename, len)) {
        std::cerr << "Test failed: File does not exist or contains incorrect data." << std::endl;
        return 1;
    }

    // Delete the file
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Error deleting the file." << std::endl;
        return 1;
    }

    std::cout << "Test passed: File created and data written correctly." << std::endl;
    return 0;
}
```

### Compilation and Execution

#### Fortran

1. Save the Fortran test code in a file named `test_DRB049_fprintf_orig_no.f90`.
2. Compile the Fortran test code with a command similar to:
   ```sh
   gfortran -fopenmp -o test_DRB049_fprintf_orig_no test_DRB049_fprintf_orig_no.f90
   ```
3. Run the test:
   ```sh
   ./test_DRB049_fprintf_orig_no
   ```

#### C++

1. Save the C++ test code in a file named `test_DRB049_fprintf_orig_no.cpp`.
2. Compile the C++ test code with a command similar to:
   ```sh
   g++ -fopenmp -o test_DRB049_fprintf_orig_no test_DRB049_fprintf_orig_no.cpp
   ```
3. Run the test:
   ```sh
   ./test_DRB049_fprintf_orig_no
   ```

These tests will verify that the file `mytempfile.txt` is created, contains the correct data, and is deleted correctly after writing.
