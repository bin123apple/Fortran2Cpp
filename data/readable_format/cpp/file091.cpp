#include <iostream>

int add(int a, int b) {
    return a + b;
}

void testAddFunction() {
    if (add(5, 3) == 8) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    testAddFunction();
    return 0;
}