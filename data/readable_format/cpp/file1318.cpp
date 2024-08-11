#include <iostream>
#include <vector>

// Declare and define the ZMESS function directly in this file
void ZMESS(int& NUMESS, int& LESSEL, int& LESSDL, 
           std::vector<int>& IDESS, std::vector<int>& NEESS, std::vector<int>& NEDSS, 
           std::vector<int>& IXEESS, std::vector<int>& IXEDSS, std::vector<int>& LTEESS, 
           std::vector<int>& LTSSS, std::vector<int>& LTSNC, std::vector<float>& FAC, 
           bool USESDF) {
    if (NUMESS <= 0) return;

    int JESS = 0;
    int JNE = 0;
    int JDF = 0;
    int IDFE = 0;
    for (int IESS = 0; IESS < NUMESS; ++IESS) {
        int JNELST = JNE;
        int JDFLST = JDF;
        int nd1 = IXEDSS[IESS];
        int IDFB = nd1;
        for (int N = 0; N < NEESS[IESS]; ++N) {
            int NE = N + IXEESS[IESS];
            int ICNT = LTSNC[NE];
            IDFE = IDFB + ICNT - 1;
            if (LTEESS[NE] > 0) {
                LTEESS[JNE] = LTEESS[NE];
                LTSSS[JNE]  = LTSSS[NE];
                LTSNC[JNE]  = LTSNC[NE];
                ++JNE;
                if (USESDF) {
                    for (int nd = IDFB; nd <= IDFE; ++nd) {
                        FAC[JDF] = FAC[nd - 1];  // Adjusting index for zero-based
                        ++JDF;
                    }
                }
            }
            IDFB = IDFE + 1;
        }
        int N = JNE - JNELST;
        if (N > 0) {
            IDESS[JESS] = IDESS[IESS];
            NEESS[JESS] = N;
            IXEESS[JESS] = JNELST + 1;
            ++JESS;
            if (USESDF) {
                NEDSS[JESS - 1] = JDF - JDFLST;  // -1 since JESS was incremented
                IXEDSS[JESS - 1] = JDFLST + 1;
            }
        }
    }
    NUMESS = JESS;
    LESSEL = JNE;
    if (USESDF) {
        if (IDFE != LESSDL - 1) {  // Adjusted for zero-based indexing
            std::cerr << "ZMESS: Internal error" << std::endl;
            std::exit(1);
        }
        LESSDL = JDF;
    }
}

// Main function to execute a simple test
int main() {
    int NUMESS = 2;
    int LESSEL = 0;
    int LESSDL = 0;
    std::vector<int> IDESS = {1, 2, 0, 0, 0};
    std::vector<int> NEESS = {2, 3, 0, 0, 0};
    std::vector<int> NEDSS = {0, 0, 0, 0, 0};
    std::vector<int> IXEESS = {1, 3, 0, 0, 0};
    std::vector<int> IXEDSS = {1, 4, 0, 0, 0};
    std::vector<int> LTEESS = {1, 2, 3, 0, 0};
    std::vector<int> LTSSS = {4, 5, 6, 0, 0};
    std::vector<int> LTSNC = {7, 8, 9, 0, 0};
    std::vector<float> FAC = {1.0f, 2.0f, 3.0f, 0.0f, 0.0f};
    bool USESDF = true;

    ZMESS(NUMESS, LESSEL, LESSDL, IDESS, NEESS, NEDSS, IXEESS, IXEDSS, LTEESS, LTSSS, LTSNC, FAC, USESDF);

    // Output and check the results
    std::cout << "NUMESS: " << NUMESS << std::endl;
    std::cout << "LESSEL: " << LESSEL << std::endl;
    std::cout << "LESSDL: " << LESSDL << std::endl;
    // Add more output as needed to verify the correctness

    return 0;
}