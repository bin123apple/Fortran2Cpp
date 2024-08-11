#include <iostream>

// Define the namespace to encapsulate the functionalities
namespace ppm_module_gmm_extend_fwd {

// Enumerations for dimension and precision, for illustrative purposes
enum Dimension {
    TwoD = 2,
    ThreeD = 3
};

enum Precision {
    Single = 1,
    Double = 2
};

// Template function declarations. In reality, you would adjust these based on actual requirements.
template<Dimension DIM, Precision KIND>
void ppm_gmm_extend_fwd(float input, float& output);

template<Dimension DIM, Precision KIND>
void ppm_gmm_extend_fwd(double input, double& output);

// Template specializations for the single precision, 2D case
template<>
void ppm_gmm_extend_fwd<TwoD, Single>(float input, float& output) {
    // Assuming a simple operation, for demonstration
    output = input + 1.0f;
}

// Template specializations for the double precision, 2D case
template<>
void ppm_gmm_extend_fwd<TwoD, Double>(double input, double& output) {
    // Assuming a simple operation, for demonstration
    output = input + 1.0;
}

// You can define other specializations as needed...

} // namespace ppm_module_gmm_extend_fwd

// Main function to demonstrate usage
int main() {
    float resultSingle = 0.0f;
    double resultDouble = 0.0;

    ppm_module_gmm_extend_fwd::ppm_gmm_extend_fwd<ppm_module_gmm_extend_fwd::TwoD, ppm_module_gmm_extend_fwd::Single>(1.0f, resultSingle);
    ppm_module_gmm_extend_fwd::ppm_gmm_extend_fwd<ppm_module_gmm_extend_fwd::TwoD, ppm_module_gmm_extend_fwd::Double>(1.0, resultDouble);

    std::cout << "Result (Single Precision, 2D): " << resultSingle << std::endl;
    std::cout << "Result (Double Precision, 2D): " << resultDouble << std::endl;

    return 0;
}