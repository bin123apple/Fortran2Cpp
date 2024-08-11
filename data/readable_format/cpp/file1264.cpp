#include <iostream>

int main() {
    int i[2]; // In C++, array indices start from 0
    const int j = 1;
    i[0] = 1; // Adjusted for 0-based indexing
    i[j] = 2; // j already starts from 1, so it directly maps to the second element
    std::cout << i[0] << std::endl;
    std::cout << i[1] << std::endl;
    return 0;
}