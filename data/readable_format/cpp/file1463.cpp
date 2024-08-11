#include <iostream>
#include <cstring> // for strlen

// Define the Chanel_C class directly in this file
class Chanel_C {
public:
    static const int filename_len = 240;
    int iw = 26;
    int ifiles_1 = 1;
    // Continue with other integer variables...

    char job_fn[filename_len];
    char output_fn[filename_len];
    // Continue with other character arrays...

    int ifilen[145];
    // Continue with other arrays...

    int irecln = 1023;
    // Continue with other variables...

    // Constructor
    Chanel_C() {
        // Initialize strings to empty
        job_fn[0] = '\0';
        output_fn[0] = '\0';
        // Continue initialization as necessary
    }

    // You can also add member functions here
};

int main() {
    Chanel_C testObj;

    // Test integer variables
    std::cout << "Testing integer variables..." << std::endl;
    if (testObj.iw == 26) {
        std::cout << "PASS: iw is initialized correctly." << std::endl;
    } else {
        std::cout << "FAIL: iw is not initialized correctly." << std::endl;
    }

    // Add similar tests for other integer variables...

    // Test character arrays (strings)
    std::cout << "Testing character variables..." << std::endl;
    if (strlen(testObj.job_fn) == 0) {
        std::cout << "PASS: job_fn is initialized correctly." << std::endl;
    } else {
        std::cout << "FAIL: job_fn is not initialized correctly." << std::endl;
    }

    // Add similar tests for other character arrays...

    // Test integer arrays
    std::cout << "Testing integer arrays..." << std::endl;
    if (testObj.ifilen[0] == 0) {
        std::cout << "PASS: ifilen is initialized correctly." << std::endl;
    } else {
        std::cout << "FAIL: ifilen is not initialized correctly." << std::endl;
    }

    // Add similar tests for other arrays and variables as needed...

    return 0;
}