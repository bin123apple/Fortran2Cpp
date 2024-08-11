#include <iostream>

// Function declaration (optional in this context since the definition is before usage)
int add(int a, int b);

// Main function - the entry point of the C++ program
int main() {
    int a = 5;
    int b = 10;
    int sum = add(a, b);  // Using the add function
    
    std::cout << "The sum of " << a << " and " << b << " is " << sum << std::endl;
    
    // You can call other functions here as needed
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;  // Return the sum of a and b
}

// You can define more functions here