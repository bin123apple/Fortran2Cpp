#include <vector>

class ZeroMatrix {
public:
    // Function to set a matrix of size MxM to zero
    void zerom(int M, std::vector<std::vector<double>>& X) {
        // Resize the matrix to MxM
        X.resize(M);
        for (int i = 0; i < M; ++i) {
            X[i].resize(M);
        }

        // Set all elements to zero
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                X[i][j] = 0.0;
            }
        }
    }
};

// Example usage
int main() {
    int M = 5; // Example size
    std::vector<std::vector<double>> X;

    ZeroMatrix zm;
    zm.zerom(M, X);

    // Print the matrix to verify
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << X[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}