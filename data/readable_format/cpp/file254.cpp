#include <string>
#include <cstdlib> // for std::abs

std::string CHR_NTH(int IVALUE) {
    int TENS, UNITS;
    std::string TABLE[4] = {"th", "st", "nd", "rd"};
    
    TENS = std::abs(IVALUE) % 100; // Ensure TENS is positive
    UNITS = TENS % 10;
    TENS -= UNITS;
    
    if (TENS == 10 || UNITS > 3) {
        return "th";
    } else {
        return TABLE[UNITS];
    }
}

// Example usage
#include <iostream>

int main() {
    std::cout << "1" << CHR_NTH(1) << std::endl;
    std::cout << "2" << CHR_NTH(2) << std::endl;
    std::cout << "3" << CHR_NTH(3) << std::endl;
    std::cout << "4" << CHR_NTH(4) << std::endl;
    std::cout << "11" << CHR_NTH(11) << std::endl;
    std::cout << "21" << CHR_NTH(21) << std::endl;
    std::cout << "22" << CHR_NTH(22) << std::endl;
    std::cout << "23" << CHR_NTH(23) << std::endl;
    std::cout << "24" << CHR_NTH(24) << std::endl;
    
    return 0;
}