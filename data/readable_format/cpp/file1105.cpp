#include <vector>

void IZERO(std::vector<int>& ivec) {
    if (ivec.size() < 1) return;
    for (size_t i = 0; i < ivec.size(); ++i) {
        ivec[i] = 0;
    }
}