// CSINTRSC.cpp
#include <iostream>
#include <cmath>

void CSINTRSC(const double P1[3], const double P2[3], const double CN[3], double P[3], int &IER) {
    double D1, D2, PP[3], PPN, T;
    
    D1 = CN[0] * P1[0] + CN[1] * P1[1] + CN[2] * P1[2];
    D2 = CN[0] * P2[0] + CN[1] * P2[1] + CN[2] * P2[2];
    
    if (D1 == D2) {
        IER = 1;
        P[0] = 0.0;
        P[1] = 0.0;
        P[2] = 0.0;
        return;
    }

    T = D1 / (D1 - D2);
    PPN = 0.0;
    for (int i = 0; i < 3; ++i) {
        PP[i] = P1[i] + T * (P2[i] - P1[i]);
        PPN += PP[i] * PP[i];
    }
    
    if (PPN == 0.0) {
        IER = 2;
        return;
    }
    
    PPN = sqrt(PPN);
    for (int i = 0; i < 3; ++i) {
        P[i] = PP[i] / PPN;
    }
    
    IER = 0;
}

int main() {
    double P1[3] = {1.0, 0.0, 0.0};
    double P2[3] = {0.0, 1.0, 0.0};
    double CN[3] = {0.0, 0.0, 1.0};
    double P[3];
    int IER;

    CSINTRSC(P1, P2, CN, P, IER);
    
    std::cout << "IER: " << IER << std::endl << "P: ";
    for (int i = 0; i < 3; i++) {
        std::cout << P[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

// Compile with: g++ -o test_CSINTRSC CSINTRSC.cpp
// Run with: ./test_CSINTRSC