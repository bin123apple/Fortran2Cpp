#include <iostream>
#include <vector>
#include <cassert>

// Function to remove atoms with a NUC value of 0 and adjust arrays accordingly
void removeAtoms(int& natoms, int& natms, std::vector<double>& nuc, std::vector<double>& coord, std::vector<double>& coord2, std::vector<double>& nuc2) {
    int icnt = 0;
    for (int iatm = 0; iatm < natoms; ++iatm) {
        if (nuc[iatm] != 0) {
            nuc2[icnt] = nuc[iatm];
            for (int i = 0; i < 3; ++i) {
                coord2[icnt * 3 + i] = coord[iatm * 3 + i];
            }
            ++icnt;
        }
    }
    natms = icnt;
}

// Main function with a test case
int main() {
    int natoms = 5;
    int natms;
    std::vector<double> nuc = {1, 0, 2, 0, 3};
    std::vector<double> coord = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<double> coord2(3 * natoms); // Resized based on maximum possible size
    std::vector<double> nuc2(natoms); // Resized based on maximum possible size

    removeAtoms(natoms, natms, nuc, coord, coord2, nuc2);

    // Assertions to verify the correctness of the code
    assert(natms == 3);
    assert((nuc2[0] == 1) && (nuc2[1] == 2) && (nuc2[2] == 3));
    assert((coord2[0] == 1) && (coord2[1] == 2) && (coord2[2] == 3) &&
           (coord2[3] == 7) && (coord2[4] == 8) && (coord2[5] == 9) &&
           (coord2[6] == 13) && (coord2[7] == 14) && (coord2[8] == 15));

    std::cout << "All tests passed!" << std::endl;

    // Optionally, print the results for visual confirmation
    std::cout << "Filtered NATMS: " << natms << std::endl;
    std::cout << "Filtered NUC2: ";
    for (int i = 0; i < natms; ++i) {
        std::cout << nuc2[i] << " ";
    }
    std::cout << std::endl << "Filtered COORD2: ";
    for (int i = 0; i < 3 * natms; ++i) {
        std::cout << coord2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}