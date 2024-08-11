#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using Tensor3D = std::vector<std::vector<std::vector<int>>>;

// Custom clamp function for compatibility
template<typename T>
T clamp(const T& val, const T& low, const T& high) {
    return std::max(low, std::min(val, high));
}

class Convolution {
public:
    void apply(Tensor3D& C) {
        int depth = C.size();
        int width = C[0].size();
        int height = C[0][0].size();

        Tensor3D C2 = C;

        std::vector<std::vector<int>> k = {
            {-4, -2, 0},
            {-2,  1, 2},
            { 0,  2, 4}
        };

        for (int o = 0; o < depth; ++o) {
            for (int j = 1; j < height - 1; ++j) {
                for (int i = 1; i < width - 1; ++i) {
                    int sum_k = std::accumulate(k.begin(), k.end(), 0,
                        [](int value, const std::vector<int>& vec) {
                            return value + std::accumulate(vec.begin(), vec.end(), 0);
                        });

                    if (sum_k != 0) {
                        int sum_c = 0;
                        for (int kj = 0; kj < 3; ++kj) {
                            for (int ki = 0; ki < 3; ++ki) {
                                sum_c += C[o][i + ki - 1][j + kj - 1] * k[ki][kj];
                            }
                        }
                        C2[o][i][j] = sum_c / sum_k;
                    }
                }
            }
        }

        C = C2;

        for (int o = 0; o < depth; ++o) {
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < height; ++j) {
                    C[o][i][j] = clamp(C[o][i][j], 0, 255);
                }
            }
        }
    }
};

void test_convolution() {
    Tensor3D C = {
        {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}},
        {{15, 25, 35}, {45, 55, 65}, {75, 85, 95}},
        {{20, 30, 40}, {50, 60, 70}, {80, 90, 100}}
    };

    Convolution conv;
    conv.apply(C);

    // Print the result for verification
    for (const auto& layer : C) {
        for (const auto& row : layer) {
            for (const auto& element : row) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    test_convolution();
    return 0;
}