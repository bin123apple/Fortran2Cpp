#include <iostream>
#include <vector>

int main() {
    // Equivalent to Fortran's integer,save :: itmp(3)[*]
    static std::vector<int> itmp(3); // Static to mimic 'save', initialized with size 3
    
    itmp[0] = 3; // Arrays in C++ are 0-indexed

    // Check the size and value of the first element
    if (itmp.size() == 3 && itmp[0] == 3) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NG: itmp(3)[*] is illegally allocated or not allocated." << std::endl;
    }

    return 0;
}