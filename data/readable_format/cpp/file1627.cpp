#include <vector>
#include <complex>

// Function prototype
void ZAdd(const std::vector<std::complex<double>>& A, 
          const std::vector<std::complex<double>>& B, 
          std::vector<std::complex<double>>& C, 
          int N);

// Function definition
void ZAdd(const std::vector<std::complex<double>>& A, 
          const std::vector<std::complex<double>>& B, 
          std::vector<std::complex<double>>& C, 
          int N) {
    for (int j = 0; j < N; j++) {
        C[j] = A[j] + B[j];
    }
}