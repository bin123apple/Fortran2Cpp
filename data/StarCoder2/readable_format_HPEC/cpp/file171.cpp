#include <vector>
#include <cmath>

// Assuming the existence of these global variables, similar to the Fortran module 'cg_data'
extern double amult;
extern double tran;

// Forward declarations of external functions
double randlc(double a, double c);
int icnvrt(double x, int n);

void sprnvc(int n, int nz, int nn1, std::vector<double>& v, std::vector<int>& iv) {
    int nzv = 0;

    while (nzv < nz) {
        double vecelt = randlc(tran, amult);
        double vecloc = randlc(tran, amult);
        int i = icnvrt(vecloc, nn1) + 1; // Adjusting for 1-based indexing in C++

        if (i > n) continue;

        bool found = false;
        for (int ii = 0; ii < nzv; ++ii) {
            if (iv[ii] == i) {
                found = true;
                break;
            }
        }
        if (found) continue;

        nzv++;
        v[nzv - 1] = vecelt; // Adjusting for 0-based indexing
        iv[nzv - 1] = i;
    }
}

// Example definitions of the external functions (assuming they are part of the translation)
double randlc(double a, double c) {
    // Placeholder implementation
    return std::rand() * (c - a) + a;
}

int icnvrt(double x, int n) {
    // Placeholder implementation
    return static_cast<int>(std::round(x * n));
}

// Example global variables (assuming they are part of the translation)
double amult = 1.0;
double tran = 0.0;

int main() {
    int n = 10; // Example value
    int nz = 5;  // Example value
    int nn1 = 10; // Example value
    std::vector<double> v(nz);
    std::vector<int> iv(nz);

    sprnvc(n, nz, nn1, v, iv);

    // Output the results for verification
    for (int i = 0; i < nz; ++i) {
        std::cout << "v[" << i << "] = " << v[i] << ", iv[" << i << "] = " << iv[i] << std::endl;
    }

    return 0;
}
