Certainly! Below is the translated Fortran code to C++:

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int i = 1;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp critical(NAME)
            {
                #pragma omp parallel
                {
                    #pragma omp single
                    {
                        i = i + 1;
                    }
                }
            }
        }
    }

    std::cout << "i = " << i << std::endl;

    return 0;
}
```

### Explanation:
1. **Include OpenMP**: The `#include <omp.h>` directive is used to include the OpenMP library in C++.
2. **Main Function**: The `main` function is the entry point of the C++ program.
3. **Variable Declaration**: The variable `i` is declared and initialized to `1`.
4. **Parallel Sections**: The `#pragma omp parallel sections` directive is used to create parallel sections.
5. **Sections**: Each section is created using `#pragma omp section`.
6. **Critical Section**: The critical section is created using `#pragma omp critical(NAME)`.
7. **Parallel Region**: Inside the critical section, a parallel region is created using `#pragma omp parallel`.
8. **Single Region**: Inside the parallel region, a single region is created using `#pragma omp single`.
9. **Increment Operation**: The variable `i` is incremented inside the single region.
10. **Output**: The value of `i` is printed to the console using `std::cout`.

This C++ code mirrors the structure and behavior of the original Fortran code, including the use of parallel sections, critical sections, and single regions.
Let's write some test to verify if the translation is correct. 
Below are the unit test codes for both the original Fortran code and the translated C++ code.

### Fortran Unit Test Code

```fortran
program test_drb139_worksharingcritical_orig_no
    use omp_lib
    implicit none

    integer :: i
    integer :: num_threads
    integer :: num_sections
    integer :: num_critical
    integer :: num_parallel
    integer :: num_single

    i = 1
    num_threads = 0
    num_sections = 0
    num_critical = 0
    num_parallel = 0
    num_single = 0

    !$OMP PARALLEL PRIVATE(i)
    !$OMP SECTIONS
    !$OMP SECTION
    !$OMP CRITICAL (NAME)
    !$OMP PARALLEL PRIVATE(i)
    !$OMP SINGLE
    i = i + 1
    !$OMP END SINGLE
    !$OMP END PARALLEL
    !$OMP END CRITICAL (NAME)
    !$OMP END SECTION
    !$OMP END SECTIONS
    !$OMP END PARALLEL

    !$OMP PARALLEL SECTIONS PRIVATE(i) REDUCTION(+:num_threads, num_sections, num_critical, num_parallel, num_single)
    !$OMP SECTION
    num_sections = num_sections + 1
    !$OMP SECTION
    num_sections = num_sections + 1
    !$OMP END SECTIONS
    !$OMP END PARALLEL SECTIONS

    print *, "i = ", i
    print *, "Number of threads: ", num_threads
    print *, "Number of sections: ", num_sections
    print *, "Number of critical sections: ", num_critical
    print *, "Number of parallel regions: ", num_parallel
    print *, "Number of single regions: ", num_single
end program test_drb139_worksharingcritical_orig_no
```

### C++ Unit Test Code

```cpp
#include <omp.h>
#include <iostream>

int main() {
    int i = 1;
    int num_threads = 0;
    int num_sections = 0;
    int num_critical = 0;
    int num_parallel = 0;
    int num_single = 0;

    #pragma omp parallel private(i)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                #pragma omp critical(NAME)
                {
                    #pragma omp parallel private(i)
                    {
                        #pragma omp single
                        {
                            i = i + 1;
                        }
                    }
                }
            }
        }
    }

    #pragma omp parallel sections private(i) reduction(+:num_threads, num_sections, num_critical, num_parallel, num_single)
    {
        #pragma omp section
        {
            num_sections++;
        }
        #pragma omp section
        {
            num_sections++;
        }
    }

    std::cout << "i = " << i << std::endl;
    std::cout << "Number of threads: " << num_threads << std::endl;
    std::cout << "Number of sections: " << num_sections << std::endl;
    std::cout << "Number of critical sections: " << num_critical << std::endl;
    std::cout << "Number of parallel regions: " << num_parallel << std::endl;
    std::cout << "Number of single regions: " << num_single << std::endl;

    return 0;
}
```

### Explanation:

1. **Fortran Unit Test Code**:
   - The `test_drb139_worksharingcritical_orig_no` program initializes the variables `i`, `num_threads`, `num_sections`, `num_critical`, `num_parallel`, and `num_single`.
   - It then performs the parallel sections, sections, critical sections, parallel regions, and single regions as in the original Fortran code.
   - Finally, it prints the values of `i` and the counters for parallel sections, sections, critical sections, parallel regions, and single regions.

2. **C++ Unit Test Code**:
   - The main function initializes the variables `i`, `num_threads`, `num_sections`, `num_critical`, `num_parallel`, and `num_single`.
   - It then performs the parallel sections, sections, critical sections, parallel regions, and single regions as in the translated C++ code.
   - Finally, it prints the values of `i` and the counters for parallel sections, sections, critical sections, parallel regions, and single regions.

### Compilation and Execution:

1. **Fortran**:
   - Compile the Fortran code using a Fortran compiler that supports OpenMP, e.g., `gfortran`:
     ```sh
     gfortran -fopenmp test_drb139_worksharingcritical_orig_no.f90 -o test_drb139_worksharingcritical_orig_no
     ```
   - Execute the program:
     ```sh
     ./test_drb139_worksharingcritical_orig_no
     ```

2. **C++**:
   - Compile the C++ code using a C++ compiler that supports OpenMP, e.g., `g++`:
     ```sh
     g++ -fopenmp test_drb139_worksharingcritical_orig_no.cpp -o test_drb139_worksharingcritical_orig_no
     ```
   - Execute the program:
     ```sh
     ./test_drb139_worksharingcritical_orig_no
     ```

These unit tests will help verify the correctness of the translation by comparing the output of both programs.
