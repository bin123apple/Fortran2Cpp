#include <iostream>
#include <string>
#include <cstdlib> // For std::abort()

std::string test(int alen) {
    std::string result;
    for (int i = alen; i >= 1; --i) {
        result = "test";
        break; // Exit the loop after the first iteration
    }
    if (result.length() != 4) std::abort();
    if (result != "test") std::abort();
    return result;
}

std::string test2(int alen) {
    std::string result;
    for (int i = alen; i >= 1; --i) {
        result = "test";
        break; // Exit the loop after the first iteration
    }
    if (result.length() != 4) std::abort();
    if (result != "test") std::abort();
    return result;
}

int main() {
    std::string s;

    s = test(2);
    if (s.length() != 4) std::abort();
    if (s != "test") std::abort();

    s = test2(2);
    if (s.length() != 4) std::abort();
    if (s != "test") std::abort();

    return 0;
}