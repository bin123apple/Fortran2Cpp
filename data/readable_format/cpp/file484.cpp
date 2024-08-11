#include <iostream>

// Equivalent of Fortran COMMON block using a struct in C++
struct EH0001 {
    int mesflg; // Assuming mesflg is used elsewhere in your Fortran code
    int lunit;
};

// Global instance of the struct
EH0001 eh0001;

// C++ version of the Fortran subroutine
void xsetun(int lun) {
    // Directly access the global struct's member
    if (lun > 0) eh0001.lunit = lun;
}

int main() {
    // Example usage
    xsetun(5);
    std::cout << "lunit set to: " << eh0001.lunit << std::endl;
    
    return 0;
}