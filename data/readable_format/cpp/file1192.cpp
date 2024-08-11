#include <cmath>    // For pow function
#include <cstdlib>  // For abort function

int main() {
    const int size = 2;
    float a[size];

    // Initialize the array
    for (int n = 1; n <= size; ++n) {
        a[n-1] = std::pow(static_cast<float>(n), 1.0f);
    }

    // Check if any element does not match the initialization criteria
    bool any_mismatch = false;
    for (int n = 1; n <= size; ++n) {
        if (a[n-1] != std::pow(static_cast<float>(n), 1.0f)) {
            any_mismatch = true;
            break;
        }
    }

    // If any element does not match, abort
    if (any_mismatch) {
        std::abort();
    }

    return 0;
}