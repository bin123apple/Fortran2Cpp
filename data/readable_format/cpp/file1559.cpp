#include <iostream>

struct t {
    char c;
    // Constructor for easy initialization of 'c'
    t(char ch) : c(ch) {}
};

int main() {
    // Initialize x with 'a' using the constructor of struct t
    t typeInstance('a'); // Creating an instance of t initialized with 'a'
    char x = typeInstance.c; // Assuming the intent was to use the character from the type
    
    // Then, assigning 'b' to x, overriding the previous value
    x = 'b';

    // Demonstrating the value of x
    std::cout << x << std::endl;

    return 0;
}