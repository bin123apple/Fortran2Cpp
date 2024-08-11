#include <iostream>
#include <vector>
#include <string>

// Constants
const int NTYPES = 1;
const int BADTYP = 7554;
const std::string R3TYPE[NTYPES] = {"BUCK_PC"};

void R3SGRT(int GRPID, const std::string& TYPNAM, int& nresp, std::vector<int>& grdtyp, int& ERROR) {
    // Initialization
    ERROR = 0;
    nresp = 0; // Assuming we need to ensure nresp has a defined value even if not set below

    // Loop over each type
    for (int ITYPE = 0; ITYPE < NTYPES; ++ITYPE) {
        if (TYPNAM == R3TYPE[ITYPE]) {
            nresp = 1;
            if (grdtyp.size() >= 1) { // Ensure grdtyp has enough space
                grdtyp[0] = 3;
            } else {
                // Handle error or resize vector
                grdtyp.resize(1, 3); // Resizing and setting the value to 3 if not enough space
            }
            return; // Exit the function
        }
    }
    ERROR = BADTYP;
}

// Main function to demonstrate testing
int main() {
    // Example of calling the function
    int GRPID = 1;
    std::string TYPNAM;
    int nresp;
    std::vector<int> grdtyp(1); // Assuming this vector is pre-sized for this example
    int ERROR;

    // Test Case 1: Matching TYPNAM
    TYPNAM = "BUCK_PC";
    R3SGRT(GRPID, TYPNAM, nresp, grdtyp, ERROR);
    std::cout << "Test 1 (Matching) - ERROR: " << ERROR << ", nresp: " << nresp << ", grdtyp[0]: " << grdtyp[0] << std::endl;

    // Test Case 2: Non-matching TYPNAM
    TYPNAM = "INVALID";
    R3SGRT(GRPID, TYPNAM, nresp, grdtyp, ERROR);
    std::cout << "Test 2 (Non-Matching) - ERROR: " << ERROR << std::endl;

    return 0;
}