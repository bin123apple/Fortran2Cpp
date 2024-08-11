#include <vector>
#include <iostream>

class MOD_DG_Vars {
public:
    std::vector<std::vector<double>> D;
    std::vector<std::vector<std::vector<std::vector<double>>>> U;
    std::vector<std::vector<std::vector<std::vector<double>>>> Ut;

    int nTotalU;
    int nDOFFace;
    int nDOFElem;

    std::vector<std::vector<std::vector<std::vector<double>>>> U_master;
    std::vector<std::vector<std::vector<std::vector<double>>>> U_slave;
    std::vector<std::vector<std::vector<std::vector<double>>>> Flux_master;
    std::vector<std::vector<std::vector<std::vector<double>>>> Flux_slave;

    std::vector<std::vector<std::vector<std::vector<double>>>> UPrim;
    std::vector<std::vector<std::vector<std::vector<double>>>> UPrim_master;
    std::vector<std::vector<std::vector<std::vector<double>>>> UPrim_slave;

    int SplitDG;
    std::vector<std::vector<std::vector<double>>> UPrim_Boundary;

    bool DGInitIsDone = false;
};

void TestMOD_DG_Vars() {
    MOD_DG_Vars dgVars;

    // Correctly initializing the vectors
    dgVars.D = std::vector<std::vector<double>>(10, std::vector<double>(10, 1.0));
    
    // Corrected initialization for U
    std::vector<double> innerMost(2, 2.0);
    std::vector<std::vector<double>> thirdLayer(5, innerMost);
    std::vector<std::vector<std::vector<double>>> secondLayer(5, thirdLayer);
    std::vector<std::vector<std::vector<std::vector<double>>>> firstLayer(5, secondLayer);
    dgVars.U = firstLayer;

    // Corrected initialization for UPrim_Boundary
    std::vector<double> boundaryInner(2, 3.0);
    std::vector<std::vector<double>> boundaryMiddle(3, boundaryInner);
    std::vector<std::vector<std::vector<double>>> boundaryOuter(3, boundaryMiddle);
    dgVars.UPrim_Boundary = boundaryOuter;

    // Simple checks
    bool testPassed = true;

    // Using nested loops to check the values in a multi-dimensional vector
    for (const auto &row : dgVars.D) {
        for (const auto &elem : row) {
            if (elem != 1.0) {
                testPassed = false;
                break;
            }
        }
        if (!testPassed) break;
    }

    if (testPassed) {
        for (const auto &matrix : dgVars.U) {
            for (const auto &cube : matrix) {
                for (const auto &face : cube) {
                    for (const auto &elem : face) {
                        if (elem != 2.0) {
                            testPassed = false;
                            break;
                        }
                    }
                    if (!testPassed) break;
                }
                if (!testPassed) break;
            }
            if (!testPassed) break;
        }
    }

    if (testPassed) {
        for (const auto &cube : dgVars.UPrim_Boundary) {
            for (const auto &face : cube) {
                for (const auto &elem : face) {
                    if (elem != 3.0) {
                        testPassed = false;
                        break;
                    }
                }
                if (!testPassed) break;
            }
            if (!testPassed) break;
        }
    }

    if (testPassed) {
        std::cout << "C++ Test Passed" << std::endl;
    } else {
        std::cout << "C++ Test Failed" << std::endl;
    }
}

int main() {
    TestMOD_DG_Vars();
    return 0;
}