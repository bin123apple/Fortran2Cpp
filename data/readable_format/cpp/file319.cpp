#include <iostream>
#include <cstdlib>

void testFunction() {
    int a = 42;
    if (a != 42) {
        std::cout << "Test failed." << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed." << std::endl;
    }
}

int main() {
    testFunction(); // Call the test function directly
    return 0;
}