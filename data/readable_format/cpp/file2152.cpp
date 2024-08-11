#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath> // For checking overflows

class DotProduct {
public:
    static bool matrix_error;

    static double dot(const std::vector<double>& A, const std::vector<double>& B) {
        if (A.size() != B.size()) {
            matrix_error = true;
            throw std::invalid_argument("Vectors must be of the same size.");
        }

        double result = 0.0;
        for (size_t i = 0; i < A.size(); ++i) {
            double product = A[i] * B[i];
            if (std::isinf(product)) {
                matrix_error = true;
                throw std::overflow_error("Overflow occurred during multiplication.");
            }
            result += product;
            if (std::isinf(result)) {
                matrix_error = true;
                throw std::overflow_error("Overflow occurred during accumulation.");
            }
        }

        return result;
    }
};

bool DotProduct::matrix_error = false;

int main() {
    try {
        std::vector<double> A = {1.0, 2.0, 3.0};
        std::vector<double> B = {4.0, 5.0, 6.0};
        
        double result = DotProduct::dot(A, B);
        std::cout << "Dot product: " << result << std::endl;
        
        if (DotProduct::matrix_error) {
            std::cerr << "An error occurred during the dot product calculation." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}