#include <iostream>
#include <string>

int main() {
    // Equivalent of .not..true.
    std::cout << std::boolalpha << !true << std::endl;

    // Equivalent of .not..false.
    std::cout << std::boolalpha << !false << std::endl;

    // Equivalent of .not..false..eqv..true. (For .eqv., we use == as it's logical equivalence)
    std::cout << std::boolalpha << (!(false) == true) << std::endl;

    // For string comparisons, we will use the == operator in C++
    std::cout << std::boolalpha << (std::string("hello") == std::string("hello")) << std::endl;
    std::cout << std::boolalpha << (std::string("hello") == std::string("world")) << std::endl;

    // Concatenating strings and comparing
    std::cout << std::boolalpha << (std::string("hello world") == std::string("hello") + std::string(" world")) << std::endl;

    return 0;
}