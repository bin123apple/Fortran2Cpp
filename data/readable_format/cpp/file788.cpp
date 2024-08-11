#include <iostream>
#include <vector>

// Define a template for a 2D vector
template<typename T>
using Matrix = std::vector<std::vector<T>>;

class TypeMod {
public:
    Matrix<float> vp, vs, ro;      // Elastic parameters
    Matrix<float> vpe, vse, roe;   // Elastic parameters in another domain
    Matrix<float> bux, buz;        // Buoyancy factors
    Matrix<float> mu0, mue;        // Shear moduli
    Matrix<float> lb0, lbmu;       // Lamé parameters
};

// Helper function to resize a 2D vector (Matrix)
template<typename T>
void resizeMatrix(Matrix<T>& mat, size_t rows, size_t cols, T initVal = T()) {
    mat.resize(rows);
    for (auto& row : mat) {
        row.resize(cols, initVal);
    }
}

int main() {
    TypeMod example;
    
    // Allocate and initialize arrays
    resizeMatrix(example.vp, 10, 10, 1.0f);
    resizeMatrix(example.vs, 10, 10);  // Default initialization
    resizeMatrix(example.ro, 10, 10);
    
    // Example usage: Print a value from vp
    std::cout << "vp(5,5) = " << example.vp[4][4] << std::endl;  // 0-based indexing in C++
    
    return 0;
}