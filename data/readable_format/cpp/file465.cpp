#include <iostream>
#include <vector>
#include <cassert>

// Assuming dimensions and interactions constants
const int ME2c_max = 100;
const int nsh_max = 10;

// Function declaration and definition in the same file
void recoverC(int n1, int n2, const std::vector<float>& hlist, const std::vector<float>& dhlist,
              std::vector<std::vector<float>>& hbox, std::vector<std::vector<float>>& dhbox) {
    int index;
    int indexcoulomb;
    int ii;
    int kk;
    
    ii = 0;  // Adjusted for 0-based indexing
    kk = -1; // Adjusted for 0-based indexing and incremented before use

    indexcoulomb = n1 * n2;
    for (index = 0; index < indexcoulomb; ++index) { // Adjust loop for 0-based indexing
        kk++;
        hbox[ii][kk] = hlist[index];
        dhbox[ii][kk] = dhlist[index];
        if ((index + 1) % n2 == 0) { // Adjust condition for 0-based indexing
            ii++;
            kk -= n2;
        }
    }
}

int main() {
    int n1 = 2;
    int n2 = 3;
    std::vector<float> hlist = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<float> dhlist = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
    std::vector<std::vector<float>> hbox(n1, std::vector<float>(n2));
    std::vector<std::vector<float>> dhbox(n1, std::vector<float>(n2));

    // Call the function
    recoverC(n1, n2, hlist, dhlist, hbox, dhbox);

    // Simple test to verify output
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            std::cout << "hbox[" << i << "][" << j << "] = " << hbox[i][j] << ", ";
            std::cout << "dhbox[" << i << "][" << j << "] = " << dhbox[i][j] << std::endl;
            // Add your verification logic here, for example, using assert
        }
    }

    return 0;
}