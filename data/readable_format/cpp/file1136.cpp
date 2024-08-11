#include <iostream>

// Global variables to mimic the Fortran common block
double rhol_com, cl_com, rhor_com, cr_com;

// Function definition
void interface_setprob(double rhol, double cl, double rhor, double cr) {
    rhol_com = rhol;
    cl_com = cl;
    rhor_com = rhor;
    cr_com = cr;
}

int main() {
    // Example usage
    double rhol = 1.0, cl = 2.0, rhor = 3.0, cr = 4.0;
    interface_setprob(rhol, cl, rhor, cr);
    
    // Output the values to verify they are set correctly
    std::cout << "Testing interface_setprob..." << std::endl;
    std::cout << "rhol_com: " << rhol_com << std::endl;
    std::cout << "cl_com: " << cl_com << std::endl;
    std::cout << "rhor_com: " << rhor_com << std::endl;
    std::cout << "cr_com: " << cr_com << std::endl;

    // Checking the values
    bool success = true;
    if (rhol_com != rhol) {
        std::cout << "Error: rhol_com is incorrect." << std::endl;
        success = false;
    }
    if (cl_com != cl) {
        std::cout << "Error: cl_com is incorrect." << std::endl;
        success = false;
    }
    if (rhor_com != rhor) {
        std::cout << "Error: rhor_com is incorrect." << std::endl;
        success = false;
    }
    if (cr_com != cr) {
        std::cout << "Error: cr_com is incorrect." << std::endl;
        success = false;
    }

    if (success) {
        std::cout << "All tests passed successfully!" << std::endl;
    }

    return 0;
}