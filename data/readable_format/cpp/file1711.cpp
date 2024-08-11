#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

void kcache(int istart, int iend, int jstart, int jend, double& sumA6, double& sumA7, double& sumA8, double& sumA9) {
    int iwidth = iend - istart + 1;
    int jwidth = jend - jstart + 1;
    std::vector<std::vector<double>> data1(iwidth, std::vector<double>(jwidth, 2.0));
    std::vector<std::vector<double>> data2(iwidth, std::vector<double>(jwidth, 3.0));
    std::vector<std::vector<double>> array6(iwidth, std::vector<double>(jwidth, 0.0));
    std::vector<std::vector<double>> array7(iwidth, std::vector<double>(jwidth, 0.0));
    std::vector<std::vector<double>> array8(iwidth, std::vector<double>(jwidth, 0.0));
    std::vector<std::vector<double>> array9(iwidth, std::vector<double>(jwidth, 0.0));

    for (int i = 0; i < iwidth; ++i) {
        array6[i][0] = 1.0;
        array7[i][0] = 2.0;
        array8[i][0] = 3.0;
        array9[i][0] = 4.0;
    }

    for (int i = 0; i < iwidth; ++i) {
        for (int j = 1; j < jwidth; ++j) {
            data1[i][j-1] = 0.0;
            array6[i][j] = array6[i][j-1] * 2.0 + data1[i][j];
            array7[i][j] = array7[i][j-1] * 2.0 + array6[i][j-1] + data1[i][j];
            array8[i][j] = array8[i][j-1] * 2.0 + array6[i][j-1] + array7[i][j-1] + data2[i][j];
            array9[i][j] = array9[i][j-1] * 2.0 + array6[i][j-1] + array8[i][j-1] + data2[i][j];
        }
    }

    sumA6 = std::accumulate(array6.begin(), array6.end(), 0.0, [](double sum, const std::vector<double>& vec) {
        return sum + std::accumulate(vec.begin(), vec.end(), 0.0);
    });
    sumA7 = std::accumulate(array7.begin(), array7.end(), 0.0, [](double sum, const std::vector<double>& vec) {
        return sum + std::accumulate(vec.begin(), vec.end(), 0.0);
    });
    sumA8 = std::accumulate(array8.begin(), array8.end(), 0.0, [](double sum, const std::vector<double>& vec) {
        return sum + std::accumulate(vec.begin(), vec.end(), 0.0);
    });
    sumA9 = std::accumulate(array9.begin(), array9.end(), 0.0, [](double sum, const std::vector<double>& vec) {
        return sum + std::accumulate(vec.begin(), vec.end(), 0.0);
    });
}

void test() {
    double sumA6, sumA7, sumA8, sumA9;
    kcache(1, 10, 1, 20, sumA6, sumA7, sumA8, sumA9);
    std::cout << "C++ Test Results:" << std::endl;
    std::cout << "Sum of array6: " << sumA6 << std::endl;
    std::cout << "Sum of array7: " << sumA7 << std::endl;
    std::cout << "Sum of array8: " << sumA8 << std::endl;
    std::cout << "Sum of array9: " << sumA9 << std::endl;
}

int main() {
    test();
    return 0;
}