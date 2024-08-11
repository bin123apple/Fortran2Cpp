#include <iostream>
#include <vector>
#include <algorithm> // for std::min

namespace tao_random_numbers {
    std::vector<int> s_buffer(10);
    int s_last = s_buffer.size();
}

namespace linalg {
    std::vector<float> diag(const std::vector<std::vector<float>>& a) {
        std::vector<float> d(std::min(a.size(), a[0].size()));
        for (size_t i = 0; i < d.size(); ++i) {
            d[i] = a[i][i];
        }
        return d;
    }
}

int main() {
    using namespace tao_random_numbers;
    using namespace linalg;

    std::vector<std::vector<float>> x = { {1.0f, 2.0f}, {3.0f, 4.0f} };

    std::cout << s_last << std::endl;
    std::vector<float> diag_x = diag(x);
    for (float val : diag_x) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}