#include <iostream>
#include <array>

using DP = double; // Define DP as double

// Assuming the recips function signature and adjusting it for C++
void recips(std::array<DP, 3>& a1, std::array<DP, 3>& a2, std::array<DP, 3>& a3, 
            std::array<DP, 3>& b1, std::array<DP, 3>& b2, std::array<DP, 3>& b3) {
    DP den = 0.0;
    int i = 0; // Adjusted for 0-based indexing
    int j = 1;
    int k = 2;
    DP s = 1.0;
    
    for (int iperm = 0; iperm < 3; ++iperm) { // Adjusted loop for 0-based indexing
        den += s * a1[i] * a2[j] * a3[k];
        int l = i;
        i = j;
        j = k;
        k = l;
    }
    
    i = 1; // Adjusted for the next segment
    j = 0;
    k = 2;
    s = -s;
    if (s < 0.0) {
        // Repeating the block as the goto has been removed
        for (int iperm = 0; iperm < 3; ++iperm) { // Adjusted loop for 0-based indexing
            den += s * a1[i] * a2[j] * a3[k];
            int l = i;
            i = j;
            j = k;
            k = l;
        }
    }
    
    i = 0; // Resetting i, j, k for the final computation
    j = 1;
    k = 2;
    for (int ipol = 0; ipol < 3; ++ipol) { // Adjusted loop for 0-based indexing
        b1[ipol] = (a2[j] * a3[k] - a2[k] * a3[j]) / den;
        b2[ipol] = (a3[j] * a1[k] - a3[k] * a1[j]) / den;
        b3[ipol] = (a1[j] * a2[k] - a1[k] * a2[j]) / den;
        int l = i;
        i = j;
        j = k;
        k = l;
    }
}

void test_recips() {
    std::array<DP, 3> a1 = {1.0, 2.0, 3.0};
    std::array<DP, 3> a2 = {4.0, 5.0, 6.0};
    std::array<DP, 3> a3 = {7.0, 8.0, 9.0};
    std::array<DP, 3> b1, b2, b3;

    recips(a1, a2, a3, b1, b2, b3);

    std::cout << "b1: ";
    for (const auto& val : b1) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "b2: ";
    for (const auto& val : b2) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "b3: ";
    for (const auto& val : b3) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    test_recips();
    return 0;
}