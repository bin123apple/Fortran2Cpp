#include <iostream>

// Equivalent of the Fortran module 'truc' using a namespace.
namespace truc {
    // Equivalent of the Fortran parameter 'answer'.
    const int answer = 42;
}

int main() {
    // Equivalent of the Fortran 'print' statement.
    std::cout << "hello there" << std::endl;

    // This line is just to show how you might use the 'answer' from the 'truc' namespace,
    // similar to how you might use it in Fortran if it were referenced in the 'test' program.
    std::cout << "The answer is: " << truc::answer << std::endl;

    return 0;
}