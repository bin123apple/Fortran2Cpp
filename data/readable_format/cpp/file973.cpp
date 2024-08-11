#include <iostream>
#include <string>

// Mock implementation of the NetCDF functionality
namespace NetCDF {

bool openFile(const std::string& filename) {
    // Simplified example: Assume success if filename is "example.nc"
    return filename == "example.nc";
}

} // namespace NetCDF

// Basic testing function
void testOpenFile() {
    std::cout << "Testing openFile with 'example.nc'" << std::endl;
    if (NetCDF::openFile("example.nc")) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    std::cout << "Testing openFile with 'nonexistent.nc'" << std::endl;
    if (!NetCDF::openFile("nonexistent.nc")) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    testOpenFile();
    return 0;
}