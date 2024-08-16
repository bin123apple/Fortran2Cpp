To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code, then map it to C++ syntax and OpenMP directives. The Fortran code demonstrates the use of OpenMP tasks with dependencies, where tasks are executed in parallel and their execution order is controlled by dependencies.

Here's a C++ version of the code, using OpenMP for parallelism and task dependencies:

```cpp
#include <iostream>
#include <omp.h>
#include <unistd.h> // for sleep()

int main() {
    int i, j, k;
    i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                sleep(3); // Sleep for 3 seconds to simulate a long running task
                i = 1;
            }
            #pragma omp task depend(in:i)
            {
                j = i;
            }
            #pragma omp task depend(in:i)
            {
                k = i;
            }
        }
    }

    std::cout << "j = " << j << " k = " << k << std::endl;

    if (j != 1 && k != 1) {
        std::cout << "Race Condition" << std::endl;
    }

    return 0;
}
```

### Key Points:

1. **Include OpenMP and Sleep Headers**: The `#include <omp.h>` directive is used to enable OpenMP functionalities, and `#include <unistd.h>` is included for the `sleep()` function, which is used to simulate a long running task.

2. **Variable Declarations**: The variables `i`, `j`, and `k` are declared at the beginning of the `main` function.

3. **Initialization**: The variable `i` is initialized to 0.

4. **OpenMP Parallel Region**: The `#pragma omp parallel` directive starts a parallel region. Inside this region, an `#pragma omp single` directive ensures that the enclosed block is executed by a single thread.

5. **OpenMP Tasks**: Three `#pragma omp task` directives are used to create tasks. The `depend` clause is used to specify dependencies between tasks.

6. **Sleep Function**: The `sleep(3)` function is used to simulate a long running task. Note that the actual sleep time can be adjusted as needed.

7. **Output**: The values of `j` and `k` are printed to the standard output.

8. **Race Condition Check**: If `j` and `k` are not both 1, a message indicating a race condition is printed.

### Compilation and Execution:
To compile and run this C++ code with OpenMP support, you can use a command similar to the following (assuming you have an OpenMP-capable compiler like `g++`):

```sh
g++ -fopenmp your_program.cpp -o your_program
./your_program
```

This command also enables OpenMP (`-fopenmp`) and compiles the program into an executable named `your_program`.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the original Fortran code and the translated C++ code involves checking the functionality that was demonstrated in the main program. However, the original programs are designed to demonstrate the use of OpenMP tasks with dependencies, which can be hard to test directly in a unit test framework without introducing additional complexity. Instead, I'll outline how you might approach testing these programs by modifying them slightly to make them more testable.

### Modified Fortran Program for Testing

For the Fortran program, we can modify it to return values that can be easily tested. However, due to the nature of the original program (which involves sleeping and race conditions), a direct unit test in the traditional sense isn't straightforward. Instead, you could modify the program to output specific values for testing purposes.

### Modified C++ Program for Testing

For the C++ program, we can encapsulate the functionality into functions that can be called with parameters or return values for testing.

### Testing Approach

For both Fortran and C++, the testing approach will involve:

1. Modifying the programs to make them more testable.
2. Writing test cases that call these modified functions and check the results.

### Fortran Testing Example

Since the original Fortran program is quite complex and not straightforward to test in a traditional sense, you might consider a modified version that returns values for testing.

### C++ Testing Example

Here's how you might encapsulate the functionality into functions in C++ for testing:

```cpp
#include <iostream>
#include <omp.h>
#include <unistd.h> // for sleep()

// Encapsulate the functionality into functions for easier testing
int performTaskWithDependency() {
    int i, j, k;
    i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                sleep(3); // Sleep for 3 seconds to simulate a long running task
                i = 1;
            }
            #pragma omp task depend(in:i)
            {
                j = i;
            }
            #pragma omp task depend(in:i)
            {
                k = i;
            }
        }
    }

    // Return a value that can be tested
    return j;
}

int main() {
    int result = performTaskWithDependency();
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

### Writing Unit Tests

For both Fortran and C++, you would write a separate program or function that calls the modified functions and checks the results. This might involve using a testing framework or simply writing custom checks.

#### Custom Testing Example for C++

```cpp
#include <iostream>

// Assuming performTaskWithDependency() is declared in another file
extern int performTaskWithDependency();

void testPerformTaskWithDependency() {
    int result = performTaskWithDependency();
    if (result == 1) {
        std::cout << "Test passed: Result is 1" << std::endl;
    } else {
        std::cout << "Test failed: Result is not 1" << std::endl;
    }
}

int main() {
    testPerformTaskWithDependency();
    return 0;
}
```

### Compiling and Running Tests

For Fortran, you would compile and run your tests using a Fortran compiler, and for C++, you would use a C++ compiler with OpenMP support enabled.

### Conclusion

Testing these programs requires making significant changes to make them more testable. The provided examples are simplified and focus on illustrating how you might approach testing rather than providing a comprehensive testing solution.
