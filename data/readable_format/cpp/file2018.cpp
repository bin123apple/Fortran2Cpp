#include <vector>
#include <cmath>

float FPOLY(int NDEG, const std::vector<float>& COEFF, float X) {
    double DSUM = static_cast<double>(COEFF[NDEG]); // Adjust for zero-based indexing
    if (NDEG > 0) {
        for (int K = NDEG - 1; K >= 0; --K) { // Adjust loop for zero-based indexing
            DSUM = DSUM * static_cast<double>(X) + static_cast<double>(COEFF[K]);
        }
    }
    return static_cast<float>(DSUM);
}