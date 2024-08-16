#include <iostream>
#include <omp.h>

int main() {
    int* counter = new int(0); // Dynamically allocate memory for counter and initialize it to 0

    #pragma omp parallel // OpenMP parallel region
    {
        #pragma omp atomic // Ensure atomic increment
        (*counter)++; // Increment the value of counter by 1 in a thread-safe manner
    }

    std::cout << *counter << std::endl; // Print the value of counter

    delete counter; // Deallocate the memory for counter

    return 0;
}
