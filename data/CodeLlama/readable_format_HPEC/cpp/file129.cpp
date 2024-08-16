#include <iostream>
#include <omp.h>
#include <unistd.h> // For sleep()

int main() {
    int result = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskgroup
            {
                #pragma omp task
                {
                    sleep(3); // Sleep for 3 seconds
                    result = 1;
                }
            }
            #pragma omp task
            {
                result = 2;
            }
        }
    }

    std::cout << "result = " << result << std::endl;

    return 0;
}
