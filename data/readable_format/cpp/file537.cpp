#include <iostream>
#include <vector>

void indexx(int N, const std::vector<double>& arrin, std::vector<int>& indx) {
    for (int i = 0; i < N; ++i) {
        indx[i] = i;
    }

    if (N < 1) return;

    int L = N / 2;
    int IR = N - 1;
    while (true) {
        int INDXT;
        double Q;
        if (L > 0) {
            L = L - 1;
            INDXT = indx[L];
            Q = arrin[INDXT];
        } else {
            INDXT = indx[IR];
            Q = arrin[INDXT];
            indx[IR] = indx[0];
            IR = IR - 1;
            if (IR == 0) {
                indx[0] = INDXT;
                break;
            }
        }
        int I = L;
        int J = 2 * L + 1;
        while (J <= IR) {
            if (J < IR && arrin[indx[J]] < arrin[indx[J + 1]]) {
                J++;
            }
            if (Q < arrin[indx[J]]) {
                indx[I] = indx[J];
                I = J;
                J = 2 * J + 1;
            } else {
                break;
            }
        }
        indx[I] = INDXT;
    }
}

int main() {
    std::vector<std::vector<double>> testArrays = {
        {},
        {1.0, 5.0, 3.0, 4.0, 2.0},
        {2.0, 1.0, 2.0, 3.0, 3.0, 1.0}
    };

    for (size_t i = 0; i < testArrays.size(); ++i) {
        std::vector<double> arrin = testArrays[i];
        std::vector<int> indx(arrin.size());
        indexx(arrin.size(), arrin, indx);

        std::cout << "Test " << i + 1 << ": ";
        for (auto& idx : indx) std::cout << idx << " ";
        std::cout << std::endl;
    }

    return 0;
}