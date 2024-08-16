#include <array>

extern std::array<std::array<double, 13>, 5> ce; // Assuming this is defined elsewhere

void exact_solution(double xi, double eta, double zeta, std::array<double, 5>& dtemp) {
    for (int m = 0; m < 5; ++m) {
        dtemp[m] = ce[m][0] + 
                    xi * (ce[m][1] + xi * (ce[m][5] + xi * (ce[m][8] + xi * ce[m][11]))) + 
                    eta * (ce[m][2] + eta * (ce[m][6] + eta * (ce[m][9] + eta * ce[m][12]))) + 
                    zeta * (ce[m][3] + zeta * (ce[m][7] + zeta * (ce[m][10] + zeta * ce[m][13])));
    }
}
