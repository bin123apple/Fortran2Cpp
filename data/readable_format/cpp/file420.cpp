// Include header for input/output operations
#include <iostream>

// Function prototype
void GRFLUN(int& LUN);

// Main function
int main() {
    int LUN = 5; // Example initialization
    GRFLUN(LUN); // Call the function
    std::cout << "LUN after GRFLUN: " << LUN << std::endl; // Display the result
    return 0;
}

// Function definition
void GRFLUN(int& LUN) {
    LUN = 0;
}