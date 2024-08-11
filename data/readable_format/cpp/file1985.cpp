#include <iostream>
#include <limits>
#include <cstdint>

// Namespace to encapsulate the configuration similar to a Fortran module
namespace config {
    // Mapping the precision types directly in the namespace
    using sp = float;        // Single precision
    using dp = double;       // Double precision
    using ep = long double;  // Extended precision
    using qp = long double;  // Quadruple precision, assuming long double for demonstration
    
    using wp = dp; // Using double precision as wp
    
    // Function to display the precision type size
    void disp_wp() {
        std::cout << "Precision size of wp (in bytes): " << sizeof(wp) << std::endl;
    }
}

int main() {
    // Testing the disp_wp function from the config namespace
    config::disp_wp();
    return 0;
}