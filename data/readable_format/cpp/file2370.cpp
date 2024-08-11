// utilbd.cpp
#include <iostream>
#include <array>
#include <cassert>

// Global variables as common blocks
std::array<int, 100> IU;
std::array<double, 50> QX, QY;
std::array<int, 25> IF;
int NQ, NF;
int JX, JY;

void InitializeCommonBlocks() {
    // Initialize IU array
    IU = {1, 1, 10, 10, 50, 2, 1, 1, 1, 8000, 0, 1, 1000, 1000};
    NQ = 1;
    QX.fill(0.0); // QX[0] initialized to 0.0 explicitly
    QY.fill(0.0); // QY[0] initialized to 0.0 explicitly
    NF = 1;
    IF.fill(0);   // IF[0] initialized to 1 explicitly
    IF[0] = 1;
    JX = 0;
    JY = 0;
}

void UnitTests() {
    assert(IU[0] == 1);
    assert(NQ == 1);
    assert(QX[0] == 0.0);
    assert(JX == 0);
    std::cout << "All tests passed." << std::endl;
}

int main() {
    InitializeCommonBlocks();
    UnitTests();
    return 0;
}