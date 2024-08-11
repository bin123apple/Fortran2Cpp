#include <cmath>  // For the pow function

// Define a structure to represent the COMMON block
struct CommonBlock {
    int NPP;
    int K;
    int EPS;
    int CNV;
    int NM;
    int NCMPLX;
    int IK;
};

// Function to replace the Fortran subroutine
void INXCA(int I, int IR, int& IDXA, int& NA, CommonBlock& cblk) {
    NA = static_cast<int>(std::pow(2, IR));
    IDXA = I - NA + 1;
    if (I - cblk.NM >= 0) {
        NA = 0;
    }
    // No need for explicit RETURN as the function will return naturally
}

int main() {
    // Example usage
    CommonBlock cblk = {0, 0, 0, 0, 10, 0, 0};  // Initialize common block with some values
    int I = 15;
    int IR = 3;
    int IDXA;
    int NA;

    INXCA(I, IR, IDXA, NA, cblk);

    // Print the results
    std::cout << "IDXA: " << IDXA << std::endl;
    std::cout << "NA: " << NA << std::endl;

    return 0;
}