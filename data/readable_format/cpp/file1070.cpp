#include <iostream>
#include <vector>
#include <cassert> // For basic assertion checks

const int nelemg = 100; // Example size, adjust according to actual application

class Vect91 {
public:
    std::vector<double> xargat;
    Vect91() : xargat(nelemg, 0.0) {} // Initialize xargat to zero
};

void xghis1(Vect91& vect91, const std::vector<std::vector<double>>& a, int ln, int nft, int nlt) {
    // Assuming 'a' is a 2D vector passed with dimensions, and ln is the leading dimension.
    // Loop to modify xargat based on 'a'
    for (int i = nft; i <= nlt; ++i) {
        vect91.xargat[i-1] = a[0][i-1]; // Adjusting indices for 0-based C++ arrays
    }
}

int main() {
    Vect91 vect91;
    int ln = 10; // Example dimensions, adjust based on actual usage
    int nft = 1, nlt = 5; // Example loop bounds, adjust based on actual usage
    std::vector<std::vector<double>> a(ln, std::vector<double>(nelemg, 0.0)); // Initialize with zeros

    // Fill 'a' with some values for demonstration
    for (int i = nft; i <= nlt; ++i) {
        a[0][i-1] = i * 1.0; // Simple test values
    }

    // Call the function
    xghis1(vect91, a, ln, nft, nlt);

    // Simple checks to verify the function worked as expected
    for (int i = 0; i < nelemg; ++i) {
        if (i >= nft-1 && i <= nlt-1) {
            assert(vect91.xargat[i] == (i + 1) * 1.0); // Check modified values
        } else {
            assert(vect91.xargat[i] == 0.0); // Check unchanged values
        }
    }

    std::cout << "C++: All tests passed." << std::endl;

    return 0;
}