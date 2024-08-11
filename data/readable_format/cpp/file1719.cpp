#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime> // For seeding rand()

template <typename T>
void initializeRandom(std::vector<std::vector<T>>& matrix) {
    for (auto& row : matrix) {
        for (auto& elem : row) {
            elem = static_cast<T>(rand()) / static_cast<T>(RAND_MAX);
        }
    }
}

template <typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// Assuming this is the translated gdmpgd function signature.
template <typename T>
void gdmpgd(std::vector<std::vector<T>>& R, const std::vector<std::vector<T>>& A, const std::vector<std::vector<T>>& B, T CON, int NI, int NJ, int NB) {
    // Function implementation here
    // Placeholder for the actual logic you've translated
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    int NI = 4, NJ = 4, NB = 1234;
    float CON = 1.5f;
    std::vector<std::vector<float>> R(NI, std::vector<float>(NJ)),
                                    A(NI, std::vector<float>(NJ)),
                                    B(NI, std::vector<float>(NJ));

    // Initialize matrices A and B with random values
    initializeRandom(A);
    initializeRandom(B);

    // Call the function
    gdmpgd(R, A, B, CON, NI, NJ, NB);

    // Print the result
    std::cout << "Result R:" << std::endl;
    printMatrix(R);

    return 0;
}