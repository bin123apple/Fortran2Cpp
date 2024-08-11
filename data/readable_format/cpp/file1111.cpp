#include <iostream>
#include <cmath>

// Constants
const double pi = 3.141592653589793238462;
const double dr = 0.05, rmax = 100, rasymp = 50;
const int nr = static_cast<int>(std::round(rmax / dr)); // Adjusted for rounding
const int nasymp = static_cast<int>(std::round(rasymp / dr)); // Adjusted for rounding
const double ecmin = 0.002;

// Variables
double vclus = 0.2, fluc = 0.1, rpot = 15.0;
int num_para = -1;

int main() {
    std::cout << "Testing constants and variables..." << std::endl;
    std::cout << "pi: " << pi << std::endl;
    std::cout << "dr: " << dr << std::endl;
    std::cout << "rmax: " << rmax << std::endl;
    std::cout << "rasymp: " << rasymp << std::endl;
    std::cout << "nr: " << nr << std::endl;
    std::cout << "nasymp: " << nasymp << std::endl;
    std::cout << "ecmin: " << ecmin << std::endl;
    std::cout << "vclus: " << vclus << std::endl;
    std::cout << "fluc: " << fluc << std::endl;
    std::cout << "rpot: " << rpot << std::endl;
    std::cout << "num_para: " << num_para << std::endl;

    return 0;
}