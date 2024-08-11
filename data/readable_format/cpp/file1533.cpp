#include <iostream>
#include <vector>

// Function declaration
void ADDJUT(int MXND, std::vector<double>& XN, std::vector<double>& YN,
            std::vector<std::vector<int>>& LXK, std::vector<std::vector<int>>& KXL,
            std::vector<std::vector<int>>& NXL, std::vector<std::vector<int>>& LXN,
            std::vector<double>& ANGLE, std::vector<std::vector<int>>& LNODES,
            double XNEW, double YNEW, int& NNN, int& LLL,
            int NOLD, int& NLOOP, bool& JUTTED);

// Function definition
void ADDJUT(int MXND, std::vector<double>& XN, std::vector<double>& YN,
            std::vector<std::vector<int>>& LXK, std::vector<std::vector<int>>& KXL,
            std::vector<std::vector<int>>& NXL, std::vector<std::vector<int>>& LXN,
            std::vector<double>& ANGLE, std::vector<std::vector<int>>& LNODES,
            double XNEW, double YNEW, int& NNN, int& LLL,
            int NOLD, int& NLOOP, bool& JUTTED) {
    
    // Increase NNN and set new coordinates
    NNN += 1;
    XN[NNN-1] = XNEW;  // Note: Adjusted index for 0-based arrays
    YN[NNN-1] = YNEW;

    // Increase LLL and set NXL values
    LLL += 1;
    NXL[0][LLL-1] = NNN;  // Adjusted index for 0-based arrays
    NXL[1][LLL-1] = NOLD;

    // Initialize LXN values for new node to 0
    for (int i = 0; i < 4; ++i) {
        LXN[i][NNN-1] = 0;  // Adjusted index for 0-based arrays
    }

    // Set KXL values for new link to 0
    KXL[0][LLL-1] = 0;
    KXL[1][LLL-1] = 0;

    // Set LNODES values for new node
    LNODES[0][NNN-1] = 0;
    LNODES[1][NNN-1] = NOLD;
    LNODES[2][NNN-1] = NOLD;
    LNODES[3][NNN-1] = -1;
    LNODES[4][NNN-1] = LLL;

    // Update LNODES values for old node
    LNODES[0][NOLD-1] = 0;  // Adjusted index for 0-based arrays
    LNODES[2][NOLD-1] = NNN;
    LNODES[4][NOLD-1] = LLL;

    // Increase NLOOP and set JUTTED to true
    NLOOP += 2;
    JUTTED = true;
}

// Main program for testing
int main() {
    const int MXND = 100;
    std::vector<double> XN(MXND), YN(MXND);
    std::vector<std::vector<int>> LXK(4, std::vector<int>(MXND)),
                                 KXL(2, std::vector<int>(3*MXND)),
                                 NXL(2, std::vector<int>(3*MXND)),
                                 LXN(4, std::vector<int>(MXND));
    std::vector<double> ANGLE(MXND);
    std::vector<std::vector<int>> LNODES(7, std::vector<int>(MXND));
    int NNN = 0, LLL = 0, NOLD = 1, NLOOP = 0;
    bool JUTTED = false;

    // Call ADDJUT with some test values
    ADDJUT(MXND, XN, YN, LXK, KXL, NXL, LXN, ANGLE, LNODES, 5.0, 10.0, NNN, LLL, NOLD, NLOOP, JUTTED);

    // Check results
    std::cout << "NNN = " << NNN << std::endl;
    std::cout << "XN[NNN-1] = " << XN[NNN-1] << std::endl; // Adjusted for 0-based indexing
    std::cout << "YN[NNN-1] = " << YN[NNN-1] << std::endl;
    std::cout << "JUTTED = " << std::boolalpha << JUTTED << std::endl;

    // Add more checks as necessary

    return 0;
}