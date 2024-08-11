#include <iostream>
#include <cstddef>

class pr32601 {
public:
    // In C++, returning a pointer to a local variable is dangerous
    // because the variable will go out of scope when the function returns.
    // However, to replicate the Fortran example's behavior as closely as possible,
    // we ignore this issue. In real applications, avoid returning pointers to local variables.
    static int* get_ptr() {
        static int x; // Making 'x' static to extend its lifetime beyond the function scope
        return &x;
    }
};

int main() {
    // Demonstrating null pointer
    int* t = nullptr;
    std::cout << "Demonstrating nullptr: " << t << std::endl;

    // Demonstrating pointer to a function that returns a pointer to an integer
    int* ptr = pr32601::get_ptr();
    std::cout << "Pointer from get_ptr(): " << ptr << std::endl;
    std::cout << "Value pointed to by ptr (uninitialized, may vary): " << *ptr << std::endl; // This will show an uninitialized value

    return 0;
}