#include <iostream>
#include <string>
#include <cassert>

int nitems(const std::string& line) {
    int number = 0;
    int icount = 0;
    int lineLen = line.length();
    int icmax = line.length();

    while (icount < lineLen) {
        // If the current character is not a space or comma
        if (line[icount] != ' ' && line[icount] != ',') {
            number++; // Increment the count of items

            // Skip the current item until the next space, comma, or end of string
            while (icount < icmax && line[icount] != ' ' && line[icount] != ',') {
                icount++;
            }
        } else {
            icount++; // Move to the next character if the current one is a space or comma
        }
    }

    return number;
}

int main() {
    // Test cases
    assert(nitems("apple, orange, banana, peach") == 4);
    assert(nitems("  ") == 0);
    assert(nitems("apple orange banana") == 3);
    assert(nitems("") == 0);
    assert(nitems(" , , ,") == 0);
    assert(nitems("apple,orange,banana,peach") == 4);
    assert(nitems("    apple orange    banana   peach  ") == 4);

    std::cout << "All tests passed." << std::endl;
    return 0;
}