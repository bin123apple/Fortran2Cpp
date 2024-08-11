#include <iostream>
#include <vector>
#include <cassert>

// Assuming DOUBLE corresponds to double in C++
using DOUBLE = double;

// A simple example of the hmuf function to be tested.
void hmuf(std::vector<std::vector<DOUBLE>>& H1, int ID, const std::vector<std::vector<DOUBLE>>& COORD, 
          const std::vector<int>& NFIRST, const std::vector<int>& NLAST, const std::vector<int>& NAT, 
          int NORBS, int NUMAT) {
    // Example logic: Just modifies H1 based on ID for demonstration.
    for (auto& row : H1) {
        for (auto& val : row) {
            val += ID; // Simple operation for demonstration.
        }
    }
}

void test_hmuf() {
    int NORBS = 2, NUMAT = 3;
    std::vector<std::vector<DOUBLE>> H1(NORBS, std::vector<DOUBLE>(NORBS, 0.0));
    std::vector<std::vector<DOUBLE>> COORD = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<int> NFIRST = {1, 2, 3}, NLAST = {2, 3, 4}, NAT = {1, 1, 1};
    int ID = 1;

    // Assume hmuf modifies H1 in a predictable way, for example, sets all elements to the sum of ID and the size of NAT
    DOUBLE expected_value = ID; // Adjusted for the simple hmuf logic provided.

    hmuf(H1, ID, COORD, NFIRST, NLAST, NAT, NORBS, NUMAT);

    // Verify that H1 has been modified as expected
    for (const auto &row : H1) {
        for (DOUBLE val : row) {
            assert(val == expected_value);
        }
    }

    std::cout << "C++ hmuf test passed." << std::endl;
}

int main() {
    test_hmuf();
    return 0;
}