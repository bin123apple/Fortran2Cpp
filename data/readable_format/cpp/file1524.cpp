#include <iostream>
#include <vector>

// Function to calculate the length of the Collatz sequence for a given number
long calculateCollatzLength(long n) {
    long length = 1; // Starting length is 1
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        ++length;
    }
    return length;
}

// Function for testing the calculateCollatzLength function
void testCalculateCollatzLength() {
    std::cout << "Running tests..." << std::endl;
    // Test 1: The length of the Collatz sequence for 13 should be 10
    if (calculateCollatzLength(13) == 10) {
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed." << std::endl;
    }

    // Add more tests as needed
}

int main() {
    const long MAX_NUM = 1000000;
    long numberWithLongestSequence = 0;
    long longestSequenceLength = 0;

    for (long n = 1; n <= MAX_NUM; ++n) {
        long currentLength = calculateCollatzLength(n);
        if (currentLength > longestSequenceLength) {
            longestSequenceLength = currentLength;
            numberWithLongestSequence = n;
        }
    }

    std::cout << "Number with the longest Collatz sequence is: " << numberWithLongestSequence
              << " with a sequence length of " << longestSequenceLength << std::endl;

    // Run tests
    testCalculateCollatzLength();

    return 0;
}