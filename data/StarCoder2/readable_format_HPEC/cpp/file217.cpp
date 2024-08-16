#include <iostream>

// Assuming DATA_TYPE is a simple type like int or double, and DATA_PRINTF_MODIFIER is a format specifier like "%d" or "%f".
// You need to adjust these types and modifiers according to your actual Fortran code.
template<typename DATA_TYPE>
void print_array(DATA_TYPE output) {
    // Print the value with the specified format
    std::cout << DATA_PRINTF_MODIFIER << output << std::endl;
}

int main() {
    // Example usage
    print_array<int>(10); // Prints "10"
    print_array<double>(3.14); // Prints "3.14"
    
    return 0;
}
