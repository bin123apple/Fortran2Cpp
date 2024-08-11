#include <algorithm>  // For std::max

// Assuming these constants are defined somewhere in the included Fortran files
const int max_aes = 100;  // Example value, replace with actual value from control_tables.inc
const int max_spac = 50;  // Example value, replace with actual value from control_tab_v1.inc

// Function equivalent to the Fortran subroutine
void enq_v1_teldef(int& nae_max, int& nsp_max, int& nba_max, int& nch_max, int s) {
    // If s is not 0, return immediately
    if (s != 0) return;

    // Set the maximum values
    nae_max = max_aes;
    nsp_max = max_spac;
    nba_max = 1;
    nch_max = 1;
}

int main() {
    int nae_max, nsp_max, nba_max, nch_max;
    int s = 0;  // Example value for s

    enq_v1_teldef(nae_max, nsp_max, nba_max, nch_max, s);

    // Output the values to verify
    std::cout << "nae_max: " << nae_max << std::endl;
    std::cout << "nsp_max: " << nsp_max << std::endl;
    std::cout << "nba_max: " << nba_max << std::endl;
    std::cout << "nch_max: " << nch_max << std::endl;

    return 0;
}