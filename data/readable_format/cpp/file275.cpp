#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ofstream out("cpp_output.txt");

    // Since Fortran's T8 positions the integer right before the 8th column, 
    // and the direct translation might not perfectly match due to different tab behavior,
    // we adjust by manually calculating spaces as needed.
    out << std::setw(4) << 1234 << std::setw(3) << " " << 8 << std::endl; // Correction for T8
    out << std::setw(4) << 1234 << std::setw(3) << " " << 8 << std::endl; // For TR3, assuming the same adjustment
    out << std::setw(4) << 1234 << std::string(3, ' ') << 8 << std::endl; // 5X followed by TL2, adjusted

    out.close();
    return 0;
}