#include <iostream>

int main() {
    const int n = 2;
    int a[n];
    int* ptr = nullptr;
    ptr = a; // pointing ptr to the start of array a

    a[0] = 0;
    ptr[0] = 1; // modifying the first element of a through ptr

    // Optional: Print to verify the change
    std::cout << "a[0]: " << a[0] << std::endl;
    return 0;
}