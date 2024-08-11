#include <vector>
#include <iostream>
#include <cmath> // For std::abs

struct rrlw_tbl {
    static const int ntbl = 10000;
    static constexpr double tblint = 10000.0;
    static constexpr double pade = 0.278;
    
    std::vector<double> tau_tbl;
    std::vector<double> exp_tbl;
    std::vector<double> tfn_tbl;
    
    double bpade = pade; // Initialize bpade with the value of pade

    rrlw_tbl() : tau_tbl(ntbl + 1), exp_tbl(ntbl + 1), tfn_tbl(ntbl + 1) {
        // Initialize vectors or other member variables if necessary
    }
};

// Simple function to test the initialization of bpade
bool test_bpade_initialization(const rrlw_tbl& table) {
    // Using a small epsilon for floating point comparison
    const double epsilon = 1e-7;
    return std::abs(table.bpade - rrlw_tbl::pade) < epsilon;
}

int main() {
    rrlw_tbl table;

    // Testing bpade initialization
    if (test_bpade_initialization(table)) {
        std::cout << "Test passed: bpade initialized correctly." << std::endl;
    } else {
        std::cout << "Test failed: bpade not initialized correctly." << std::endl;
    }

    return 0;
}