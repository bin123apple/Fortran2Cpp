#include <iostream>
#include <string>

int main() {
    // Define and initialize the string
    std::string c = "Hello, "
                    "world!";
    
    // Check if the string is not equal to "Hello, world!"
    if (c != "Hello, world!") {
        // If not, exit the program with return code 1
        return 1;
    }

    return 0; // Successful execution
}