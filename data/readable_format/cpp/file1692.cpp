#include <iostream>
#include <vector>
#include <cstdint>

class JACG__genmod {
public:
    static void JACG(std::vector<double>& XJAC, int32_t NP, double ALPHA, double BETA) {
        for (int i = 0; i < NP; ++i) {
            XJAC[i] = ALPHA * XJAC[i] + BETA;
        }
    }
};

int main() {
    // Set up a test case for the JACG function
    std::vector<double> XJAC = {1.0, 2.0, 3.0, 4.0, 5.0};
    int32_t NP = static_cast<int32_t>(XJAC.size());
    double ALPHA = 2.0;
    double BETA = 1.0;

    // Call the JACG function
    JACG__genmod::JACG(XJAC, NP, ALPHA, BETA);

    // Output the results to verify correctness
    std::cout << "Resulting XJAC: ";
    for (const auto& val : XJAC) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}