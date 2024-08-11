#include <iostream>

// Definition of f1 directly in the C++ source file.
extern "C" void f1() {
    #pragma acc kernels default(none)
    {
        // Body of kernels region with default(none)
    }
    #pragma acc end kernels

    #pragma acc parallel default(none)
    {
        // Body of parallel region with default(none)
    }
    #pragma acc end parallel

    #pragma acc kernels default(present)
    {
        // Body of kernels region with default(present)
    }
    #pragma acc end kernels

    #pragma acc parallel default(present)
    {
        // Body of parallel region with default(present)
    }
    #pragma acc end parallel
}

int main() {
    f1(); // Call the function

    std::cout << "C++ function f1 executed successfully." << std::endl;

    return 0;
}