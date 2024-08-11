#include <iostream>

// Declaration and definition of setupReceivers in the same file
void setupReceivers() {
    std::cout << "Setup receivers called" << std::endl;
}

// Main function to test setupReceivers
int main() {
    setupReceivers();
    return 0;
}