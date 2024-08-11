#include <iostream>
#include <vector>

// Define the selci_mxmb function
void selci_mxmb(const std::vector<double>& a, int mcola, int mrowa,
                const std::vector<double>& b, int mcolb, int mrowb,
                std::vector<double>& r, int mcolr, int mrowr,
                int ncol, int nlink, int nrow) {
    int ir = 0; // Adjusted for 0-indexing
    int ib = 0; // Adjusted for 0-indexing
    for (int j = 0; j < nrow; ++j) {
        int ibb = ib;
        int ia = 0; // Adjusted for 0-indexing
        for (int k = 0; k < nlink; ++k) {
            double fac = b[ibb];
            if (fac != 0) { // Adjusted condition check for C++
                int irr = ir;
                int iaa = ia;
                for (int i = 0; i < ncol; ++i) {
                    r[irr] += fac * a[iaa];
                    irr += mcolr;
                    iaa += mcola;
                }
            }
            ibb += mcolb;
            ia += mrowa;
        }
        ir += mrowr;
        ib += mrowb;
    }
}

// Unit test function
void testMatrixMultiplication() {
    std::vector<double> a = {1, 2, 3, 4};
    std::vector<double> b = {2, 0, 1, 2};
    std::vector<double> r(4, 0.0); // Initialize result matrix with zeros

    int mcola = 1, mrowa = 2, mcolb = 1, mrowb = 2;
    int mcolr = 1, mrowr = 2;
    int ncol = 2, nlink = 2, nrow = 2;

    selci_mxmb(a, mcola, mrowa, b, mcolb, mrowb, r, mcolr, mrowr, ncol, nlink, nrow);

    std::cout << "Result matrix R:" << std::endl;
    for (double elem : r) {
        std::cout << elem << std::endl;
    }

    // Expected: r = {2, 4, 8, 10}
}

int main() {
    testMatrixMultiplication();
    return 0;
}