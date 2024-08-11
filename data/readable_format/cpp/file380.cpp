#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

// Assume the following is the C++ translation of the Fortran subroutine.
void xc_pzca(int n, const std::vector<double>& rho, std::vector<double>& ex, std::vector<double>& ec, std::vector<double>& vx, std::vector<double>& vc) {
    if (n <= 0) {
        std::cerr << "Error(xc_pzca): invalid n : " << n << std::endl;
        std::exit(EXIT_FAILURE);
    }

    const double pi = 3.1415926535897932385;
    const double thrd = 1.0 / 3.0, thrd2 = 2.0 / 3.0, thrd4 = 4.0 / 3.0;
    const double g = -0.1423, b1 = 1.0529, b2 = 0.3334;
    const double a = 0.0311, b = -0.048, c = 0.0020, d = -0.0116;

    double p1, p2, r, rs, t1;
    t1 = 3.0 / (4.0 * pi);
    p1 = pow(t1, thrd);
    p2 = t1 * pow((9.0 * pi / 4.0), thrd);

    for (int i = 0; i < n; i++) {
        r = rho[i];
        if (r < 1e-12) {
            ex[i] = 0.0;
            ec[i] = 0.0;
            vx[i] = 0.0;
            vc[i] = 0.0;
            continue;
        }

        rs = p1 / pow(r, thrd);
        ex[i] = -p2 / rs;
        vx[i] = thrd4 * ex[i];

        if (rs >= 1.0) {
            t1 = sqrt(rs);
            ec[i] = g / (1.0 + b1 * t1 + b2 * rs);
            vc[i] = ec[i] * (1.0 + (7.0 / 6.0) * b1 * t1 + thrd4 * b2 * rs) / (1.0 + b1 * t1 + b2 * rs);
        } else {
            t1 = log(rs);
            ec[i] = a * t1 + b + c * rs * t1 + d * rs;
            vc[i] = a * t1 + (b - thrd * a) + thrd2 * c * rs * t1 + thrd * (2.0 * d - c) * rs;
        }
    }
}

void testXcPzca(const std::vector<double>& rho) {
    int n = rho.size();
    std::vector<double> ex(n), ec(n), vx(n), vc(n);

    xc_pzca(n, rho, ex, ec, vx, vc);

    std::cout << "Testing with rho: ";
    for (double r : rho) std::cout << r << " ";
    std::cout << std::endl;

    std::cout << "Results:" << std::endl;
    std::cout << "ex: ";
    for (double val : ex) std::cout << val << " ";
    std::cout << std::endl << "ec: ";
    for (double val : ec) std::cout << val << " ";
    std::cout << std::endl << "vx: ";
    for (double val : vx) std::cout << val << " ";
    std::cout << std::endl << "vc: ";
    for (double val : vc) std::cout << val << " ";
    std::cout << std::endl << std::endl;
}

int main() {
    // Test 1: General case
    testXcPzca({0.1, 0.2, 0.3, 0.4, 0.5});
    
    // Additional tests can be added here
    // For instance, testing with empty rho, negative values, etc.

    return 0;
}