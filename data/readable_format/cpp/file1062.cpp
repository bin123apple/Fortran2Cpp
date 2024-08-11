#include <iostream>

int main() {
    if (false) {
        std::cout << "These lines" << std::endl;
        std::cout << "are not printed" << std::endl;
        std::cout << "if the the CLAW compiler has processed" << std::endl;
        std::cout << "the file." << std::endl;
    }
    return 0;
}