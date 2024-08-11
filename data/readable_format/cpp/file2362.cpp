#include <iostream>
#include <functional>

// Define type alias for function pointers
using FuncPtr = std::function<int(int, int)>;

// Definition of the add function
int add(int a, int b) {
    return a + b;
}

// Function to set the function pointer
void set_ptr(FuncPtr& f1, FuncPtr& f2) {
    f2 = f1;
}

int main() {
    // Declare function pointers
    FuncPtr forig = add;
    FuncPtr fset;

    // Set fset to point to the same function as forig
    set_ptr(forig, fset);

    // Check if the function pointers work correctly
    if (forig(1, 2) != fset(1, 2)) {
        std::cerr << "Error: Function pointers do not match." << std::endl;
        return 1;
    }

    std::cout << "Function pointers match." << std::endl;
    return 0;
}