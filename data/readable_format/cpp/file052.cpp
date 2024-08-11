#include <cmath> // For std::abs

bool gtabs_int(int x, int y) {
    bool ordered;
    if (std::abs(x) > std::abs(y)) {
        ordered = true;
    } else {
        ordered = false;
    }
    return ordered;
}