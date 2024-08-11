#include <iostream>

// Assuming print_string is a simple function that prints a C-style string
extern "C" void print_string(const char* str) {
    std::cout << "String from C++: " << str << std::endl;
}

int main() {
    char arg[256] = "Hello from C++";
    char* c = arg;

    print_string(c);

    return 0;
}