#include <string>
#include <iostream>

void foo(std::string& a, int n) {
    // Resize the string to n + 5 as specified in the Fortran code
    a.resize(n + 5);
    // Optionally, initialize or modify the string here
    // For demonstration, let's fill it with a specific character
    std::fill(a.begin(), a.end(), 'x');
}

int main() {
    std::string str;
    int n = 10; // Example size
    foo(str, n);
    std::cout << "Resulting string: " << str << std::endl;
    return 0;
}