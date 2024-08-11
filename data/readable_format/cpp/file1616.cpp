#include <iostream>
#include <cassert>

// Global counter
int counter = 0;

void work(int i, int j) {
    // Increment the counter when work is called
    ++counter;
}

void wrong1(int n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            work(i, j);
        }
    }
}

void resetCounter() {
    counter = 0;
}

int getCounter() {
    return counter;
}

void testWrong1(int n, int expected) {
    resetCounter();
    wrong1(n);
    assert(getCounter() == expected);
    std::cout << "C++ Test passed." << std::endl;
}

int main() {
    // Example test
    testWrong1(5, 25); // Since 5*5 = 25, expecting 25 calls to work
    return 0;
}