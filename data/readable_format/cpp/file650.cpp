#include <iostream>

// Assuming Container is a simple struct for demonstration purposes
struct Container {
    // Example member variable
    int id;
};

// Definition for the function pointer type
using cFuncPointer = void (*)();

// Function declarations and definitions
extern "C" {
    void convert_c_funcpointer(void* cpointer, cFuncPointer& fpointer) {
        fpointer = reinterpret_cast<cFuncPointer>(cpointer);
    }

    void allocate_Container(void** Container_cptr) {
        *Container_cptr = new Container();
    }

    void deallocate_Container(void* Container_cptr) {
        Container* Container_ptr = static_cast<Container*>(Container_cptr);
        delete Container_ptr;
    }
}

// Test function to use with convert_c_funcpointer
extern "C" void testFunction() {
    std::cout << "Function pointer conversion successful." << std::endl;
}

int main() {
    // Test convert_c_funcpointer
    cFuncPointer fpointer = nullptr;
    convert_c_funcpointer(reinterpret_cast<void*>(&testFunction), fpointer);
    fpointer(); // Should print a success message

    // Test allocate_Container and deallocate_Container
    void* Container_cptr = nullptr;
    allocate_Container(&Container_cptr);
    std::cout << "Container allocated." << std::endl;

    deallocate_Container(Container_cptr);
    std::cout << "Container deallocated." << std::endl;

    return 0;
}