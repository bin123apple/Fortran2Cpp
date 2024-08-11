#include <iostream>

void ugetio(int& iopt, int& nin, int& nout) {
    static int nind = 1;
    static int noutd = 2;

    if (iopt == 3) {
        noutd = nout;
    } else if (iopt == 2) {
        nind = nin;
    } else if (iopt == 1) {
        nin = nind;
        nout = noutd;
    }
}

int main() {
    int nin, nout;

    int iopt1 = 1;
    // Test iopt = 1
    ugetio(iopt1, nin, nout);
    std::cout << "Test iopt=1: nin=" << nin << " nout=" << nout << std::endl;

    int iopt2 = 2;
    nin = 10;
    // Test iopt = 2
    ugetio(iopt2, nin, nout);
    std::cout << "Test iopt=2: nin=" << nin << " nout=" << nout << std::endl;

    int iopt3 = 3;
    nout = 20;
    // Test iopt = 3
    ugetio(iopt3, nin, nout);
    std::cout << "Test iopt=3: nin=" << nin << " nout=" << nout << std::endl;

    return 0;
}