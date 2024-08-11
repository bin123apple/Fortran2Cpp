#include <cstddef>

namespace pr37287_1 {
    void set_null(void*& ptr) {
        ptr = nullptr;
    }
}

// Example usage
#include <iostream>

int main() {
    int* myPtr = new int(10); // Example pointer allocation
    pr37287_1::set_null(reinterpret_cast<void*&>(myPtr));
    
    if (myPtr == nullptr) {
        std::cout << "Pointer is null." << std::endl;
    } else {
        std::cout << "Pointer is not null." << std::endl;
    }

    return 0;
}