#include <iostream>
#include <array>
#include <stdexcept>

// Define the_distribution type
struct the_distribution {
    std::array<int, 2> parameters;
};

// Define the_beta constant
const the_distribution the_beta = {{99, 999}};

// Function to set bound
void set_bound(int arg_name, int test) {
    if (arg_name != test) {
        throw std::runtime_error("Error: Bound check failed.");
    }
}

// Function cdf_beta
void cdf_beta(int which, int test) {
    set_bound(the_beta.parameters[which - 1], test);  // Adjust for 0-based index in C++
}

int main() {
    try {
        cdf_beta(1, 99);
        cdf_beta(2, 999);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}