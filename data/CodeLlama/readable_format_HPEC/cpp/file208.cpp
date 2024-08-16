#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double.
// Adjust the type if necessary.
void init_array(int n, std::vector<double>& p, std::vector<std::vector<double>>& a) {
    // Resize the vectors to match the dimensions n x n for a and n for p.
    p.resize(n);
    a.resize(n, std::vector<double>(n));

    // Initialize p and a as per the Fortran code.
    for (int i = 0; i < n; ++i) {
        p[i] = 1.0 / n;
        for (int j = 0; j < n; ++j) {
            a[j][i] = 1.0 / n;
        }
    }
}
