#include <iostream>
#include <iomanip>
#include <cmath>

// Define the SROTG function
void SROTG(double &SA, double &SB, double &SC, double &SS) {
    double U, V, R;
    
    if (std::abs(SA) > std::abs(SB)) {
        U = SA + SA;
        V = SB / U;
        R = std::sqrt(0.25 + V*V) * U;
        SC = SA / R;
        SS = V * (SC + SC);
        SB = SS;
        SA = R;
    } else if (SB != 0.0) {
        U = SB + SB;
        V = SA / U;
        R = std::sqrt(0.25 + V*V) * U;
        SA = R;
        SS = SB / SA;
        SC = V * (SS + SS);
        if (SC != 0.0) {
            SB = 1.0 / SC;
        } else {
            SB = 1.0;
        }
    } else {
        SC = 1.0;
        SS = 0.0;
    }
}

// Test function for SROTG
void testSROTG(double sa, double sb) {
    double sc, ss;
    SROTG(sa, sb, sc, ss);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Test - SA: " << sa << " SB: " << sb << " SC: " << sc << " SS: " << ss << std::endl;
}

int main() {
    // Test case 1
    testSROTG(3.0, 4.0);

    // Test case 2
    testSROTG(5.0, 0.0);

    return 0;
}