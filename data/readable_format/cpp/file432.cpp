#include <string> // Include the string library

int MDILNB(const std::string& chrs) {
    // Loop from the end of the string to the beginning
    for (int i = chrs.length() - 1; i >= 0; --i) {
        if (chrs[i] != ' ') { // Check if the character is not a space
            return i + 1; // Return position (1-based indexing, like Fortran)
        }
    }
    // If all characters are spaces or the string is empty,
    // the function returns 1, indicating no non-space character found.
    return 1;
}

// Example usage
#include <iostream>
int main() {
    std::string testString = "Hello World   ";
    int position = MDILNB(testString);
    std::cout << "Last non-space character is at position: " << position << std::endl;
    return 0;
}