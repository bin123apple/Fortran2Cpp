#include <vector>
#include <cmath>
#include <algorithm>

// Assuming external functions randlc and icnvrt are available
// and their signatures are as follows:
double randlc(double tran, double amult);
int icnvrt(double vecloc, int nn1);

void sprnvc(int n, int nz, int nn1, std::vector<double>& v, std::vector<int>& iv) {
    int nzv = 0;
    int ii, i;
    double vecelt, vecloc;

    while (nzv < nz) {
        vecelt = randlc(tran, amult);
        vecloc = randlc(tran, amult);
        i = icnvrt(vecloc, nn1) + 1;
        if (i > n) continue;

        for (ii = 1; ii <= nzv; ++ii) {
            if (iv[ii - 1] == i) continue;
        }

        nzv += 1;
        v[nzv - 1] = vecelt;
        iv[nzv - 1] = i;
    }
}

// Example usage
int main() {
    int n = 10; // Example size of n
    int nz = 5; // Example size of nz
    int nn1 = 100; // Example value for nn1
    std::vector<double> v(nz); // Initialize vector v with size nz
    std::vector<int> iv(nz); // Initialize vector iv with size nz

    // Assuming randlc and icnvrt are properly defined and initialized
    double tran = 0.0; // Example value for tran
    double amult = 1.0; // Example value for amult

    sprnvc(n, nz, nn1, v, iv);

    // Output results for demonstration
    for (int i = 0; i < nz; ++i) {
        std::cout << "v[" << i << "] = " << v[i] << ", iv[" << i << "] = " << iv[i] << std::endl;
    }

    return 0;
}
