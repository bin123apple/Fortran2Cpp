#include <iostream>
#include <vector>
#include <cmath>

// Forward declaration of PlSchmidt
void PlSchmidt(std::vector<double>& p, int lmax, double z, int* exitstatus);

// Definition of PlSchmidt
void PlSchmidt(std::vector<double>& p, int lmax, double z, int* exitstatus) {
    if (exitstatus) *exitstatus = 0;

    if (p.size() < static_cast<size_t>(lmax + 1)) {
        if (exitstatus) {
            *exitstatus = 1;
            return;
        } else {
            std::cerr << "Error: Array p is too small." << std::endl;
            exit(1);
        }
    }

    double pm2 = 1.0;
    p[0] = 1.0;

    if (lmax > 0) {
        double pm1 = z;
        p[1] = pm1;

        for (int l = 2; l <= lmax; ++l) {
            double pl = ((2 * l - 1) * z * pm1 - (l - 1) * pm2) / l;
            p[l] = pl;
            pm2 = pm1;
            pm1 = pl;
        }
    }
}

// Test function
void testPlSchmidt(int lmax, double z) {
    std::vector<double> p(lmax + 1);
    int exitstatus = 0; // Use a regular int variable here

    PlSchmidt(p, lmax, z, &exitstatus); // Pass the address of exitstatus

    if (exitstatus != 0) {
        std::cerr << "Error with exit status: " << exitstatus << std::endl;
        return;
    }

    for (int i = 0; i <= lmax; ++i) {
        std::cout << "P[" << i << "] = " << p[i] << std::endl;
    }
}

int main() {
    int lmax = 4;
    double z = 0.5;

    std::cout << "Testing PlSchmidt with lmax = " << lmax << " and z = " << z << std::endl;
    testPlSchmidt(lmax, z);

    return 0;
}