#include <iostream>
#include <omp.h>
#include <thread>

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
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    result = 1;
                }
                #pragma omp task
                {
                    result = 2;
                }
            }
        }
    }

    std::cout << "result = " << result << std::endl;

    return 0;
}
