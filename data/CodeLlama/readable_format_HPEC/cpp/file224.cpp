#include <vector>
#include <cmath>

void init_array(int length, std::vector<std::vector<int>>& c, std::vector<std::vector<double>>& w) {
    // Resize the vectors to have dimensions length x length
    c.resize(length, std::vector<int>(length));
    w.resize(length, std::vector<double>(length));

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            c[j][i] = (i * j) % 2; // Adjusted for 0-based indexing
            w[j][i] = static_cast<double>(i - j) / static_cast<double>(length); // Adjusted for 0-based indexing
        }
    }
}

int main() {
    int length = 5; // Example length
    std::vector<std::vector<int>> c;
    std::vector<std::vector<double>> w;

    init_array(length, c, w);

    // Optional: Print the arrays to verify the initialization
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << "c[" << i << "][" << j << "] = " << c[i][j] << ", ";
            std::cout << "w[" << i << "][" << j << "] = " << w[i][j] << std::endl;
        }
    }

    return 0;
}
