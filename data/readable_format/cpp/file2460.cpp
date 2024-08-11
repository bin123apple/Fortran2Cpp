#include <iostream>
#include <string>
#include <complex>
#include <vector>

class COM_VAR {
public:
    float RHO = 1.225f;
    float G = 9.81f;
    float Depth = 100.0f;
    float XEFF = 1.0f, YEFF = 2.0f, ZEFF = 3.0f;
    std::string MESHFILE = "mesh.dat";
    int LFILE = 10, NP = 1000, NFA = 2000;
    int IMX = 10, IXX = 20, NSYMY = 30;
    float ZER = 0.0f;
    int Indiq_solver = 1;
    int Sav_potential = 1;
    // Add more variables as needed

    // Example function to demonstrate testing
    float calculateSomething() {
        return RHO + G + Depth + XEFF + YEFF + ZEFF;
    }
};

void testCalculateSomething() {
    COM_VAR var;
    float expectedValue = 1.225f + 9.81f + 100.0f + 1.0f + 2.0f + 3.0f;
    float result = var.calculateSomething();

    if (result == expectedValue) {
        std::cout << "testCalculateSomething: PASS" << std::endl;
    } else {
        std::cout << "testCalculateSomething: FAIL" << std::endl;
    }
}

int main() {
    // Run our simple test
    testCalculateSomething();

    return 0;
}