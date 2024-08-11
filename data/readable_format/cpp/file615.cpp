// File: test.cpp
#include <iostream>

// Conditional compilation to check if MPI is enabled
#ifdef __MPI
#include <mpi.h>
constexpr bool tparallel = true;
#else
constexpr bool tparallel = false;
#endif

int main() {
    // Use the tparallel flag to determine whether MPI support is enabled
    if (tparallel) {
        std::cout << "MPI is enabled." << std::endl;
        // Initialize MPI environment here if necessary
        // MPI_Init(NULL, NULL);
        // MPI_Finalize();
    } else {
        std::cout << "MPI is not enabled." << std::endl;
    }

    // Additional program logic goes here
    return 0;
}