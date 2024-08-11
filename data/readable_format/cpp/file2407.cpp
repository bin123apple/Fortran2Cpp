#include <iostream>

void performTest(bool la, bool lb) {
    if (la == lb) {
        std::cout << "la == lb is true" << std::endl;
    }
    if (la != lb) {
        std::cout << "la != lb is true" << std::endl;
    }
    if (la && lb) {
        std::cout << "la && lb is true" << std::endl;
    }
    if (la || lb) {
        std::cout << "la || lb is true" << std::endl;
    }
    if (!la) {
        std::cout << "!la is true" << std::endl;
    }
}

int main() {
    // Test case 1: la and lb are both true
    bool la = true;
    bool lb = true;
    std::cout << "Test case 1: la and lb are both TRUE" << std::endl;
    performTest(la, lb);

    // Test case 2: la is true, lb is false
    la = true;
    lb = false;
    std::cout << "Test case 2: la is TRUE, lb is FALSE" << std::endl;
    performTest(la, lb);

    return 0;
}