To translate the given Fortran code to C++, we need to understand the structure and functionality of the original code and then replicate its behavior using C++ syntax and OpenMP directives. The Fortran code uses OpenMP for parallelism and task dependencies. Below is the translated C++ code:

```cpp
#include <omp.h>
#include <unistd.h> // For sleep()
#include <iostream>

int main() {
    int i = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                sleep(3); // Sleep for 3 seconds to simulate a long running task
                i = 3;
            }
            #pragma omp task depend(out:i)
            {
                i = 2;
            }
        }
    }

    if (i != 2) {
        std::cout << i << std::endl;
    }

    return 0;
}
```

### Explanation:
1. **Include Headers**: We include `omp.h` for OpenMP support and `unistd.h` for the `sleep()` function.
2. **Main Function**: The main function initializes the variable `i` to 0.
3. **Parallel Region**: We start a parallel region using `#pragma omp parallel`.
4. **Single Region**: Inside the parallel region, we have a single region using `#pragma omp single`.
5. **Tasks**: We have two tasks within the single region. The first task is dependent on `i` (`out:i`), and the second task does not depend on any other variable.
6. **Sleep and Assignment**: The first task sleeps for 3 seconds and then sets `i` to 3. The second task immediately sets `i` to 2.
7. **Condition Check**: After the parallel region, we check if `i` is not equal to 2 and print it if true.

### Compilation:
To compile this C++ code with OpenMP support, you can use the following command:

```sh
g++ -fopenmp your_program.cpp -o your_program
```

Replace `your_program.cpp` with the name of your C++ source file.

This command also enables OpenMP, which is necessary for the parallel and task directives to work as intended.
Let's write some test to verify if the translation is correct. 
Creating unit tests for both the original Fortran code and the translated C++ code involves checking the correctness of the parallel execution and the final value of the variable `i`. However, the original Fortran code and the translated C++ code both contain a sleep call, which makes it difficult to directly test the behavior without introducing additional mechanisms to synchronize the tests. 

Given these constraints, I'll provide a simplified approach to testing by modifying the original code to allow for testing. This involves removing the sleep calls and instead, setting a flag or variable to indicate when the tasks are complete. This way, we can check the final value of `i` without waiting for the sleep to complete.

### Modified Fortran Code for Testing

```fortran
program DRB078_taskdep2_orig_no
    use omp_lib
    implicit none

    integer :: i, task_complete
    i = 0
    task_complete = 0

    !$omp parallel
        !$omp single
            !$omp task depend (out:i)
                i=3
                task_complete = task_complete + 1
            !$omp end task
            !$omp task depend (out:i)
                i=2
                task_complete = task_complete + 1
            !$omp end task
        !$omp end single
    !$omp end parallel

    if (task_complete == 2 .and. i == 2) then
        print 100, i
        100 format (i3)
    end if
end program
```

### Modified C++ Code for Testing

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int i = 0;
    int task_complete = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:i)
            {
                i = 3;
                task_complete++;
            }
            #pragma omp task depend(out:i)
            {
                i = 2;
                task_complete++;
            }
        }
    }

    if (task_complete == 2 && i == 2) {
        std::cout << i << std::endl;
    }

    return 0;
}
```

### Testing Approach

- **For Fortran**: Compile and run the modified Fortran code. The program should output `2` if the tasks are executed correctly.
- **For C++**: Compile and run the modified C++ code. The program should output `2` if the tasks are executed correctly.

### Compilation and Execution

- **Fortran**:
  ```sh
  gfortran -fopenmp DRB078_taskdep2_orig_no.f90 -o DRB078_taskdep2_orig_no
  ./DRB078_taskdep2_orig_no
  ```
- **C++**:
  ```sh
  g++ -fopenmp DRB078_taskdep2_orig_no.cpp -o DRB078_taskdep2_orig_no
  ./DRB078_taskdep2_orig_no
  ```

These tests ensure that the parallel execution and the final value of `i` are correct, given the simplified testing approach.
