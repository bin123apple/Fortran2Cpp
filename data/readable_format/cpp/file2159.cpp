#include <iostream>
#include <vector>

int NWHSEL(int NPTIMS, const std::vector<int>& IPTIMS, const std::vector<bool>& WHOTIM) {
    int NWHSEL = 0;
    for (int I = 0; I < NPTIMS; ++I) {
        // Adjusted for 0-based indexing by subtracting 1 from IPTIMS[I]
        if (WHOTIM[IPTIMS[I] - 1]) {
            ++NWHSEL;
        }
    }
    return NWHSEL;
}

int main() {
    // Initialize test data
    int NPTIMS = 5;
    std::vector<int> IPTIMS = { 2, 4, 6, 8, 10 }; // Adjusted for 1-based indexing
    std::vector<bool> WHOTIM = { false, true, false, true, false, true, false, true, false, true };

    // Call the function
    int result = NWHSEL(NPTIMS, IPTIMS, WHOTIM);

    // Print the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}