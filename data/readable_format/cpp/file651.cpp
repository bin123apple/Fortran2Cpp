#include <iostream>
#include <vector>
#include <cassert>

void kcache(int istart, int iend, int jstart, int jend, double &sum6, double &sum7, double &sum8, double &sum9) {
    int irows = iend - istart + 1;
    int jcols = jend - jstart + 1;
    std::vector<std::vector<double>> array6(irows, std::vector<double>(jcols, 0.0));
    std::vector<std::vector<double>> array7(irows, std::vector<double>(jcols, 0.0));
    std::vector<std::vector<double>> array8(irows, std::vector<double>(jcols, 0.0));
    std::vector<std::vector<double>> array9(irows, std::vector<double>(jcols, 0.0));
    std::vector<std::vector<double>> data1(irows, std::vector<double>(jcols, 2.0));
    std::vector<std::vector<double>> data2(irows, std::vector<double>(jcols, 3.0));

    for (int i = 0; i < irows; ++i) {
        array6[i][0] = 1.0;
        array7[i][0] = 2.0;
        array8[i][0] = 3.0;
        array9[i][0] = 4.0;
    }

    for (int i = 0; i < irows; ++i) {
        for (int j = 1; j < jcols; ++j) {
            array6[i][j] = array6[i][j-1] * 2.0 + data1[i][j];
            array7[i][j] = array7[i][j-1] * 2.0 + array6[i][j-1] + data1[i][j];
            array8[i][j] = array8[i][j-1] * 2.0 + array6[i][j-1] + array7[i][j-1] + data2[i][j];
            array9[i][j] = array9[i][j-1] * 2.0 + array6[i][j-1] + array8[i][j-1] + data2[i][j];
        }
    }

    sum6 = sum7 = sum8 = sum9 = 0.0;
    for (int i = 0; i < irows; ++i) {
        for (int j = 0; j < jcols; ++j) {
            sum6 += array6[i][j];
            sum7 += array7[i][j];
            sum8 += array8[i][j];
            sum9 += array9[i][j];
        }
    }
}

int main() {
    double sum6, sum7, sum8, sum9;
    kcache(1, 10, 1, 20, sum6, sum7, sum8, sum9);

    std::cout << "Computed sums:" << std::endl;
    std::cout << sum6 << std::endl;
    std::cout << sum7 << std::endl;
    std::cout << sum8 << std::endl;
    std::cout << sum9 << std::endl;

    return 0;
}