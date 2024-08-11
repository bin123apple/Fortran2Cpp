// main.cpp
#include <iostream>
#include <string>
#include <cstdlib> // For std::abort

void perform_operations() {
    std::string a = "abcdefg";
    std::string b = "1234567";

    std::string* u = &a;
    std::string* v = &b;

    for (int j = 0; j < 2; ++j) {
        a[j] = b[j];
    }
    if (a != "12cdefg") std::abort();

    for (int j = 1; j < 3; ++j) {
        a[j] = (*v)[j];
    }
    if (a != "123defg") std::abort();

    for (int j = 2; j < 4; ++j) {
        (*u)[j] = b[j];
    }
    if (a != "1234efg") std::abort();

    for (int j = 3; j < 5; ++j) {
        (*u)[j] = (*v)[j];
    }
    if (a != "12345fg") std::abort();

    std::cout << "C++ Test Passed" << std::endl;
}

int main() {
    perform_operations();
    return 0;
}