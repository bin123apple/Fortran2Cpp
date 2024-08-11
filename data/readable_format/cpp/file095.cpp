#include <iostream>

// Define the namespace with constants directly in this file
namespace defMSGProject {
    constexpr double PI = 3.14159265359;

    constexpr double SAT_HEIGHT = 42164.0;
    constexpr double R_EQ = 6378.169;
    constexpr double R_POL = 6356.5838;
    constexpr double SUB_LON = 0.0;

    constexpr int CFAC = -781648343;
    constexpr int LFAC = -781648343;
    constexpr int COFF = 1856;
    constexpr int LOFF = 1856;
}

int main() {
    // Example usage of the constants
    std::cout << "PI = " << defMSGProject::PI << std::endl;
    std::cout << "SAT_HEIGHT = " << defMSGProject::SAT_HEIGHT << std::endl;
    std::cout << "R_EQ = " << defMSGProject::R_EQ << std::endl;
    std::cout << "R_POL = " << defMSGProject::R_POL << std::endl;
    std::cout << "SUB_LON = " << defMSGProject::SUB_LON << std::endl;
    std::cout << "CFAC = " << defMSGProject::CFAC << std::endl;
    std::cout << "LFAC = " << defMSGProject::LFAC << std::endl;
    std::cout << "COFF = " << defMSGProject::COFF << std::endl;
    std::cout << "LOFF = " << defMSGProject::LOFF << std::endl;

    return 0;
}