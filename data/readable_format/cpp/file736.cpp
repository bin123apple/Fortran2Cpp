#include <iostream>
#include <vector>

// Define the FIND function
void FIND(const std::vector<int>& ibuffer, int ib, int nini, int ntot, int ip, int& iat) {
    int ipx = 0;
    // Note: Adjusting for C++ 0-based indexing in the loop
    for (iat = nini; iat < ntot; ++iat) {
        if (ibuffer[iat - 1] == ib) { // Adjusted index for 0-based array
            ++ipx;
            if (ip == ipx) {
                return; // Exiting the function if the condition is met
            }
        }
    }
}

int main() {
    std::vector<int> ibuffer = {1, 2, 3, 2, 1};
    int ib = 2;
    int nini = 1; // Starting index adjusted for 1-based to 0-based indexing
    int ntot = 5;
    int ip = 2;
    int iat = -1; // Initialize iat with an invalid index

    // Call the FIND function
    FIND(ibuffer, ib, nini, ntot, ip, iat);

    // Check the result
    // Note: Adjusting iat back to 1-based indexing for consistency with expectation
    if (iat == 4) { // Correct expectation based on 1-based indexing
        std::cout << "Test passed: iat is 4 as expected." << std::endl;
    } else {
        std::cout << "Test failed: iat is not 4." << std::endl;
    }

    return 0;
}