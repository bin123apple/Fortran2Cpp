#include <iostream>

int main() {
    // Equivalent to write(*,10) in Fortran with the format(1H1), 
    // though the 1H1 format technically means starting with a single character defined directly after H, which is '1' here.
    // But since it doesn't actually print anything meaningful, we can simplify the translation by skipping it.
    
    // Equivalent to write(*,20) with format(6H     6), which means to print "      6"
    std::cout << "      6" << std::endl;
    
    // Equivalent to write(*,'(16H''apostrophe'' fun)') in Fortran,
    // which is meant to print the string "'apostrophe' fun"
    std::cout << "'apostrophe' fun" << std::endl;

    return 0;
}