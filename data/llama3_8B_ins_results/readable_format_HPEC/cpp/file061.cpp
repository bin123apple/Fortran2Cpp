#include <iostream>
#include <mutex>

int main() {
    int i = 1;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            std::lock_guard<std::mutex> lock;
            #pragma omp parallel
            {
                #pragma omp single
                {
                    i++;
                }
            }
        }
    }

    std::cout << "i = " << i << std::endl;

    return 0;
}
