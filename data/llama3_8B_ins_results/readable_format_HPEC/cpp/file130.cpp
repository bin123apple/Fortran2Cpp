#include <iostream>
#include <omp.h>

int main() {
    int section_count = 0;

    omp_set_dynamic(false);
    omp_set_num_threads(1);

    #pragma omp parallel
    {
        #pragma omp sections firstprivate(section_count)
        {
            #pragma omp section
            {
                section_count++;
                std::cout << "section_count = " << section_count << std::endl;
            }

            #pragma omp section
            {
                section_count++;
                std::cout << "section_count = " << section_count << std::endl;
            }
        }
    }

    return 0;
}
