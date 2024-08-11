#include <iostream>
#include <vector>

// Definition of the FSCAN function
void FSCAN(int& OPCODE, int& NLC, int& NLI, int& NLD, std::vector<char>& NLCPRM,
           std::vector<int>& NLIPRM, std::vector<double>& NLDPRM, std::vector<double>& WORLD,
           std::vector<double>& PIXEL, int& CONTRL, std::vector<double>& CONTXT, int& IERR) {
    // Ensure vectors are correctly sized
    // Assuming vectors WORLD, PIXEL, CONTXT, NLCPRM, NLIPRM, NLDPRM are properly sized outside this function

    IERR = 0;

    if (OPCODE > 0) {
        PIXEL[0] = NLDPRM[0] + (WORLD[0] - NLDPRM[2]) / NLDPRM[4];
        double S = NLDPRM[3] + PIXEL[0] * NLDPRM[6];
        PIXEL[1] = NLDPRM[1] + (WORLD[1] - S) / NLDPRM[5];

        CONTRL = 0;
    } else if (OPCODE == 0) {
        if (NLC < 1 || NLI < 1 || NLD < 7) IERR = 1;
        if (NLDPRM[4] == 0.0) IERR = 1; // Check against 0.0 for double
        if (NLDPRM[5] == 0.0) IERR = 1; // Check against 0.0 for double
        if (NLDPRM[6] == 0.0) IERR = 1; // Check against 0.0 for double

        CONTRL = 0;
    } else if (OPCODE == -1) {
        WORLD[0] = NLDPRM[2] + NLDPRM[4] * (PIXEL[0] - NLDPRM[0]);
        WORLD[1] = NLDPRM[3] + NLDPRM[5] * (PIXEL[1] - NLDPRM[1]) + PIXEL[0] * NLDPRM[6];
    } else {
        IERR = 1;
    }
}

// Function to run tests
void runTest(int testId, int OPCODE, int NLC, int NLI, int NLD, std::vector<char>& NLCPRM,
             std::vector<int>& NLIPRM, std::vector<double>& NLDPRM, std::vector<double>& WORLD,
             std::vector<double>& PIXEL, int& CONTRL, std::vector<double>& CONTXT) {
    int IERR;
    FSCAN(OPCODE, NLC, NLI, NLD, NLCPRM, NLIPRM, NLDPRM, WORLD, PIXEL, CONTRL, CONTXT, IERR);
    std::cout << "Test " << testId << ": IERR = " << IERR << std::endl;
    if (OPCODE == 1 || OPCODE == -1) {
        std::cout << "PIXEL = [" << PIXEL[0] << ", " << PIXEL[1] << "]" << std::endl;
    }
    if (OPCODE == -1) {
        std::cout << "WORLD = [" << WORLD[0] << ", " << WORLD[1] << "]" << std::endl;
    }
}

int main() {
    // Example test cases
    int OPCODE, NLC = 0, NLI = 1, NLD = 7, CONTRL;
    std::vector<char> NLCPRM(1);
    std::vector<int> NLIPRM(1);
    std::vector<double> NLDPRM = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::vector<double> WORLD = {10.0, 20.0};
    std::vector<double> PIXEL(2), CONTXT(20);

    // Test 1
    OPCODE = 1;
    runTest(1, OPCODE, NLC, NLI, NLD, NLCPRM, NLIPRM, NLDPRM, WORLD, PIXEL, CONTRL, CONTXT);

    // Additional tests can be added as necessary

    return 0;
}