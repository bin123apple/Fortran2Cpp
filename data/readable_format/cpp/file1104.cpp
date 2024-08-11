#include <iostream>
#include <random>

int main() {
    const int size = 123;
    float array[size];
    
    // Create a random number generator and distribution
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_real_distribution<> distr(0.0, 1.0); // Define the range
    
    // Initialize the array with random numbers
    for (int i = 0; i < size; ++i) {
        array[i] = distr(gen);
    }

    // Optionally, print the array to verify (comment out if not needed)
    // for (int i = 0; i < size; ++i) {
    //     std::cout << array[i] << std::endl;
    // }

    return 0;
}