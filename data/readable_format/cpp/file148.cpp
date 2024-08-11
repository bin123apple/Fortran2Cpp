#include <iostream>
#include <cmath>
#include <functional>
#include <array>

// Define a class to encapsulate the procedure pointer
class ProcPointerType {
public:
    // Using std::function to store a pointer to a function that matches the signature of `triple`
    std::function<std::array<float, 2>(int, std::array<float, 2>)> f;

    // Constructor
    ProcPointerType() {}

    // Method to assign a function to the pointer
    void assign(std::function<std::array<float, 2>(int, std::array<float, 2>)> func) {
        f = func;
    }
};

// Function matching the Fortran `triple` function
std::array<float, 2> triple(int n, std::array<float, 2> x) {
    return {3.0f * x[0], 3.0f * x[1]};
}

int main() {
    ProcPointerType ppt;
    std::array<float, 2> tres;

    // Assigning the `triple` function to the procedure pointer
    ppt.assign(triple);

    // Using the assigned function
    tres = ppt.f(2, {2.0f, 4.0f});
    if (std::abs(tres[0] - 6.0f) > 1E-3 || std::abs(tres[1] - 12.0f) > 1E-3) {
        std::cerr << "First test failed." << std::endl;
        return 1;
    }

    tres = ppt.f(2, {3.0f, 5.0f});
    if (std::abs(tres[0] - 9.0f) > 1E-3 || std::abs(tres[1] - 15.0f) > 1E-3) {
        std::cerr << "Second test failed." << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}