#include <vector>

void movint(int nmov, const std::vector<int>& ifrom, std::vector<int>& ito) {
    for (int i = 0; i < nmov; ++i) {
        ito[i] = ifrom[i];
    }
}