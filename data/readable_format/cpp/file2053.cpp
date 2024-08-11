#include <iostream> // Include the IOstream library for input and output operations
#include <string>   // Include the string library for using the string data type

int main() {
    // Declare variables equivalent to the Fortran program
    int i;       // 'integer' in Fortran is equivalent to 'int' in C++
    float x;     // 'real' in Fortran is often equivalent to 'float' in C++. If you need more precision, consider using 'double'.
    std::string str; // 'character(len=10)' in Fortran is replaced by 'std::string' in C++. std::string size is dynamic.

    // Example conversion within assignment
    i = 42;
    x = 3.14f;   // Note the 'f' suffix to explicitly define the literal as a float
    str = "Hello"; // In C++, strings are enclosed in double quotes

    // Print the variable values. In C++, we use 'std::cout' for outputting text to the console.
    std::cout << "Integer i = " << i << std::endl;
    std::cout << "Real x = " << x << std::endl;
    std::cout << "String str = " << str << std::endl;

    return 0; // Return statement indicating the program ended successfully
}