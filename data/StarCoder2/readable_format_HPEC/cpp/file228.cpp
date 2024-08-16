#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE corresponds to float and DATA_PRINTF_MODIFIER to "%f"
// You might need to adjust the type and format according to your actual use case.
void print_array(int maxgrid, float path[][maxgrid]) {
    // Set precision for floating-point output
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            std::cout << path[j][i] << " ";
            if ((i * maxgrid + j) % 20 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    const int maxgrid = 5;
    float path[maxgrid][maxgrid] = {
        {1.1f, 2.2f, 3.3f, 4.4f, 5.5f},
        {5.5f, 4.4f, 3.3f, 2.2f, 1.1f},
        {1.1f, 2.2f, 3.3f, 4.4f, 5.5f},
        {5.5f, 4.4f, 3.3f, 2.2f, 1.1f},
        {1.1f, 2.2f, 3.3f, 4.4f, 5.5f}
    };

    print_array(maxgrid, path);

    return 0;
}
