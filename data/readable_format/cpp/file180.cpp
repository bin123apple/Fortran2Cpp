#include <iostream>
#include <vector>
#include <cmath> // For pow()

// Function prototype
void fsub(const std::vector<double>& x, int n, std::vector<double>& f);

int main() {
    std::vector<double> y = {2.0, 3.0, 7.0}; // Initialize vector y with values
    int n = y.size(); // Get the size of vector y
    std::vector<double> z(n); // Initialize vector z with the same size as y

    fsub(y, n, z); // Call the function to square each element

    // Print the results
    std::cout << "z = ";
    for (auto& elem : z) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Function to square each element of the input array
void fsub(const std::vector<double>& x, int n, std::vector<double>& f) {
    for (int i = 0; i < n; i++) {
        f[i] = std::pow(x[i], 2); // Square each element
    }
}