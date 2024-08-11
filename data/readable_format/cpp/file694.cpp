#include <algorithm> // For std::min and std::max

void qqqmima(const float* fld, int n, float& xmin, float& xmax) {
    // Assuming the array is not empty and n > 0.
    float xxmin = fld[0]; // Note: Arrays in C++ are 0-indexed
    float xxmax = fld[0];

    for (int i = 1; i < n; ++i) { // Loop starts from 1 since we already used the first element
        xxmin = std::min(fld[i], xxmin);
        xxmax = std::max(fld[i], xxmax);
    }

    xmin = xxmin;
    xmax = xxmax;
}