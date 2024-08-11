// File: ksbin1_aux_mod.cpp
#include <iostream>
#include <stdexcept>

class KSbin1AuxMod {
public:
    static int setbd() {
        return 42;
    }

    static void foo() {
        if (setbd() != 42) {
            throw std::runtime_error("Error in foo");
        }
        std::cout << "foo check passed" << std::endl;
    }
};

// Main program for direct execution
int main() {
    try {
        KSbin1AuxMod::foo();
        std::cout << "All C++ tests passed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
    }
    return 0;
}