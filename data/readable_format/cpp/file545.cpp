#include <iostream>

int main() {
    // Printing 'next is a form feed' and then a form feed character
    std::cout << "next is a form feed" << char(12) << std::endl;
    std::cout << "that was a form feed" << std::endl;

    // Printing 'this is BEL' followed by a BEL character
    std::cout << "this is BEL" << char(7) << std::endl;

    return 0;
}