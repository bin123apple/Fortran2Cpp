#include <iostream>
#include <string>
#include <cstdlib>

const std::string chrs = "-+.0123456789eEdD";
const std::string expr = "-+.0123456789eEdD";

int index(const std::string& str, const std::string& chars) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (chars.find(str[i]) != std::string::npos) {
            return static_cast<int>(i) + 1; // Fortran indices start at 1
        }
    }
    return 0; // If none of the characters are found
}

int foo(const std::string& expr) {
    return index(chrs, expr);
}

void bar(const std::string& expr) {
    if (index(chrs, expr) != 1) std::abort();
}

void test_index() {
    if (index(chrs, expr) != 1) std::abort();
}

void test_foo() {
    if (foo(expr) != 1) std::abort();
}

int main() {
    test_index();
    test_foo();
    bar(expr);

    std::cout << "All C++ tests passed." << std::endl;
    return 0;
}