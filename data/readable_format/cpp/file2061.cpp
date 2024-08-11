#include <iostream>
#include <vector>

// Namespace is used to encapsulate the function similarly to the module in Fortran
namespace KVECANS__genmod {

void KVECANS(int NCPX, int P, const std::vector<double>& U_KNOT, double UK, std::vector<double>& UB) {
    for (int i = 0; i < NCPX + P + 1 + P; ++i) {
        UB[i] = (i + 1) * UK; // Adjust to mimic 1-based indexing logic as in Fortran
    }
}

} // namespace KVECANS__genmod

int main() {
    const int NCPX = 10;
    const int P = 3;
    const double UK = 2.5;
    std::vector<double> U_KNOT(NCPX + P + 1, 0.0); // Initialize U_KNOT with zeros for simplicity
    std::vector<double> UB(NCPX + P + 1 + P);

    // Initialize U_KNOT with example values
    for (int i = 0; i < NCPX + P + 1; ++i) {
        U_KNOT[i] = (i + 1) * 1.0; // Fill with dummy values for demonstration
    }

    // Call the function
    KVECANS__genmod::KVECANS(NCPX, P, U_KNOT, UK, UB);

    // Output the results
    std::cout << "UB:" << std::endl;
    for (size_t i = 0; i < UB.size(); ++i) {
        std::cout << UB[i] << std::endl;
        // For actual unit testing, here you would check UB[i] against expected values
    }

    return 0;
}