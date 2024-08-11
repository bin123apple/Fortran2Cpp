#include <iostream>
#include <sstream>
#include <string>

void sayHello() {
    std::cout << "Hello, World!" << std::endl;
}

void sayGoodbye() {
    std::cout << "Goodbye, World!" << std::endl;
}

void testHelloGoodbye() {
    sayHello();
    sayGoodbye();
}

int main() {
    testHelloGoodbye();
    return 0;
}