#include <iostream>
#include <string>

int main() {
    std::string s = "abcd";
    bool b = !s.empty(); // This will be true if s is non-empty, which is always the case here

    std::cout << std::boolalpha << b << std::endl; // This will print 'true'
    
    return 0;
}