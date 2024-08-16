#include <iostream>
#include <iomanip> // For std::setprecision

// Assuming DATA_TYPE is a type alias for float or double, and N, M are constants representing the dimensions of the matrix.
// Adjust the precision of floating-point output if necessary.
template<typename DATA_TYPE>
void print_array(int m, DATA_TYPE** symmat) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setprecision(6) << symmat[j][i] << " "; // Adjust precision as needed
            if ((i * m) + j + 1 % 20 == 0) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    // Assuming N and M are defined somewhere
    const int N = 5; // Example size
    const int M = 5;

    // Allocate and initialize the symmetric matrix
    double** symmat = new double*[N];
    for (int i = 0; i < N; ++i) {
        symmat[i] = new double[M];
        for (int j = 0; j < M; ++j) {
            symmat[i][j] = i + j; // Example initialization
        }
    }

    // Print the matrix
    print_array(N, symmat);

    // Clean up
    for (int i = 0; i < N; ++i) {
        delete[] symmat[i];
    }
    delete[] symmat;

    return 0;
}
