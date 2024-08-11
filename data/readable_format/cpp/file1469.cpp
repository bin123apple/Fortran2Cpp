#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ofstream outFile("file.txt");
    
    if (!outFile) {
        std::cerr << "Failed to open file.txt" << std::endl;
        return 1; // Return with error code
    }
    
    outFile << std::setw(21) << std::scientific << std::setprecision(7) << 3.1415927 
            << std::setw(21) << std::scientific << std::setprecision(7) << 3.1415927 << std::endl;
    
    if (outFile.fail()) {
        std::cerr << "oops" << std::endl; // Error during write operation
        outFile.close();
        return 2; // Return with error code
    } else {
        std::cout << "Write successful" << std::endl;
    }
    
    outFile.close();
    return 0; // Successful completion
}