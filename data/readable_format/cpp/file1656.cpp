// File: MoColumn.cpp
#include <iostream>
#include <vector>
#include <cmath>

class MoColumn {
public:
    static std::vector<double> computeColumn(const std::vector<std::vector<double>>& t, 
                                             const std::vector<std::vector<double>>& q, 
                                             int nz, double b, int nproma, double o) {
        std::vector<double> columnResult(nz, 0.0);
        for (int i = 0; i < nz; ++i) {
            for (int j = 0; j < nproma; ++j) {
                columnResult[i] += (t[i][j] + q[i][j]) * b + o;
            }
        }
        return columnResult;
    }
};

int main() {
    std::vector<std::vector<double>> t = {{1.0, 3.0}, {2.0, 4.0}};
    std::vector<std::vector<double>> q = {{0.5, 2.5}, {1.5, 3.5}};
    int nz = 2;
    double b = 1.0;
    int nproma = 2;
    double o = 0.5;

    std::vector<double> result = MoColumn::computeColumn(t, q, nz, b, nproma, o);

    std::cout << "C++ Result: ";
    for (auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}