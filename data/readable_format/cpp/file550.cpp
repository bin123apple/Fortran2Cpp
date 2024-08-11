#include <iostream>
#include <string>
#include <vector>

int main() {
    const int N = 1; // Adjusted to match Fortran behavior
    std::vector<std::string> C(3, std::string(N, 'a')); // Adjusted to initialize strings with 'a'
    std::string D(N, 'a');

    for(const auto& str : C) {
        std::cout << str << std::endl; // Adjusted for matching output format
    }
    std::cout << D << std::endl;

    return 0;
}