#include <iostream>
#include <string>

void test(std::string& s) {
    s = "Hello World";
}

int main() {
    std::string s(80, ' '); // Create a string of length 80 filled with spaces
    test(s);
    std::cout << s << std::endl; // This will print "Hello World"
    return 0;
}