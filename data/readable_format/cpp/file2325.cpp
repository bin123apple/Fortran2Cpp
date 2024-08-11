#include <iostream>
#include <cstdlib> // For std::abort

namespace modproc {
    // Forward declaration of sub
    int sub();

    // Typedef for the function pointer
    using bar_t = int(*)();

    // Function pointer for x
    bar_t bar = sub;

    // Definition of sub function
    int sub() {
        return -5;
    }
}

// Definition of x function
int x() {
    return -5;
}

int main() {
    // Using the namespace modproc
    using namespace modproc;

    // Test the function x
    if (x() != -5) {
        std::abort();
    }

    return 0;
}