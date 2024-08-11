#include <iostream>
#include <vector>

// Mock the MPI functionality relevant for our example
namespace MPI {
    const int MPI_UNDEFINED = -1;
    const int COMM_WORLD = 0;
    void Abort(int, int) {
        std::cerr << "MPI_Abort called: Limit of companies has been exceeded." << std::endl;
        exit(1); // Exit the program to simulate MPI_Abort behavior
    }
}

// Assuming constants for indexing into the company table, for simplicity
const int c_company_id = 0, c_nmgr = 1, c_mgr_mem = 2, c_nwrkr = 3, c_wrkr_mem = 4;
const int max_company = 10; // Maximum number of companies
int c_table[max_company][5]; // Company table: simplified version

void build_company(int id, int nmgr, int mgr_mem, int nwrkr, int wrkr_mem) {
    for (int i = 0; i < max_company; ++i) {
        if (c_table[i][c_company_id] == MPI::MPI_UNDEFINED) {
            c_table[i][c_company_id] = id;
            c_table[i][c_nmgr] = nmgr;
            c_table[i][c_mgr_mem] = mgr_mem;
            c_table[i][c_nwrkr] = nwrkr;
            c_table[i][c_wrkr_mem] = wrkr_mem;
            return;
        }
    }

    // If we reach this point, it means the company limit has been exceeded.
    MPI::Abort(MPI::COMM_WORLD, 1);
}

int main() {
    // Initialize the company table
    for (int i = 0; i < max_company; ++i) {
        for (int j = 0; j < 5; ++j) {
            c_table[i][j] = MPI::MPI_UNDEFINED;
        }
    }

    // Example usage of build_company
    build_company(1, 2, 100, 50, 500);
    build_company(2, 3, 150, 60, 600);

    // Print the company table to verify
    for (int i = 0; i < max_company; ++i) {
        if (c_table[i][c_company_id] != MPI::MPI_UNDEFINED) {
            std::cout << "Company ID: " << c_table[i][c_company_id]
                      << ", Managers: " << c_table[i][c_nmgr]
                      << ", Manager Memory: " << c_table[i][c_mgr_mem]
                      << ", Workers: " << c_table[i][c_nwrkr]
                      << ", Worker Memory: " << c_table[i][c_wrkr_mem]
                      << std::endl;
        }
    }

    return 0;
}