#include <iostream>
#include <sstream>
#include <array>
#include <cstdlib>
#include <iomanip>

// Equivalent to the Fortran module and function `bar` translated into C++
class Foo {
public:
    static std::array<int, 3> bar(int arg) {
        return {arg, arg + 1, arg + 2};
    }
};

// A simple test function
void testBarFunction() {
    auto result = Foo::bar(5);
    if (result[0] == 5 && result[1] == 6 && result[2] == 7) {
        std::cout << "Test for bar function passed." << std::endl;
    } else {
        std::cerr << "Test for bar function failed." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

int main() {
    // Run the test for the bar function
    testBarFunction();

    // The rest of your program can go here.
    // For demonstration, let's just print something.
    std::cout << "All tests passed. Demonstrating additional functionality:" << std::endl;

    std::array<std::array<float, 3>, 3> d;
    std::array<int, 3> barResult = Foo::bar(5);
    std::cout << "Result of Foo::bar(5): ";
    for (int i : barResult) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}