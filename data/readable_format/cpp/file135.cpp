// Combined C++ code with the struct definition and the test code in one file

#include <array> // For std::array
#include <iostream>

namespace lib {
    int i;
    int mpi_err, req_recv, req_send;

    struct Kozo {
        std::array<double, 42> U;
        std::array<double, 42> V;
    };

    Kozo Iriguchi;
    Kozo Deguchi;
}

int main() {
    // Initialize some values
    lib::Iriguchi.U[0] = 1.0;
    lib::Iriguchi.V[0] = 2.0;
    lib::Deguchi.U[0] = 3.0;
    lib::Deguchi.V[0] = 4.0;

    // Print values to verify
    std::cout << "Iriguchi.U[0]: " << lib::Iriguchi.U[0] << std::endl;
    std::cout << "Iriguchi.V[0]: " << lib::Iriguchi.V[0] << std::endl;
    std::cout << "Deguchi.U[0]: " << lib::Deguchi.U[0] << std::endl;
    std::cout << "Deguchi.V[0]: " << lib::Deguchi.V[0] << std::endl;

    return 0;
}