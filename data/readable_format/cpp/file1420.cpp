// essai.cpp
#include <iostream>
#include <array>

const int NbDim = 3;
const int NbPoints = 5;

void changer_coordonnees(const std::array<double, NbDim>& Deplacement, std::array<std::array<double, NbPoints>, NbDim>& Points);

void test_changer_coordonnees();

int main() {
    test_changer_coordonnees();
    return 0;
}

void changer_coordonnees(const std::array<double, NbDim>& Deplacement, std::array<std::array<double, NbPoints>, NbDim>& Points) {
    for (int l = 0; l < NbPoints; ++l) {
        for (int c = 0; c < NbDim; ++c) {
            Points[c][l] += Deplacement[c];
        }
    }
}

void test_changer_coordonnees() {
    const std::array<double, NbDim> TestDeplacement = {0.5, -2.5, 3.0};
    std::array<std::array<double, NbPoints>, NbDim> TestPoints = {{
        {0., 1., 2., 3., 4.},
        {5., 6., 7., 8., 9.},
        {10., 11., 12., 13., 14.}
    }};
    std::array<std::array<double, NbPoints>, NbDim> ExpectedPoints = {{
        {0.5, 1.5, 2.5, 3.5, 4.5},
        {2.5, 3.5, 4.5, 5.5, 6.5},
        {13.0, 14.0, 15.0, 16.0, 17.0}
    }};

    changer_coordonnees(TestDeplacement, TestPoints);

    bool test_passed = true;
    for (int c = 0; c < NbDim; ++c) {
        for (int l = 0; l < NbPoints; ++l) {
            if (TestPoints[c][l] != ExpectedPoints[c][l]) {
                test_passed = false;
                break;
            }
        }
        if (!test_passed) break;
    }

    if (test_passed) {
        std::cout << "C++ Unit Test PASSED." << std::endl;
    } else {
        std::cout << "C++ Unit Test FAILED." << std::endl;
    }
}