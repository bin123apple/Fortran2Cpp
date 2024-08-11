#include <iostream>
#include <iomanip>

const int ndof = 2, nen = 3, numfn = 2;
const int izero = 0;

// Function definition of adfldp
void adfldp(double dl[ndof][nen], int lmf[nen], double dfault[ndof][numfn]) {
    for (int i = 0; i < nen; ++i) {
        if (lmf[i] != izero) {
            int l = lmf[i] - 1; // Adjusting for 0-based indexing in C++
            for (int j = 0; j < ndof; ++j) {
                dl[j][i] += dfault[j][l];
            }
        }
    }
}

int main() {
    double dl[ndof][nen];
    int lmf[nen];
    double dfault[ndof][numfn] = {{1.0, 3.0}, {2.0, 4.0}};

    // Test 1: All elements in lmf are different from izero
    std::cout << "Test 1" << std::endl;
    std::fill(&dl[0][0], &dl[0][0] + ndof*nen, 0);
    int lmf1[nen] = {1, 2, 1};
    adfldp(dl, lmf1, dfault);
    for(auto& row : dl) {
        for(double elem : row) std::cout << elem << " ";
        std::cout << std::endl;
    }

    // Test 2: All elements in lmf are equal to izero
    std::cout << "Test 2" << std::endl;
    std::fill(&dl[0][0], &dl[0][0] + ndof*nen, 0);
    int lmf2[nen] = {izero, izero, izero};
    adfldp(dl, lmf2, dfault);
    for(auto& row : dl) {
        for(double elem : row) std::cout << elem << " ";
        std::cout << std::endl;
    }

    // Test 3: Mixed case
    std::cout << "Test 3" << std::endl;
    std::fill(&dl[0][0], &dl[0][0] + ndof*nen, 0);
    int lmf3[nen] = {1, izero, 2};
    adfldp(dl, lmf3, dfault);
    for(auto& row : dl) {
        for(double elem : row) std::cout << elem << " ";
        std::cout << std::endl;
    }

    return 0;
}