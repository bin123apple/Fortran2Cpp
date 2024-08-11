#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

void dihed(const vector<vector<double>>& XYZ, int I, int J, int K, int L, double& ANGLE) {
    double dx = XYZ[0][I] - XYZ[0][J];
    double dy = XYZ[1][K] - XYZ[1][L];
    double dz = XYZ[2][I] - XYZ[2][L];
    ANGLE = sqrt(dx*dx + dy*dy + dz*dz);
}

void test_dihed() {
    vector<vector<double>> XYZ = {{0.0, 3.0, 6.0, 9.0},
                                  {1.0, 4.0, 7.0, 10.0},
                                  {2.0, 5.0, 8.0, 11.0}};
    int I = 0, J = 1, K = 2, L = 1;
    double ANGLE = 0.0;

    dihed(XYZ, I, J, K, L, ANGLE);
    cout << "ANGLE: " << ANGLE << endl;

    // For checking correctness:
    double expected_angle = sqrt(pow(XYZ[0][I] - XYZ[0][J], 2) +
                                 pow(XYZ[1][K] - XYZ[1][L], 2) +
                                 pow(XYZ[2][I] - XYZ[2][L], 2));
    assert(abs(ANGLE - expected_angle) < 1e-6);
}

int main() {
    test_dihed();
    return 0;
}