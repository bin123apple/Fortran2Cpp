#include <vector>

// Assuming DATA_TYPE is a placeholder for a specific type, we'll use int for simplicity.
// If DATA_TYPE is meant to be a floating-point type, use float or double instead.
void init_array(int length, std::vector<std::vector<int>>& c, std::vector<std::vector<double>>& w) {
    // Resize the vectors to length x length
    c.resize(length, std::vector<int>(length));
    w.resize(length, std::vector<double>(length));

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            c[j][i] = (i * j) % 2; // mod((i-1)*(j-1), 2) in Fortran is equivalent to (i * j) % 2 in C++
            w[j][i] = static_cast<double>(i - j) / static_cast<double>(length); // DBLE((i - 1) - (j - 1))) / DBLE(length) in Fortran is equivalent to the calculation directly in C++
        }
    }
}
