#include <iostream>

using Real = double; // Matching Fortran REAL(KIND=8)

class SHAPEFUNCEAS__genmod {
public:
    static void SHAPEFUNCEAS(Real& DETJ, const Real& XII, const Real& ETAI, const Real& ZETAI) {
        DETJ = XII * ZETAI - ETAI * 2.0;  // Simplified operation for demonstration
    }
};

int main() {
    Real DETJ, XII = 3.0, ETAI = 4.0, ZETAI = 5.0;

    SHAPEFUNCEAS__genmod::SHAPEFUNCEAS(DETJ, XII, ETAI, ZETAI);

    std::cout << "C++ DETJ: " << DETJ << std::endl;

    return 0;
}