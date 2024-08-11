#include <iostream>

// Declare the namespace and function directly in this file.
namespace mecip_I {
    void mecip() {
        std::cout << "Executing mecip function." << std::endl;
    }
}

int main() {
    // Call the function from the namespace.
    mecip_I::mecip();
    return 0;
}