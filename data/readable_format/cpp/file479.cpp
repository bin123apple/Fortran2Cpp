#include <iostream>

int main() {
    int* a = nullptr; // Pointer initialization to a null pointer.

    // Block to allocate and immediately deallocate memory.
    {
        // Allocate memory for 1000 integers.
        a = new int[1000];
        
        // Immediately deallocate the allocated memory.
        delete[] a;
    }

    return 0;
}