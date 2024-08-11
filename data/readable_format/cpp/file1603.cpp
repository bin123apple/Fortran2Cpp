#include <iostream>
#include <cstring>
#include <cstdlib>

// Function declarations
void foo(char cc1[]);
void sfoo(char* sc1);
void afoo(char (*ac1)[5]);

// Simple test function declarations
void testFoo();
void testSfoo();
void testAfoo();

int main() {
    // Run tests
    testFoo();
    testSfoo();
    testAfoo();
    std::cout << "All tests passed." << std::endl;
    return 0;
}

// Function implementations
void foo(char cc1[]) {
    if (std::strcmp(cc1, "wxyz") != 0) std::abort();
}

void sfoo(char* sc1) {
    if (std::strcmp(sc1, "wxyz") != 0) std::abort();
}

void afoo(char (*ac1)[5]) {
    if (std::strcmp(ac1[0], "wxyz") != 0) std::abort();
}

// Test implementations
void testFoo() {
    char testInput1[5] = "wxyz";
    foo(testInput1);
}

void testSfoo() {
    char* testInput2 = new char[5];
    std::strcpy(testInput2, "wxyz");
    sfoo(testInput2);
    delete[] testInput2;
}

void testAfoo() {
    char (*testInput3)[5] = new char[1][5];
    std::strcpy(testInput3[0], "wxyz");
    afoo(testInput3);
    delete[] testInput3;
}