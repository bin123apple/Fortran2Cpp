#include <iostream>
#include <cstring>

union SharedMemory {
    char a[4];
    struct {
        char c1[3];
        char c2[3];
    } c;
};

int main() {
    SharedMemory shared;

    // Example of how to use the shared memory
    // Setting values - be careful with null-terminating characters
    strncpy(shared.a, "abc", 3); // Set 'a' affecting 'c1'
    shared.a[3] = '\0'; // Null-terminate 'a'
    strncpy(shared.c.c2, "def", 3); // Set 'c2' affecting 'b'

    // Since we're directly manipulating the memory, the 'b' part of the union
    // doesn't explicitly exist. It's conceptually the same as 'c.c2'.

    std::cout << "a: " << shared.a << std::endl; // Outputs: abc
    std::cout << "c1: " << shared.c.c1 << std::endl; // Outputs: abc
    std::cout << "c2: " << shared.c.c2 << std::endl; // Outputs: def

    // Demonstrating the shared memory effect
    strncpy(shared.c.c1, "xyz", 3); // This changes 'a' as well
    std::cout << "After changing c1:" << std::endl;
    std::cout << "a: " << shared.a << std::endl; // Outputs: xyz (shows shared memory effect)
    std::cout << "c1: " << shared.c.c1 << std::endl; // Outputs: xyz

    return 0;
}