#include <iostream>
#include <vector>
#include <cmath>

class Networks {
public:
    void normal(std::vector<std::vector<std::vector<double>>>& arr) {
        for (auto& plane : arr) {
            for (auto& row : plane) {
                for (auto& elem : row) {
                    if (elem != 0) {
                        elem = 1.0 / elem;
                    }
                }
            }
        }
    }

    double calc_distance(const std::vector<std::vector<double>>& laplacian, int node1, int node2) {
        if (node1 < 0 || node2 < 0 || node1 >= laplacian.size() || node2 >= laplacian[0].size()) {
            std::cerr << "Node index out of bounds" << std::endl;
            return -1.0; // Error code
        }
        return std::sqrt(std::abs(laplacian[node1][node2]));
    }
};

int main() {
    Networks networks;
    std::vector<std::vector<std::vector<double>>> arr = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    networks.normal(arr);
    std::cout << "After normalizing:" << std::endl;
    for (const auto& plane : arr) {
        for (const auto& row : plane) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "---" << std::endl;
    }

    std::vector<std::vector<double>> laplacian = {{0, 1}, {1, 0}};
    double dist = networks.calc_distance(laplacian, 0, 1);
    std::cout << "Distance between nodes 0 and 1: " << dist << std::endl;

    return 0;
}