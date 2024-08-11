#include <iostream>

// Namespace to mimic the Fortran module's encapsulation
namespace CRM_SETUP_INDEXING__genmod {

// Function prototype
void CRM_SETUP_INDEXING(int NSPEC, int NGLOB_THEOR, int NPOINTOT);

} // namespace CRM_SETUP_INDEXING__genmod

// Function implementation
void CRM_SETUP_INDEXING__genmod::CRM_SETUP_INDEXING(int NSPEC, int NGLOB_THEOR, int NPOINTOT) {
    std::cout << "NSPEC: " << NSPEC << " NGLOB_THEOR: " << NGLOB_THEOR << " NPOINTOT: " << NPOINTOT << std::endl;
}

// Simple testing function
void test_CRM_SETUP_INDEXING() {
    std::cout << "Testing CRM_SETUP_INDEXING..." << std::endl;
    // Call the function with test values
    CRM_SETUP_INDEXING__genmod::CRM_SETUP_INDEXING(10, 20, 30);
    // Manual verification needed, or you could implement checks if you know the expected output
    std::cout << "Test completed. Verify the output manually." << std::endl;
}

// Main function to run tests
int main() {
    test_CRM_SETUP_INDEXING();
    return 0;
}