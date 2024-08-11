#include <iostream>
#include <cassert>

void CNTNZU(int N, int* IA, int* JA, int& NZSUT) {
    int NUM = 0;
    for (int II = 1; II <= N; ++II) {
        int JMIN = IA[II - 1];
        int JMAX = IA[II] - 1;
        if (JMIN > JMAX) continue;
        for (int J = JMIN; J <= JMAX; ++J) {
            int JJ = JA[J - 1];
            if (JJ == II) continue;
            int KMIN = IA[JJ - 1];
            int KMAX = IA[JJ] - 1;
            bool found = false;
            for (int K = KMIN; K <= KMAX; ++K) {
                if (JA[K - 1] == II) {
                    found = true;
                    break;
                }
            }
            if (!found) NUM++;
        }
    }
    NZSUT = NUM;
}

void testCNTNZU() {
    int N = 5;
    int IA[] = {1, 2, 4, 6, 8, 10}; // 1-based indexing
    int JA[] = {1, 3, 2, 5, 4, 1, 3, 5, 2, 4}; // Content for JA based on the example
    int NZSUT;

    CNTNZU(N, IA, JA, NZSUT);

    assert(NZSUT == 4); // Adjusted based on the expected Fortran output
    std::cout << "Test passed: NZSUT = " << NZSUT << std::endl;
}

int main() {
    testCNTNZU();
    return 0;
}