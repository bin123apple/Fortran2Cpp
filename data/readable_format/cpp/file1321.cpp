#include <iostream>
#include <vector>
#include <string>

// Function prototype
void S(std::vector<std::string>& x);

int main() {
    std::vector<std::string> X1;
    
    // Example initialization - assuming you want to demonstrate usage.
    // In a real scenario, you might populate X1 with actual data.
    X1.push_back("String 1");
    X1.push_back("String 2");

    // Call the function with the vector
    S(X1);

    return 0;
}

// Function definition that mimics the SUBROUTINE S from Fortran
void S(std::vector<std::string>& x) {
    // Example action - print the strings to demonstrate the function works
    for (const auto& str : x) {
        std::cout << str << std::endl;
    }
}