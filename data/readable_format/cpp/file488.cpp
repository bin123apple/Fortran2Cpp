#include <vector>

void lookup_shell(const std::vector<int>& table, int a, int& m) {
    int nshells = table.size();

    for(int i = 0; i < nshells; ++i) {
        if(table[i] >= a) {
            m = i + 1; // Adjust to 1-based indexing for consistency with Fortran code
            return;
        }
    }

    m = nshells; // Adjust to 1-based indexing for consistency with Fortran code
}