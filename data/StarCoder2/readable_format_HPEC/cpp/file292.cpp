#include <vector>

// Assuming DATA_TYPE is double for this example
using DATA_TYPE = double;

void kernel_trmm(int ni, DATA_TYPE alpha, std::vector<std::vector<DATA_TYPE>>& a, std::vector<std::vector<DATA_TYPE>>& b) {
    // Assuming the size of a and b is ni x ni
    // Note: In C++, vectors are 0-based, so the loop indices start from 1 and go to ni - 1
    for (int i = 1; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            for (int k = 0; k < i; ++k) {
                b[j][i] += alpha * a[k][i] * b[k][j];
            }
        }
    }
}

int main() {
    // Example usage
    int ni = 4; // Matrix size
    DATA_TYPE alpha = 1.0; // Scalar value

    // Initialize matrices a and b
    std::vector<std::vector<DATA_TYPE>> a(ni, std::vector<DATA_TYPE>(ni));
    std::vector<std::vector<DATA_TYPE>> b(ni, std::vector<DATA_TYPE>(ni));

    // Populate matrices a and b with some values
    // For simplicity, let's just fill them with 1.0
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            a[i][j] = 1.0;
            b[i][j] = 1.0;
        }
    }

    // Call the function
    kernel_trmm(ni, alpha, a, b);

    // Output the result for verification
    for (int i = 0; i < ni; ++i) {
        for (int j = 0; j < ni; ++j) {
            std::cout << "b[" << i << "][" << j << "] = " << b[i][j] << std::endl;
        }
    }

    return 0;
}
