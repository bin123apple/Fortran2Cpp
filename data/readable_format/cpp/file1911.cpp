#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib> // for std::exit()

int main() {
    std::ostringstream oss;
    std::string s;

    // Test 1
    oss.str(""); // Clear the stream
    oss << "hello world";
    s = oss.str();
    if (s != "hello world") std::exit(1);

    // Test 2
    oss.str(""); // Clear the stream
    oss << std::setw(2) << "hello world";
    s = oss.str();
    if (s != "he") std::exit(2);

    // Test 3
    oss.str(""); // Clear the stream
    oss << std::setw(18) << std::left << "hello world";
    s = oss.str();
    // Correcting the padding issue to match Fortran behavior
    if (s != "hello world       ") std::exit(3);

    std::cout << "C++ Program Passed All Tests" << std::endl;

    return 0;
}