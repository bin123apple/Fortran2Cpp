#include <cassert>
#include <iostream>
#include <vector>

// Function Prototype
void grid2triple(const std::vector<double>& X, const std::vector<double>& Y,
                 const std::vector<std::vector<double>>& Z, int MX, int NY,
                 std::vector<std::vector<double>>& D, int& LD, int LDMAX,
                 double ZMSG, int& IER);

// Function Implementation
void grid2triple(const std::vector<double>& X, const std::vector<double>& Y,
                 const std::vector<std::vector<double>>& Z, int MX, int NY,
                 std::vector<std::vector<double>>& D, int& LD, int LDMAX,
                 double ZMSG, int& IER) {
    IER = 0;
    LD = 0;

    D.resize(LDMAX, std::vector<double>(3, 0.0));

    for (int n = 0; n < NY; ++n) {
        for (int m = 0; m < MX; ++m) {
            if (Z[m][n] != ZMSG) {
                if (LD < LDMAX) {
                    D[LD][0] = X[m];
                    D[LD][1] = Y[n];
                    D[LD][2] = Z[m][n];
                    ++LD;
                } else {
                    IER = -11; // Error code for exceeding LDMAX
                    return;
                }
            }
        }
    }

    if (LD == 0) {
        IER = -10;
    }
}

// Helper function for printing D
void printD(const std::vector<std::vector<double>>& D, int LD) {
    for (int i = 0; i < LD; ++i) {
        std::cout << "(" << D[i][0] << ", " << D[i][1] << ", " << D[i][2] << ")" << std::endl;
    }
}

// Test scenario 1
void testScenario1() {
    std::vector<double> X = {1, 2};
    std::vector<double> Y = {1, 2};
    std::vector<std::vector<double>> Z = {{2, 3}, {3, 4}};
    std::vector<std::vector<double>> D(4, std::vector<double>(3, 0));
    double ZMSG = -999.0;
    int MX = 2, NY = 2, LD, IER;
    int LDMAX = 4;
    
    grid2triple(X, Y, Z, MX, NY, D, LD, LDMAX, ZMSG, IER);
    assert(LD == 4); // Expecting 4 valid triples
    assert(IER == 0); // No error
    std::cout << "Scenario 1 passed" << std::endl;
    printD(D, LD);
}

// Test scenario 2
void testScenario2() {
    std::vector<double> X = {1, 2};
    std::vector<double> Y = {1, 2};
    std::vector<std::vector<double>> Z = {{-999, 3}, {3, 4}};
    std::vector<std::vector<double>> D(4, std::vector<double>(3, 0));
    double ZMSG = -999.0;
    int MX = 2, NY = 2, LD, IER;
    int LDMAX = 4;
    
    grid2triple(X, Y, Z, MX, NY, D, LD, LDMAX, ZMSG, IER);
    assert(LD == 3); // Expecting 3 valid triples
    assert(IER == 0); // No error
    std::cout << "Scenario 2 passed" << std::endl;
    printD(D, LD);
}

// Test scenario 3
void testScenario3() {
    std::vector<double> X = {1, 2};
    std::vector<double> Y = {1, 2};
    std::vector<std::vector<double>> Z = {{-999, -999}, {-999, -999}};
    std::vector<std::vector<double>> D(4, std::vector<double>(3, 0));
    double ZMSG = -999.0;
    int MX = 2, NY = 2, LD, IER;
    int LDMAX = 4;
    
    grid2triple(X, Y, Z, MX, NY, D, LD, LDMAX, ZMSG, IER);
    assert(LD == 0); // Expecting 0 valid triples
    assert(IER == -10); // Error code for no valid triples
    std::cout << "Scenario 3 passed" << std::endl;
}

// Main function to run tests
int main() {
    testScenario1();
    testScenario2();
    testScenario3();
    return 0;
}