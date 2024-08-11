#include <iostream>
#include <string>

std::string getHelloWorld() {
    return "Hello, world!";
}

int main() {
    std::cout << getHelloWorld() << std::endl;
    return 0;
}