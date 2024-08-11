#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<int> j(5); 
    std::string x = "ab";
    std::string y = "cd";
    std::vector<std::string> z(2);
    
    // Logic similar to the Fortran code
    z[0] = y.substr(0, y.find_last_not_of(" ") + 1) + x.substr(0, x.find_last_not_of(" ") + 1);
    z[1] = x.substr(0, x.find_last_not_of(" ") + 1) + y.substr(0, y.find_last_not_of(" ") + 1);
    
    // Comparison similar to the Fortran if-statement checks
    for (size_t i = 0; i < z[0].size(); ++i) {
        j[i] = static_cast<int>(z[0][i]);
    }
    for (size_t i = z[0].size(); i < 5; ++i) {
        j[i] = 32; // ASCII for space
    }
    // Add checks similar to Fortran's STOP statements if needed
    
    return 0;
}