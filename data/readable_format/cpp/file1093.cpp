#include <vector>

int selci_isum(int n, const std::vector<std::vector<int>>& m) {
    int is = 0;
    for (int i = 0; i < n; ++i) {
        is += m[0][i]; // Adjusted index for C++ 0-based array
    }
    return is;
}