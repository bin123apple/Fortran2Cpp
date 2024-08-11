#include <array>

void pr94329(float& s, std::array<std::array<float, 3>, 3>& t) {
    for (int i = 0; i < 3; i++) { // Adjusting for 0-indexing in C++
        for (int j = 0; j < 3; j++) {
            s = t[i][j];
        }
    }
}