#include <iostream>

int main() {
    int seconds_in_a_day = 0;

    // In C++, line continuation for expressions doesn't require a special symbol.
    seconds_in_a_day = 24*60*60;
    std::cout << seconds_in_a_day << std::endl;

    // Similar to the above, just split across lines differently as an example.
    seconds_in_a_day = 24*60*60;
    std::cout << seconds_in_a_day << std::endl;

    // For long string literals, C++ allows string literal concatenation by breaking the string into parts.
    std::cout << "This is a really long string, that normally would not fit on a single line." << std::endl;

    return 0;
}