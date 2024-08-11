#include <iostream>
#include <cstdlib>
#include <ctime>

class RandomICMod {
public:
    RandomICMod() {
        // Use current time as seed for random generator
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    double generateRandom() const {
        return static_cast<double>(std::rand()) / RAND_MAX;
    }
};

int main() {
    RandomICMod randomGenerator;
    double randomNumber = randomGenerator.generateRandom();

    std::cout << "Generated random value: " << randomNumber << std::endl;

    // Basic "test" to check if the random value is within the expected range
    if (randomNumber >= 0.0 && randomNumber <= 1.0) {
        std::cout << "Test passed: Random number is within the expected range [0, 1]." << std::endl;
    } else {
        std::cout << "Test failed: Random number is outside the expected range [0, 1]." << std::endl;
    }

    return 0;
}