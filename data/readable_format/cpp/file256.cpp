#include <vector>

// Assuming we want to use 'float' for REAL. Use 'double' if more precision is needed.
void instef(float effic, int xext, int yext, std::vector<std::vector<float>>& image) {
    // Note: C++ uses 0-based indexing
    for (int j = 0; j < yext; ++j) {
        for (int i = 0; i < xext; ++i) {
            image[i][j] = image[i][j] * effic;
        }
    }
}