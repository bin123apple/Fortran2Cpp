#include <iostream>
#include <random>
#include <vector>
#include <cassert>

// Function to generate random numbers
std::vector<float> generateRandomNumbers(size_t count) {
    std::vector<float> r(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (size_t i = 0; i < count; ++i) {
        r[i] = dis(gen);
    }

    return r;
}

// Simple test function to check if numbers are within range
void testRandomNumbers(const std::vector<float>& numbers) {
    for (auto num : numbers) {
        assert(num >= 0.0 && num <= 1.0); // Assert that each number is within the range [0, 1]
    }
}

int main() {
    // Generate 5 random numbers
    auto randomNumbers = generateRandomNumbers(5);

    // Test the generated random numbers
    testRandomNumbers(randomNumbers);

    // If the test passes, print the random numbers
    std::cout << "Generated random numbers (within the range [0, 1]):" << std::endl;
    for (auto num : randomNumbers) {
        std::cout << num << std::endl;
    }

    return 0;
}