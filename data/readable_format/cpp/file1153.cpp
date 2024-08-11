#include <iostream>
#include <string>

int FirstNonChar(const std::string& str, char ch) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ch) {
            return i + 1; // Adjust for 1-based indexing to match Fortran behavior
        }
    }
    return 0;
}

int main() {
    std::cout << "Test 1 - Expected: 3, Got: " << FirstNonChar("aabacadae", 'a') << std::endl;
    std::cout << "Test 2 - Expected: 0, Got: " << FirstNonChar("aaaaaa", 'a') << std::endl;
    std::cout << "Test 3 - Expected: 0, Got: " << FirstNonChar("", 'a') << std::endl;
    std::cout << "Test 4 - Expected: 1, Got: " << FirstNonChar("bbbbbb", 'a') << std::endl;
    std::cout << "Test 5 - Expected: 0, Got: " << FirstNonChar("a", 'a') << std::endl;
    std::cout << "Test 6 - Expected: 1, Got: " << FirstNonChar("b", 'a') << std::endl;
    
    return 0;
}