// Corrected string literals for C++
#include <iostream>
#include <vector>

// Assuming CUSTOM_REAL is double for this example
using CUSTOM_REAL = double;
const int MAX_STRING_LEN = 1024; // Example constant
const CUSTOM_REAL FOUR_THIRDS = 4.0 / 3.0;
const CUSTOM_REAL R_EARTH_KM = 6371.0;

// Example class based on the tomography_par module
class TomographyPar {
public:
    int NSPEC = 0, NGLOB = 0;
    std::vector<CUSTOM_REAL> x, y, z;
    // Example method to initialize some variables
    void initialize(int ns, int ng) {
        NSPEC = ns;
        NGLOB = ng;
        x.resize(NGLOB, 1.0); // Initializing with example values
        y.resize(NGLOB, 2.0);
        z.resize(NGLOB, 3.0);
    }
    // Example method to check initialization
    bool checkInitialization() const {
        return NSPEC > 0 && NGLOB > 0 && !x.empty() && !y.empty() && !z.empty();
    }
};

// Manual test function, replacing unit testing framework functionality
void testTomographyPar() {
    TomographyPar tp;
    tp.initialize(10, 100); // Example initialization

    if (tp.checkInitialization()) {
        std::cout << "TomographyPar initialization test PASSED.";
    } else {
        std::cout << "TomographyPar initialization test FAILED.";
    }

    std::cout << std::endl; // Moving the newline to a separate statement
}

int main() {
    // Run the test
    testTomographyPar();

    return 0;
}