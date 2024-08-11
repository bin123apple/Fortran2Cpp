#include <cmath> // For std::abs

float DM3(float x) {
    float M2m, M2;

    if (x >= 0.0f && x <= 2.0f) {
        M2m = 1.0f - std::abs(x - 1.0f);
    } else {
        M2m = 0.0f;
    }

    if (x >= 1.0f && x <= 3.0f) {
        M2 = 1.0f - std::abs(x - 2.0f);
    } else {
        M2 = 0.0f;
    }

    return M2m - M2;
}