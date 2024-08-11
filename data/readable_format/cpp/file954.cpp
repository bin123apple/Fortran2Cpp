#include <iostream>
#include <vector>

// Declaration of the DLAMRG function
void DLAMRG(int N1, int N2, const std::vector<double>& A, int DTRD1, int DTRD2, std::vector<int>& INDEX) {
    int IND1, IND2, N1SV, N2SV;
    N1SV = N1;
    N2SV = N2;
    if (DTRD1 > 0) {
        IND1 = 0; // Adjusted for 0-based indexing
    } else {
        IND1 = N1 - 1; // Adjusted for 0-based indexing
    }
    if (DTRD2 > 0) {
        IND2 = N1; // Correct as-is for 0-based indexing because it was 1 + N1 in Fortran
    } else {
        IND2 = N1 + N2 - 1; // Adjusted for 0-based indexing
    }
    int i = 0; // Adjusted for 0-based indexing
    while (N1SV > 0 && N2SV > 0) {
        if (A[IND1] <= A[IND2]) {
            INDEX[i] = IND1 + 1; // Adjust back to 1-based indexing for compatibility
            i += 1;
            IND1 += DTRD1;
            N1SV -= 1;
        } else {
            INDEX[i] = IND2 + 1; // Adjust back to 1-based indexing for compatibility
            i += 1;
            IND2 += DTRD2;
            N2SV -= 1;
        }
    }
    if (N1SV == 0) {
        for (int j = 0; j < N2SV; ++j) {
            INDEX[i] = IND2 + 1; // Adjust back to 1-based indexing for compatibility
            i += 1;
            IND2 += DTRD2;
        }
    } else {
        for (int j = 0; j < N1SV; ++j) {
            INDEX[i] = IND1 + 1; // Adjust back to 1-based indexing for compatibility
            i += 1;
            IND1 += DTRD1;
        }
    }
}

// Utility function to print the INDEX vector
void printIndex(const std::vector<int>& index) {
    for (auto i : index) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to test the DLAMRG
void testDLAMRG() {
    std::vector<double> A;
    std::vector<int> INDEX;
    int N1, N2, DTRD1, DTRD2;

    // Test 1
    N1 = 3; N2 = 2; DTRD1 = 1; DTRD2 = 1;
    A = {1.0, 3.0, 5.0, 2.0, 4.0};
    INDEX.resize(N1 + N2);
    DLAMRG(N1, N2, A, DTRD1, DTRD2, INDEX);
    std::cout << "Test 1: ";
    printIndex(INDEX);

    // Test 2
    N1 = 2; N2 = 3; DTRD1 = -1; DTRD2 = -1;
    A = {4.0, 2.0, 5.0, 3.0, 1.0};
    INDEX.resize(N1 + N2);
    DLAMRG(N1, N2, A, DTRD1, DTRD2, INDEX);
    std::cout << "Test 2: ";
    printIndex(INDEX);
}

int main() {
    testDLAMRG();
    return 0;
}