#include <complex> // For std::complex

class basics_t {
public:
    int i = 42; // Default value for i
    float r = 0.0f; // Assuming REAL in Fortran corresponds to float in C++
    std::complex<float> c = {0.0f, 1.0f}; // Default value for c

    // Constructor with default values
    basics_t(int i = 42, float r = 0.0f, std::complex<float> c = {0.0f, 1.0f})
        : i(i), r(r), c(c) {}
};

int main() {
    basics_t basics; // Default constructor uses the specified default values
    basics = basics_t(42); // Uses the constructor, but only changes 'i'
    
    return 0;
}