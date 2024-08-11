#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

// Forward declaration of the function
void write_tsde_dm_edm(const std::string& fname, int nspin, int no_u, const std::vector<int>& nsc, int nnz,
                       const std::vector<int>& ncol, const std::vector<int>& list_col,
                       const std::vector<std::vector<double>>& DM, const std::vector<std::vector<double>>& EDM, double Ef);

// Definition of the function
void write_tsde_dm_edm(const std::string& fname, int nspin, int no_u, const std::vector<int>& nsc, int nnz,
                       const std::vector<int>& ncol, const std::vector<int>& list_col,
                       const std::vector<std::vector<double>>& DM, const std::vector<std::vector<double>>& EDM, double Ef) {
    std::ofstream file(fname, std::ios::binary | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return; // Handle error
    }

    // Write metadata
    file.write(reinterpret_cast<const char*>(&no_u), sizeof(no_u));
    file.write(reinterpret_cast<const char*>(&nspin), sizeof(nspin));
    file.write(reinterpret_cast<const char*>(nsc.data()), 3 * sizeof(int));

    file.write(reinterpret_cast<const char*>(ncol.data()), no_u * sizeof(int));

    int n = 0;
    for (int io = 0; io < no_u; ++io) {
        file.write(reinterpret_cast<const char*>(&list_col[n]), ncol[io] * sizeof(int));
        n += ncol[io];
    }

    for (int is = 0; is < nspin; ++is) {
        n = 0;
        for (int io = 0; io < no_u; ++io) {
            for (int i = 0; i < ncol[io]; ++i) {
                double dm_val = DM[n + i][is];
                file.write(reinterpret_cast<const char*>(&dm_val), sizeof(double));
            }
            n += ncol[io];
        }
    }

    for (int is = 0; is < nspin; ++is) {
        n = 0;
        for (int io = 0; io < no_u; ++io) {
            for (int i = 0; i < ncol[io]; ++i) {
                double edm_val = EDM[n + i][is];
                file.write(reinterpret_cast<const char*>(&edm_val), sizeof(double));
            }
            n += ncol[io];
        }
    }

    file.write(reinterpret_cast<const char*>(&Ef), sizeof(Ef));

    file.close();
}

// Test function
void test_write_tsde_dm_edm() {
    std::string filename = "cpp_test.bin";
    std::vector<int> nsc = {10, 10, 10};
    int nspin = 2, no_u = 2, nnz = 6;
    std::vector<int> ncol = {3, 3}, list_col = {1, 2, 3, 4, 5, 6};
    std::vector<std::vector<double>> DM = {{0.1, 0.2}, {0.3, 0.4}, {0.5, 0.6}, {0.7, 0.8}, {0.9, 1.0}, {1.1, 1.2}};
    std::vector<std::vector<double>> EDM = {{0.2, 0.3}, {0.4, 0.5}, {0.6, 0.7}, {0.8, 0.9}, {1.0, 1.1}, {1.2, 1.3}};
    double Ef = 5.5;

    write_tsde_dm_edm(filename, nspin, no_u, nsc, nnz, ncol, list_col, DM, EDM, Ef);

    std::cout << "Test completed. Check '" << filename << "' for output." << std::endl;
}

// Main function
int main() {
    test_write_tsde_dm_edm();
    return 0;
}