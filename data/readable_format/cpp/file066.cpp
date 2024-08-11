#include <iostream>
#include <vector>
#include <string>

// Function Declaration
void checkTrueContact(int ntie, const std::vector<std::string>& tieset, 
                      const std::vector<std::vector<double>>& tietol, 
                      const std::vector<std::vector<std::vector<double>>>& elcon, 
                      int& itruecontact, int ncmat_, int ntmat_);

// Main function for testing
int main() {
    int ntie = 2;
    std::vector<std::string> tieset = {
        "A                                                                            ", 
        "C                                                                            "};
    std::vector<std::vector<double>> tietol = {{0.0, 1.0}, {0.0, 2.0}};
    std::vector<std::vector<std::vector<double>>> elcon = {{{0.0, 0.0, 3.0}, {0.0, 0.0, 4.0}}};
    int itruecontact = -1; // Initialize with an invalid value
    int ncmat_ = 1;
    int ntmat_ = 1;

    checkTrueContact(ntie, tieset, tietol, elcon, itruecontact, ncmat_, ntmat_);

    if (itruecontact == 0) {
        std::cout << "C++ Test passed." << std::endl;
    } else {
        std::cout << "C++ Test failed." << std::endl;
    }

    return 0;
}

// Function Definition
void checkTrueContact(int ntie, const std::vector<std::string>& tieset, 
                      const std::vector<std::vector<double>>& tietol, 
                      const std::vector<std::vector<std::vector<double>>>& elcon, 
                      int& itruecontact, int ncmat_, int ntmat_) {
    itruecontact = 1;

    for (int i = 0; i < ntie; ++i) {
        if (tieset[i][80] == 'C') { // Checking the last character
            int imat = static_cast<int>(tietol[i][1]);
            if (static_cast<int>(elcon[imat][0][2]) == 4) {
                itruecontact = 0;
                break;
            }
        }
    }
}