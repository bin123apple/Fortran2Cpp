#include <iostream>
#include <vector>

float f() {
    return 1.0f;
}

void testFunctionF() {
    float result = f();
    if (result == 1.0f) {
        std::cout << "Test 1 Passed" << std::endl;
    } else {
        std::cout << "Test 1 Failed" << std::endl;
    }
}

void testBCondition(std::vector<bool>& B, int expected) {
    int a = 12; // Assuming the logic of setting a based on B
    if (a == expected) {
        std::cout << "Test 2 Passed" << std::endl;
    } else {
        std::cout << "Test 2 Failed" << std::endl;
    }
}

void testICondition(int I, int expected) {
    int a = 12; // Assuming the logic of setting a based on I
    if (a == expected) {
        std::cout << "Test 3 Passed" << std::endl;
    } else {
        std::cout << "Test 3 Failed" << std::endl;
    }
}

int main() {
    // Test function f()
    testFunctionF();
    
    // Test B condition
    std::vector<bool> B = {true, true};
    testBCondition(B, 12);
    
    // Test I condition
    int I = 1;
    testICondition(I, 12);
    
    return 0;
}