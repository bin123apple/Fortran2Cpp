#include <iostream>

namespace PRSIZES {
    // Adjusted based on typical use, since SELECTED_INT_KIND and SELECTED_REAL_KIND are not direct C++ equivalents
    const int ISIZE = 4; // Assuming 4 bytes for int, adjust as needed
    const int DPSIZE = 8; // Assuming 8 bytes for double, adjust as needed
    const int PE = 30;
    const int MAXRECID = 200;
    const int PC = 30;
    const int PCT = 30;
    const int PIR = 700;
    const int PD = 50;
    const int PAL = 50;
    const int MAXFCN = 1000000;
    const int MAXIC = 90;
    const int PG = 80;
    const int PES = 30;
}

int main() {
    using namespace PRSIZES;
    std::cout << "ISIZE: " << ISIZE << std::endl;
    std::cout << "DPSIZE: " << DPSIZE << std::endl;
    std::cout << "PE: " << PE << std::endl;
    std::cout << "MAXRECID: " << MAXRECID << std::endl;
    std::cout << "PC: " << PC << std::endl;
    std::cout << "PCT: " << PCT << std::endl;
    std::cout << "PIR: " << PIR << std::endl;
    std::cout << "PD: " << PD << std::endl;
    std::cout << "PAL: " << PAL << std::endl;
    std::cout << "MAXFCN: " << MAXFCN << std::endl;
    std::cout << "MAXIC: " << MAXIC << std::endl;
    std::cout << "PG: " << PG << std::endl;
    std::cout << "PES: " << PES << std::endl;

    return 0;
}