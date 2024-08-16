#include <iostream>
#include <vector>

// Assuming DATA_TYPE is a placeholder for the actual data type, e.g., double, float, etc.
// and DATA_PRINTF_MODIFIER is a format specifier for output, e.g., "%.2f" for floating-point numbers.
template<typename DATA_TYPE>
void print_array(int cz, int cxm, int cym, std::vector<std::vector<std::vector<DATA_TYPE>>> &bza,
                  std::vector<std::vector<std::vector<DATA_TYPE>>> &ex,
                  std::vector<std::vector<std::vector<DATA_TYPE>>> &ey,
                  std::vector<std::vector<std::vector<DATA_TYPE>>> &hz) {
    // Resize the 3D vectors to match the dimensions cxm + 1, cym + 1, cz + 1
    bza.resize(cxm + 1, std::vector<std::vector<DATA_TYPE>>(cym + 1, std::vector<DATA_TYPE>(cz + 1)));
    ex.resize(cxm + 1, std::vector<std::vector<DATA_TYPE>>(cym + 1, std::vector<DATA_TYPE>(cz + 1)));
    ey.resize(cxm + 1, std::vector<std::vector<DATA_TYPE>>(cym + 1, std::vector<DATA_TYPE>(cz + 1)));
    hz.resize(cxm + 1, std::vector<std::vector<DATA_TYPE>>(cym + 1, std::vector<DATA_TYPE>(cz + 1)));

    for (int i = 0; i < cz + 1; ++i) {
        for (int j = 0; j < cym + 1; ++j) {
            for (int k = 0; k < cxm + 1; ++k) {
                std::cout << DATA_PRINTF_MODIFIER << bza[k][j][i] << " "
                          << DATA_PRINTF_MODIFIER << ex[k][j][i] << " "
                          << DATA_PRINTF_MODIFIER << ey[k][j][i] << " "
                          << DATA_PRINTF_MODIFIER << hz[k][j][i] << std::endl;
                if ((i * cxm + j) % 20 == 0) {
                    std::cout << std::endl;
                }
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    int cz = 10, cxm = 20, cym = 30;
    std::vector<std::vector<std::vector<double>>> bza, ex, ey, hz;

    // Call the function with example data
    print_array<double>(cz, cxm, cym, bza, ex, ey, hz);

    return 0;
}
