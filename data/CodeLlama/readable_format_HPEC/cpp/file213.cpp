#include <vector>
#include <cmath> // For std::pow

// Assuming DATA_TYPE is a placeholder for the actual data type, let's use double for this example.
// If you need a different data type, you can easily change it.
using DATA_TYPE = double;

void init_array(int ni, int nj, DATA_TYPE& alpha, DATA_TYPE& beta, std::vector<std::vector<DATA_TYPE>>& c, 
                std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    // Initialize alpha and beta
    alpha = 32412.0;
    beta = 2123.0;

    // Resize vectors to match dimensions nj x nj for a, b, and nj x ni for c
    a.resize(nj, std::vector<DATA_TYPE>(nj));
    b.resize(nj, std::vector<DATA_TYPE>(ni));
    c.resize(nj, std::vector<DATA_TYPE>(ni));

    // Fill arrays a, b, and c with values
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < nj; ++j) {
            c[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<double>(ni));
            b[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<double>(ni));
        }
    }

    for (int i = 0; i < nj; ++i) {
        for (int j = 0; j < nj; ++j) {
            a[j][i] = static_cast<DATA_TYPE>((i * j) / static_cast<double>(ni));
        }
    }
}

int main() {
    int ni = 5; // Example values
    int nj = 5;
    double alpha, beta;
    std::vector<std::vector<double>> c, a, b;

    init_array(ni, nj, alpha, beta, c, a, b);

    // Example of accessing some values
    // For demonstration, let's print a few values
    std::cout << "Alpha: " << alpha << std::endl;
    std::cout << "Beta: " << beta << std::endl;
    std::cout << "c[0][0]: " << c[0][0] << std::endl;
    std::cout << "a[0][0]: " << a[0][0] << std::endl;
    std::cout << "b[0][0]: " << b[0][0] << std::endl;

    return 0;
}
