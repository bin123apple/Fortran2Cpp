// file: omp_test.cpp
#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 1; i <= 10; ++i) {
            std::cout << "C++ loop 1 thread " << omp_get_thread_num() << " i=" << i << std::endl;
        }

        #pragma omp for
        for(int i = 1; i <= 10; ++i) {
            std::cout << "C++ loop 2 thread " << omp_get_thread_num() << " i=" << i << std::endl;
        }

        #pragma omp sections
        {
            #pragma omp section
            {
                std::cout << "C++ section 1 executed by thread " << omp_get_thread_num() << std::endl;
            }

            #pragma omp section
            {
                std::cout << "C++ section 2 executed by thread " << omp_get_thread_num() << std::endl;
            }
        }
    }

    return 0;
}