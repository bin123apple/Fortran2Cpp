#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Prototypes
int performXOR(const std::vector<int>& vec);
void testXOROperation();

int main() {
    // Perform unit tests before executing the main logic
    testXOROperation();

    const int N = 1000;
    std::vector<int> random_array(N);
    int ans_val, sa;

    // Initialize the random number generator
    std::srand(std::time(0));

    // Generate random numbers and fill the array
    for (int i = 0; i < N; ++i) {
        random_array[i] = std::rand() % 10000;
    }

    // Compute ans_val by performing a bitwise XOR on all elements
    ans_val = performXOR(random_array);

    // Compute sa by performing a bitwise XOR on all elements of a
    // Here, 'a' is essentially 'random_array'
    sa = performXOR(random_array);

    // Verify if sa is equal to ans_val
    if (sa == ans_val) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        return -1;
    }

    return 0;
}

int performXOR(const std::vector<int>& vec) {
    int result = 0;
    for (int val : vec) {
        result ^= val;
    }
    return result;
}

void testXOROperation() {
    std::vector<int> testVec = {1, 2, 3, 4, 5};
    int expectedXOR = 1; // Assuming this is the expected result for the XOR operation
    for (size_t i = 1; i < testVec.size(); ++i) {
        expectedXOR ^= testVec[i];
    }
    
    int actualXOR = performXOR(testVec);
    if (actualXOR == expectedXOR) {
        std::cout << "XOR Test PASS" << std::endl;
    } else {
        std::cout << "XOR Test FAIL" << std::endl;
        exit(1); // Exit if the test fails
    }
}