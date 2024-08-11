#include <iostream>
#include <sstream>
#include <string>

// Assuming the print_optimize_message function is defined as before
void print_optimize_message() {
    std::cout << "Preprocessor: " << std::endl;
    
    #ifdef ARTED_SC
    std::cout << "  ARTED_SC" << std::endl;
    #endif
    
    // Repeat for other preprocessor directives as in the original example
}

// A simple test function that checks for a specific output
bool testOutput(const std::string& expected) {
    // Redirect stdout to a string
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream strCout;
    std::cout.rdbuf(strCout.rdbuf());

    // Call the function
    print_optimize_message();

    // Restore old stdout
    std::cout.rdbuf(oldCoutStreamBuf);

    // Check if the expected string is in the output
    std::string output = strCout.str();
    return output.find(expected) != std::string::npos;
}

int main() {
    bool allTestsPassed = true;

    // Example test: check if ARTED_SC is printed when ARTED_SC is defined
    // This particular test requires you to define ARTED_SC when compiling to be meaningful
    #ifdef ARTED_SC
    allTestsPassed &= testOutput("ARTED_SC");
    #endif

    // Add more tests as needed

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}