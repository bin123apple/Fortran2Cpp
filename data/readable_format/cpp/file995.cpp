#include <vector>

void V7CPY(int P, std::vector<float>& Y, const std::vector<float>& X) {
    for (int i = 0; i < P; ++i) {
        Y[i] = X[i];
    }
}