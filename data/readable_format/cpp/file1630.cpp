#include <iostream>
#include <string>
#include <cassert>

void foo(int i) {
    std::string s = "Hello"; // Simplified operation
    std::cout << "Function foo called with i = " << i << ". String length: " << s.length() << std::endl;
}

int main() {
    foo(10); // Example call
    return 0;
}