#include <iostream>
#include <vector>

void bubble(std::vector<std::vector<double>>& ten, std::vector<std::vector<int>>& j1, std::vector<std::vector<int>>& j2, std::vector<std::vector<int>>& j3, int m, int ind) {
    if (ind == 1) {
        for (int i = 1; i < m; i++) {
            if (ten[i][ind] > ten[i + 1][ind]) {
                std::swap(ten[i], ten[i + 1]);
                std::swap(j1[i], j1[i + 1]);
                std::swap(j2[i], j2[i + 1]);
                std::swap(j3[i], j3[i + 1]);
            }
        }
    } else {
        for (int i = 1; i < m; i++) {
            if (ten[i][ind] < ten[i + 1][ind]) {
                std::swap(ten[i], ten[i + 1]);
                std::swap(j1[i], j1[i + 1]);
                std::swap(j2[i], j2[i + 1]);
                std::swap(j3[i], j3[i + 1]);
            }
        }
    }
}
