#include <iostream>

// Function declaration is optional in this case since the definition is before main
void hrecur(double& pn, double& dpn, double& pn1, double x, int nn);

int main() {
    double x = 2.0;
    int nn = 5;
    double pn, dpn, pn1;

    // Call the function
    hrecur(pn, dpn, pn1, x, nn);

    // Print the results
    std::cout << "pn: " << pn << std::endl;
    std::cout << "dpn: " << dpn << std::endl;
    std::cout << "pn1: " << pn1 << std::endl;

    return 0;
}

// Function definition
void hrecur(double& pn, double& dpn, double& pn1, double x, int nn) {
    double p1 = 1.0;
    double p = x;
    double dp1 = 0.0;
    double dp = 1.0;
    for (int j = 2; j <= nn; ++j) {
        double fj = static_cast<double>(j);
        double fj2 = 0.5 * (fj - 1.0);
        double q = x * p - fj2 * p1;
        double dq = x * dp + p - fj2 * dp1;
        p1 = p;
        p = q;
        dp1 = dp;
        dp = dq;
    }
    pn = p;
    dpn = dp;
    pn1 = p1;
}