#include <array>

// Assuming CLAENV is globally accessible
std::array<int, 100> IPARMS; // Global array to mimic COMMON block

void XLAENV(int ISPEC, int NVALUE) {
    // The global array IPARMS is directly accessible here.

    if (ISPEC >= 1 && ISPEC <= 9) {
        IPARMS[ISPEC - 1] = NVALUE; // Adjusted for 0-based indexing
    }
}

// Assuming you want to initialize the array or make it static to preserve its state
// across function calls without external linkage:
void initCLAENV() {
    // Potentially initialize IPARMS if needed, e.g., to zeroes
    IPARMS.fill(0);
}