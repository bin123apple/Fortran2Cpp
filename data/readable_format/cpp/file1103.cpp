#include <iostream>
#include <omp.h>

int main() {
    int n = 100;
    int var = 0;

    #pragma omp parallel for reduction(+:var)
    for(int i = 1; i <= 100; ++i) {
        var = var + 1;
    }

    if(var != n) {
        std::cerr << "Error: The sum did not match the expected value." << std::endl;
        abort();
    }

    // Optional: print the result to verify
    std::cout << "Sum is: " << var << std::endl;

    return 0;
}