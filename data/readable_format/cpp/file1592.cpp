#include <cassert>
#include <iostream>
#include <string>

int LastNonChar(const std::string& str, char ch) {
    int lastNonChar = str.length(); // Adjust for 0-based indexing in C++
    while (lastNonChar > 0) {
        if (str[lastNonChar - 1] != ch) return lastNonChar; // Return 1-based index
        --lastNonChar;
    }
    return 0; // If character not found or string is empty
}

int main() {
    // Test 1: Specified character is at the end of the string
    assert(LastNonChar("hello world!", '!') == 11);

    // Test 2: Specified character is not in the string
    assert(LastNonChar("hello world", 'x') == 11);

    // Test 3: String contains only the specified character
    assert(LastNonChar("aaaaa", 'a') == 0);

    // Test 4: String is empty
    assert(LastNonChar("", 'z') == 0);

    std::cout << "All tests passed successfully." << std::endl;

    return 0;
}