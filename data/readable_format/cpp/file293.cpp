#include <iostream>

// Define the great_ne function
void great_ne(int a, int b) {
    if (a != b) {
        std::cout << "great_ne: " << a << " and " << b << " are not equal." << std::endl;
    } else {
        std::cout << "great_ne: " << a << " and " << b << " are equal." << std::endl;
    }
}

// A simple test function that uses assertions for demonstration
void test_great_ne() {
    std::cout << "Testing great_ne:" << std::endl;

    // Example test case 1: Expect not equal
    std::cout << "Test case 1: ";
    great_ne(1, 2);

    // Example test case 2: Expect equal
    std::cout << "Test case 2: ";
    great_ne(2, 2);

    // Add more test cases as needed
    std::cout << "Testing completed." << std::endl;
}

int main() {
    // Run the test function
    test_great_ne();

    return 0;
}