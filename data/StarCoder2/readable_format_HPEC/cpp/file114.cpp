#include <iostream>
#include <omp.h>

int main() {
    int* counter = nullptr; // Pointer initialization to nullptr

    // Allocate memory for counter
    counter = new int;

    *counter = 0; // Initialize counter to 0

    #pragma omp parallel
    {
        #pragma omp critical
        *counter = *counter + 1; // Increment counter in parallel
    }

    std::cout << *counter << std::endl; // Print the value of counter

    // Deallocate memory for counter
    delete counter;

    return 0;
}
