#include <iostream>
#include <vector>

// Function prototype
void DLAMRG(int N1, int N2, const std::vector<double>& A, int DTRD1, int DTRD2, std::vector<int>& INDEX);

void DLAMRG(int N1, int N2, const std::vector<double>& A, int DTRD1, int DTRD2, std::vector<int>& INDEX) {
    int IND1, IND2, N1SV, N2SV, I;

    N1SV = N1;
    N2SV = N2;
    if (DTRD1 > 0) {
        IND1 = 0; // Adjusted for 0-based indexing
    } else {
        IND1 = N1 - 1; // Adjusted for 0-based indexing
    }
    if (DTRD2 > 0) {
        IND2 = N1; // Already correct for 0-based indexing since it's 1 + N1 in Fortran
    } else {
        IND2 = N1 + N2 - 1; // Adjusted for 0-based indexing
    }
    I = 0; // Adjusted for 0-based indexing
    while (N1SV > 0 && N2SV > 0) {
        if (A[IND1] <= A[IND2]) {
            INDEX[I] = IND1 + 1; // +1 to convert back to 1-based indexing for compatibility
            ++I;
            IND1 += DTRD1;
            --N1SV;
        } else {
            INDEX[I] = IND2 + 1; // +1 to convert back to 1-based indexing for compatibility
            ++I;
            IND2 += DTRD2;
            --N2SV;
        }
    }
    if (N1SV == 0) {
        for (int j = 0; j < N2SV; ++j) {
            INDEX[I] = IND2 + 1; // +1 to convert back to 1-based indexing
            ++I;
            IND2 += DTRD2;
        }
    } else {
        for (int j = 0; j < N1SV; ++j) {
            INDEX[I] = IND1 + 1; // +1 to convert back to 1-based indexing
            ++I;
            IND1 += DTRD1;
        }
    }
}

void testDLAMRG() {
    int N1 = 5, N2 = 5;
    std::vector<double> A = {1.0, 6.0, 3.0, 7.0, 5.0, 2.0, 8.0, 4.0, 9.0, 10.0};
    std::vector<int> INDEX(N1 + N2);
    DLAMRG(N1, N2, A, 1, 1, INDEX);

    std::cout << "INDEX:" << std::endl;
    for (int i = 0; i < N1 + N2; ++i) {
        std::cout << INDEX[i] << std::endl;
    }
}

int main() {
    testDLAMRG();
    return 0;
}