#include <vector>
#include <cmath>
#include <algorithm>
#include <gtest/gtest.h>

// Assuming the use of std::vector for dynamic arrays. Adjust types if necessary.
void flood(const std::vector<std::vector<double>>& zslice,
           const std::vector<std::vector<int>>& wet,
           const std::vector<std::vector<int>>& dry,
           const std::vector<std::vector<double>>& x,
           const std::vector<std::vector<double>>& y,
           const double dmax,
           std::vector<std::vector<double>>& flooded_zslice,
           const int im, const int jm, const int nbwet, const int nbdry) {
    
    flooded_zslice = zslice; // Copy the zslice to flooded_zslice
    std::vector<double> d(nbwet);
    int dmin_idx;
    
    for (int n = 0; n < nbdry; ++n) {
        int idry = dry[n][0] - 1; // Adjust for 0-based indexing
        int jdry = dry[n][1] - 1;
        
        for (int m = 0; m < nbwet; ++m) {
            int iwet = wet[m][0] - 1;
            int jwet = wet[m][1] - 1;
            
            d[m] = std::sqrt((x[idry][jdry] - x[iwet][jwet]) * (x[idry][jdry] - x[iwet][jwet]) +
                             (y[idry][jdry] - y[iwet][jwet]) * (y[idry][jdry] - y[iwet][jwet]));
        }
        
        auto it = std::min_element(d.begin(), d.end());
        dmin_idx = std::distance(d.begin(), it);
        
        if (dmax == 0 || *it < dmax) {
            int iclose = wet[dmin_idx][0] - 1;
            int jclose = wet[dmin_idx][1] - 1;
            flooded_zslice[idry][jdry] = zslice[iclose][jclose];
        }
    }
}

// Test cases
TEST(FloodTest, BasicCase) {
    std::vector<std::vector<double>> zslice = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<std::vector<int>> wet = {{1, 1}};
    std::vector<std::vector<int>> dry = {{2, 2}};
    std::vector<std::vector<double>> x = {{0.0, 1.0}, {0.0, 1.0}};
    std::vector<std::vector<double>> y = {{0.0, 0.0}, {1.0, 1.0}};
    std::vector<std::vector<double>> flooded_zslice(2, std::vector<double>(2));
    int im = 2, jm = 2, nbwet = 1, nbdry = 1;
    double dmax = 0;

    flood(zslice, wet, dry, x, y, dmax, flooded_zslice, im, jm, nbwet, nbdry);

    EXPECT_DOUBLE_EQ(flooded_zslice[1][1], 1.0);
}

// Additional tests can be added following the same pattern

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}