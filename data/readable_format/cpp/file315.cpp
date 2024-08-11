#include <iostream>
#include <vector>

void multev(const std::vector<double>& d, std::vector<std::vector<double>>& p) {
    int nv = d.size();
    for (int i = 0; i < nv; ++i) {
        for (int j = 0; j < nv; ++j) {
            p[j][i] /= d[i];
        }
    }
}

int main() {
    std::vector<double> d = {2.0, 3.0, 4.0};
    std::vector<std::vector<double>> p = {
        {11, 12, 13},
        {21, 22, 23},
        {31, 32, 33}
    };

    multev(d, p);

    for (int i = 0; i < p.size(); ++i) {
        for (int j = 0; j < p[i].size(); ++j) {
            std::cout << "p(" << i+1 << "," << j+1 << ") = " << p[i][j] << std::endl;
        }
    }

    return 0;
}