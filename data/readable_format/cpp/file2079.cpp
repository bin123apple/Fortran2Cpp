#include <iostream>

// Function declaration and definition
int addNumbers(int a, int b) {
    return a + b;
}

// A simple "test" function
void testAddNumbers() {
    int result = addNumbers(2, 3);
    if (result == 5) {
        std::cout << "Test passed! Result = " << result << std::endl;
    } else {
        std::cout << "Test failed! Result = " << result << std::endl;
    }
}

int main() {
    // Call the test function within main
    testAddNumbers();
    return 0;
}