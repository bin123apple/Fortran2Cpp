#include <iostream>
#include <cmath> // For std::abs()
#include <cstdlib> // For std::exit()

double CSEDTAUB(double DENBULK, double TDUM, double V1, double V2, double V3, int IOPT) {
    double BULKDEN;
    if(IOPT == 1 || IOPT == 2) {
        BULKDEN = 0.001 * DENBULK;
        if(BULKDEN <= 1.013) {
            return 0.0;
        } else {
            return 0.001 * (9.808 * BULKDEN - 9.934);
        }
    } else {
        std::cerr << "CSEDTAUB: BAD SEDIMENT CRITICAL STRESS OPTION! STOPPING!" << std::endl;
        std::exit(1); // Exit the program with an error state
    }
}

void testCSEDTAUB(double DENBULK, double TDUM, double V1, double V2, double V3, int IOPT, const std::string& testCase) {
    double result = CSEDTAUB(DENBULK, TDUM, V1, V2, V3, IOPT);
    std::cout << testCase << ": Result: " << result << std::endl;
}

int main() {
    // Test case 1
    testCSEDTAUB(1000.0, 0.0, 0.0, 0.0, 0.0, 1, "Test case 1 (IOPT=1)");

    // Test case 2
    testCSEDTAUB(950.0, 0.0, 0.0, 0.0, 0.0, 2, "Test case 2 (IOPT=2)");

    return 0;
}