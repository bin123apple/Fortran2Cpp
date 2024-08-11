#include <iostream>
#include <array>
#include <stdexcept>

// Define the template for a general 2x2 matrix inversion
template<typename T>
class MatrixInverter2x2 {
public:
    static std::array<std::array<T, 2>, 2> invert(const std::array<std::array<T, 2>, 2>& matrix) {
        T a = matrix[0][0];
        T b = matrix[0][1];
        T c = matrix[1][0];
        T d = matrix[1][1];
        
        T det = a * d - b * c;
        if (det == 0) {
            throw std::runtime_error("Matrix is singular and cannot be inverted.");
        }
        
        T invDet = 1 / det;
        
        return {{{d * invDet, -b * invDet},
                 {-c * invDet, a * invDet}}};
    }
};

// Example usage
int main() {
    try {
        std::array<std::array<float, 2>, 2> matrix_f = {{{1.0f, 2.0f}, {3.0f, 4.0f}}};
        auto inverted_f = MatrixInverter2x2<float>::invert(matrix_f);

        std::array<std::array<double, 2>, 2> matrix_d = {{{1.0, 2.0}, {3.0, 4.0}}};
        auto inverted_d = MatrixInverter2x2<double>::invert(matrix_d);

        std::cout << "Inverted float matrix: [[" << inverted_f[0][0] << ", " << inverted_f[0][1] << "], [" 
                  << inverted_f[1][0] << ", " << inverted_f[1][1] << "]]" << std::endl;

        std::cout << "Inverted double matrix: [[" << inverted_d[0][0] << ", " << inverted_d[0][1] << "], [" 
                  << inverted_d[1][0] << ", " << inverted_d[1][1] << "]]" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}