#include <openacc.h>
#include <cstdlib> // for std::abort

// Global variable
int a;

#pragma acc declare create(a)

int main() {
    // Check if 'a' is present on the accelerator
    if (!acc_is_present(&a, sizeof(a))) {
        std::abort();
    }

    return 0;
}