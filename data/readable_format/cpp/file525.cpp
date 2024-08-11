#include <iostream>
#include <array>
#include <cassert>

class SaveKernelsOuterCore {
public:
    using Array4D = std::array<std::array<std::array<std::array<float, 1120>, 5>, 5>, 5>;

    static void saveKernelsOuterCore(
        Array4D& rhostoreOuterCore,
        Array4D& kappavstoreOuterCore,
        Array4D& rhoKlOuterCore,
        Array4D& alphaKlOuterCore) {
        // This is where the logic of your original Fortran subroutine would go.
        // For demonstration, let's just print something to indicate this function was called.
        std::cout << "saveKernelsOuterCore called" << std::endl;
        
        // Example operation - setting values for demonstration
        rhoKlOuterCore[0][0][0][0] = 3.0f;
        alphaKlOuterCore[0][0][0][0] = 4.0f;
    }
};

void testSaveKernelsOuterCore() {
    SaveKernelsOuterCore::Array4D rhostoreOuterCore = {};
    SaveKernelsOuterCore::Array4D kappavstoreOuterCore = {};
    SaveKernelsOuterCore::Array4D rhoKlOuterCore = {};
    SaveKernelsOuterCore::Array4D alphaKlOuterCore = {};
    
    // Assuming some initialization for these arrays...
    // For simplicity, let's skip actual initialization code.

    // Call the function
    SaveKernelsOuterCore::saveKernelsOuterCore(rhostoreOuterCore, kappavstoreOuterCore, rhoKlOuterCore, alphaKlOuterCore);
    
    // Perform some checks
    assert(rhoKlOuterCore[0][0][0][0] == 3.0f); // Example condition check
    assert(alphaKlOuterCore[0][0][0][0] == 4.0f); // Example condition check
    
    std::cout << "C++ test passed." << std::endl;
}

int main() {
    testSaveKernelsOuterCore();
    return 0;
}