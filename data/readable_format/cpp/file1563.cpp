#include <iostream>
#include <cassert>

void printMessage() {
    std::cout << "This is a subroutine" << std::endl;
}

int doubleValue(int x) {
    return x * 2;
}

void testPrintMessage() {
    printMessage(); // Directly prints the message, not a 'test' per se.
}

void testDoubleValue() {
    assert(doubleValue(5) == 10);
    std::cout << "Test passed: doubleValue function works as expected." << std::endl;
}

int main() {
    testPrintMessage();
    testDoubleValue();
    return 0;
}