#include <iostream>

namespace SETUP_EXACT_UNDOING_TO_DISK__genmod {
    bool setupDone = false;
    
    void SETUP_EXACT_UNDOING_TO_DISK() {
        setupDone = true;
    }
}

int main() {
    // Call the function to set up exact undoing to disk
    SETUP_EXACT_UNDOING_TO_DISK__genmod::SETUP_EXACT_UNDOING_TO_DISK();
    
    // Simple test to check if the setupDone flag was set to true
    if (SETUP_EXACT_UNDOING_TO_DISK__genmod::setupDone) {
        std::cout << "Test Passed: setupDone is TRUE." << std::endl;
    } else {
        std::cout << "Test Failed: setupDone is FALSE." << std::endl;
    }
    
    return 0;
}