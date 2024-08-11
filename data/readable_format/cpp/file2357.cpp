#include <iostream>
#include <vector>

int main() {
    std::vector<float> vector(10);
    std::vector<float> subvector(5);

    // Initialize the vector with some values (optional, for demonstration)
    for (int i = 0; i < 10; ++i) {
        vector[i] = static_cast<float>(i + 1);  // Example initialization
    }

    // Assign every other element from vector to subvector
    for (int i = 0; i < 5; ++i) {
        subvector[i] = vector[i * 2];
    }

    // Print the subvectors to verify the result (optional)
    std::cout << "Subvector: ";
    for (const auto &val : subvector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}