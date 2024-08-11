#include <iostream>
#include <vector>

void SLAMRG(int N1, int N2, const std::vector<float>& A, int STRD1, int STRD2, std::vector<int>& INDEX) {
    int IND1, IND2, N1SV, N2SV;

    N1SV = N1;
    N2SV = N2;
    if (STRD1 > 0) {
        IND1 = 0;
    } else {
        IND1 = N1 - 1;
    }
    if (STRD2 > 0) {
        IND2 = N1;
    } else {
        IND2 = N1 + N2 - 1;
    }

    int I = 0;

    while (N1SV > 0 && N2SV > 0) {
        if (A[IND1] <= A[IND2]) {
            INDEX[I] = IND1 + 1;
            ++I;
            IND1 += STRD1;
            --N1SV;
        } else {
            INDEX[I] = IND2 + 1;
            ++I;
            IND2 += STRD2;
            --N2SV;
        }
    }

    while (N1SV > 0) {
        INDEX[I] = IND1 + 1;
        ++I;
        IND1 += STRD1;
        --N1SV;
    }

    while (N2SV > 0) {
        INDEX[I] = IND2 + 1;
        ++I;
        IND2 += STRD2;
        --N2SV;
    }
}

int main() {
    int n1 = 5, n2 = 5;
    std::vector<float> A = {1.0, 3.0, 5.0, 7.0, 9.0, 2.0, 4.0, 6.0, 8.0, 10.0};
    std::vector<int> INDEX(n1 + n2);

    SLAMRG(n1, n2, A, 1, 1, INDEX);

    std::cout << "C++ Test Output: " << std::endl;
    for (int i = 0; i < n1 + n2; ++i) {
        std::cout << INDEX[i] << std::endl;
    }

    return 0;
}