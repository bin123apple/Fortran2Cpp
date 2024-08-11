// p.cpp
#include <iostream>

class T {
public:
    T() { std::cout << "Allocation successful." << std::endl; } // Constructor
    ~T() { std::cout << "Deallocation successful." << std::endl; } // Destructor
};

int main() {
    T* x = nullptr; // Pointer to T, initially null

    try {
        x = new T; // Allocate
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
        return 1;
    }

    delete x; // Deallocate
    x = nullptr;

    return 0;
}