#include <cctype> // For std::tolower

int char2type(char character) {
    switch (std::tolower(character)) { // Convert character to lowercase to simplify comparison
        case 'e':
            return 1;
        default:
            return -1234;
    }
}