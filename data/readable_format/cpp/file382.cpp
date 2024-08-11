#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

// Generate a vector of random integers between 0 and 9999
std::vector<int> generateRandomArray(int size) {
    std::vector<int> array(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9999);

    for(int& value : array) {
        value = distrib(gen);
    }

    return array;
}

// Compute the XOR of all elements in the vector
int computeXor(const std::vector<int>& array) {
    int result = 0;
    for(int value : array) {
        result ^= value;
    }
    return result;
}

// Simple "test" function to verify the XOR operation
void testXorOperation() {
    std::vector<int> testArray = {1, 2, 3, 4, 5};
    int expectedXor = 1^2^3^4^5;
    int computedXor = computeXor(testArray);

    if(computedXor == expectedXor) {
        std::cout << "XOR Test Passed." << std::endl; // Corrected line
    } else {
        std::cout << "XOR Test Failed." << std::endl; // Corrected line
    }
}

int main() {
    // Generating a random array and computing its XOR
    auto randomArray = generateRandomArray(10);
    int xorResult = computeXor(randomArray);

    std::cout << "Generated Random Array: ";
    for(int value : randomArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl; // Corrected line
    std::cout << "XOR Result: " << xorResult << std::endl; // Corrected line

    // Performing a simple test
    testXorOperation();

    return 0;
}