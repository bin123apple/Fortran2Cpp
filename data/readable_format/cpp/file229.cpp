#include <iostream>
#include <cassert>

void sort(int N, int IX[], int IY[]) {
    int NN = N;
    int M = NN;

    do {
        M = (9 * M) / 16;
        if (M <= 0) break;
        int M1 = M + 1;
        for (int J = M1; J <= NN; ++J) {
            int L = J;
            int I = J - M;
            while (I >= 1) {
                if (IX[L - 1] < IX[I - 1]) {
                    int KEEPX = IX[I - 1];
                    int KEEPY = IY[I - 1];
                    IX[I - 1] = IX[L - 1];
                    IY[I - 1] = IY[L - 1];
                    IX[L - 1] = KEEPX;
                    IY[L - 1] = KEEPY;
                    L = I;
                    I = I - M;
                } else {
                    break;
                }
            }
        }
    } while (M > 0);
}

void testSort() {
    const int N = 5;
    int IX[N] = {5, 2, 4, 1, 3};
    int IY[N] = {50, 20, 40, 10, 30};
    
    sort(N, IX, IY);
    
    // Expected sorted arrays are based on the correct sorting logic.
    int expectedIX[N] = {1, 2, 3, 4, 5};
    int expectedIY[N] = {10, 20, 30, 40, 50};

    for (int i = 0; i < N; ++i) {
        assert(IX[i] == expectedIX[i] && IY[i] == expectedIY[i]);
    }
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testSort();
    return 0;
}