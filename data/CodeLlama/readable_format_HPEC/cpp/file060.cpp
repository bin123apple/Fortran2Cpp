#include <iostream>
#include <omp.h>

int main() {
    int var = 0;

    // OpenMP pragma for targeting a specific device, in this case, the GPU with ID 0
    #pragma omp target device(0)
    {
        // Teams distribute parallel for with reduction on var
        #pragma omp teams distribute parallel for reduction(+:var)
        for (int i = 1; i <= 200; ++i) {
            if (var < 101) {
                var += 1;
            }
        }
    }

    // Optional: Print the result to verify
    std::cout << "var = " << var << std::endl;

    return 0;
}
