#include <iostream>

// Assuming the mapping of INTEGER(KIND=4) to int
// and REAL(KIND=8) to double

class CONVCHECK__genmod {
public:
    static void CONVCHECK(int INC, double& ABSRES, double& ABSDISP) {
        // Example logic for testing - replace this with the actual functionality
        ABSRES = INC * 2.0;
        ABSDISP = INC + 10.0;
    }
};

int main() {
    int INC = 5; // Example input
    double ABSRES, ABSDISP;

    CONVCHECK__genmod::CONVCHECK(INC, ABSRES, ABSDISP);

    std::cout << "INC = " << INC << " -> ABSRES = " << ABSRES << ", ABSDISP = " << ABSDISP << std::endl;

    return 0;
}