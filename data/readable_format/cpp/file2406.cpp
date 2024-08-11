#include <iostream>
#include <string>

// Assuming the "gridQ.h" content as part of this single file
namespace GridQ {
    int nQ2g;
    int inter_degreeQ;
    std::string InQGrid;
}

// Function declaration
void SetQGridParameters(int npQ, int degQ) {
    GridQ::nQ2g = npQ;
    GridQ::inter_degreeQ = degQ;
    GridQ::InQGrid = "done";
}

// Main function for unit testing
int main() {
    int npQ = 10;    // Test value for npQ
    int degQ = 5;    // Test value for degQ
    int errors = 0;  // Counter for errors

    // Call the function with test values
    SetQGridParameters(npQ, degQ);

    // Check and print results
    if (GridQ::nQ2g != npQ) {
        std::cerr << "Error: nQ2g is incorrect. Expected: " << npQ << ", Got: " << GridQ::nQ2g << std::endl;
        ++errors;
    }

    if (GridQ::inter_degreeQ != degQ) {
        std::cerr << "Error: inter_degreeQ is incorrect. Expected: " << degQ << ", Got: " << GridQ::inter_degreeQ << std::endl;
        ++errors;
    }

    if (GridQ::InQGrid != "done") {
        std::cerr << "Error: InQGrid is incorrect. Expected: done, Got: " << GridQ::InQGrid << std::endl;
        ++errors;
    }

    if (errors == 0) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cerr << "There were " << errors << " error(s)." << std::endl;
    }

    return 0;
}