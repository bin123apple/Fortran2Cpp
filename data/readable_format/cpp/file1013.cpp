#include <array>
#include <iostream>
#include <cassert>

class TArray {
private:
    std::array<float, 10> coeff; // Assuming 'real' translates to 'float' in C++. Adjust if necessary.

public:
    // Constructor (optional, in case you want to initialize coefficients)
    TArray() {
        // Initialize coefficients if necessary
        for (auto &c : coeff) c = 0.0f; // Example initialization
    }

    // Member function to get a copy of the coefficients array
    std::array<float, 10> getCoeff() const {
        return coeff;
    }

    // Setter function to modify coefficients
    void setCoeff(const std::array<float, 10>& newCoeff) {
        coeff = newCoeff;
    }

    float getCoeffAt(int index) const {
        // Add boundary check if necessary
        return coeff[index];
    }

    void setCoeffAt(int index, float value) {
        // Add boundary check if necessary
        coeff[index] = value;
    }
};

int main() {
    TArray myArray;
    
    // Test setting and getting an individual coefficient
    myArray.setCoeffAt(0, 5.0f); // Set first coefficient
    assert(myArray.getCoeffAt(0) == 5.0f); // Verify first coefficient

    std::cout << "Test passed: First coefficient is correctly set and retrieved." << std::endl;

    // Testing setting and getting the entire coefficients array
    std::array<float, 10> testCoeffs = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f};
    myArray.setCoeff(testCoeffs);
    auto coeffs = myArray.getCoeff();
    for (size_t i = 0; i < testCoeffs.size(); ++i) {
        assert(coeffs[i] == testCoeffs[i]);
    }

    std::cout << "Test passed: All coefficients are correctly set and retrieved." << std::endl;

    // Add additional tests as needed

    return 0;
}