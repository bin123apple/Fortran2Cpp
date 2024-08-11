#include <iostream>
#include <vector>

void threshold_image(const std::vector<std::vector<double>>& image, int n, double threshold, std::vector<std::vector<double>>& output) {
    std::cout << "Hello from the C++ function!" << std::endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (image[i][j] > threshold) {
                output[i][j] = 1.0;
            } else {
                output[i][j] = 0.0;
            }
        }
    }
}

int main() {
    int n = 3;
    double threshold = 0.5;
    
    std::vector<std::vector<double>> image = {
        {0.1, 0.6, 0.3},
        {0.7, 0.4, 0.8},
        {0.5, 0.2, 0.9}
    };
    std::vector<std::vector<double>> output(n, std::vector<double>(n, 0.0));
    
    threshold_image(image, n, threshold, output);
    
    std::cout << "Output image:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}