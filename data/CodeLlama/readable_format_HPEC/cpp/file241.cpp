#include <vector>
#include <iostream>

void init_array(int n, std::vector<std::vector<double>>& path) {
    // Resize the path array to have dimensions n x n
    path.resize(n, std::vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            path[j][i] = static_cast<double>(i * j + 1) / static_cast<double>(n);
        }
    }
}

int main() {
    int n = 4; // Example size
    std::vector<std::vector<double>> path;

    init_array(n, path);

    // Print the path array to verify the initialization
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << path[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
