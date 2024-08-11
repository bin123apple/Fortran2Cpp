#include <iostream>
#include <vector>

// The function to be tested
void probleme(std::vector<double>& p, int& nx, int& nix) {
    nx = p.size();
    nix = nx;
}

// A simple function to test 'probleme'
void testProbleme() {
    std::vector<double> p = {1.0, 2.0, 3.0};
    int nx = 0, nix = 0;

    // Call the function with the test case
    probleme(p, nx, nix);

    // Check the result and report
    if (nx == 3 && nix == 3) {
        std::cout << "Test passed: nx and nix are correctly set to " << nx << "." << std::endl;
    } else {
        std::cerr << "Test failed: nx or nix are not correctly set. nx: " << nx << ", nix: " << nix << "." << std::endl;
    }
}

int main() {
    // Run the test
    testProbleme();

    return 0;
}