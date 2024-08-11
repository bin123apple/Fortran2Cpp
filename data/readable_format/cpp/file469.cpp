#include <iostream>
#include <vector>
#include <cmath> // For fabs

// Assuming these are the necessary global variables
int Lsite = 5; // Example value
double t0 = 1.0; // Example value

// Declaration of global matrices
std::vector<std::vector<double>> Hmat_kin;
// Add other matrices and vectors as needed

void PBME_allocation() {
    // Size matrices appropriately
    Hmat_kin.resize(Lsite, std::vector<double>(Lsite, 0.0));
    // Initialize other matrices and vectors similarly
    
    // Initialize Hmat_kin
    for (int i = 0; i < Lsite; ++i) {
        int j = i + 1;
        if (j >= Lsite) j = 0; // Adjust for 0-based indexing and wrap around
        Hmat_kin[i][j] = -t0;
        
        j = i - 1;
        if (j < 0) j = Lsite - 1; // Adjust for 0-based indexing and wrap around
        Hmat_kin[i][j] = -t0;
    }
    // Perform other initializations as needed
}

bool test_Hmat_kin_initialization() {
    PBME_allocation(); // Initializing the matrices and vectors
    
    // Test if Hmat_kin is initialized correctly
    const double tolerance = 1e-7;
    bool test_passed = true;
    for (size_t i = 0; i < Hmat_kin.size(); ++i) {
        for (size_t j = 0; j < Hmat_kin[i].size(); ++j) {
            if ((i != j) && (std::fabs(Hmat_kin[i][j] + t0) > tolerance)) {
                test_passed = false;
                break;
            }
        }
        if (!test_passed) break;
    }
    return test_passed;
}

int main() {
    if (test_Hmat_kin_initialization()) {
        std::cout << "Hmat_kin allocation and initialization test passed." << std::endl;
    } else {
        std::cout << "Hmat_kin allocation and initialization test failed." << std::endl;
    }
    
    // Add more tests as needed for other matrices and vectors
    
    return 0;
}