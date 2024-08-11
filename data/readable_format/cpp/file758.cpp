#include <iostream>
#include <string>
#include <cstdlib> // For std::exit

// Define the 'error' function directly in this file
void error(const std::string& function_name, const std::string& message, double value, int level) {
    if (level < 1 || level > 3) {
        std::cerr << "*** Error in Subroutine error:" << std::endl;
        std::cerr << "*** Message: Wrong Errorlevel" << std::endl;
        std::cerr << "*** Related Value: " << level << std::endl;
    }

    if (level == 1) {
        std::cerr << "*** Warning in Subroutine " << function_name << ":" << std::endl;
    } else if (level == 2) {
        std::cerr << "*** Error in Subroutine " << function_name << ":" << std::endl;
    } else if (level == 3) {
        std::cerr << "*** Fatal Error in Subroutine " << function_name << ":" << std::endl;
    }
    std::cerr << "*** Message: " << message << std::endl;
    std::cerr << "*** Related Value: " << value << std::endl;

    if (level >= 3) {
        std::cerr << "*** Program stopped." << std::endl;
        std::exit(137);
    }
}

// Main function to demonstrate the error function usage
int main() {
    // Demonstrate the usage of the 'error' function
    error("testFunc1", "This is a warning message.", 1.0, 1);
    error("testFunc2", "This is an error message.", 2.0, 2);

    // Note: Calling the 'error' function with level 3 will cause the program to terminate due to std::exit(137)
    // Uncomment the line below to test the behavior with a fatal error level (the program will exit)
    // error("testFunc3", "This is a fatal error message.", 3.0, 3);

    return 0;
}