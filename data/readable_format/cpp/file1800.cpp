#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);
    if (result == 8) {
        std::cout << "C++ Test passed." << std::endl;
    } else {
        std::cout << "C++ Test failed." << std::endl;
    }
    return 0;
}