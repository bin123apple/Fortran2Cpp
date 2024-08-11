#include <iostream>

int main() {
    // Dynamically allocate memory for a single integer
    int* x = new int;
    
    // It's good practice to check if allocation was successful, but omitted here for simplicity
    
    // Assuming the intent is to initialize it to a value, let's say 0, as Fortran default initializes to 0.
    *x = 0;

    // Print the value of the allocated integer
    std::cout << *x << std::endl;

    // Free the allocated memory
    delete x;
    
    return 0;
}