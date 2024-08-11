#include <iostream>
#include <cstdlib> // For std::exit()

// Global variables
double xmax;
double xmin;

// Function to check parameters
void checa_parametros() {
    if (xmax <= xmin) {
        std::cerr << "Error xmax<=xmin" << std::endl;
        std::exit(EXIT_FAILURE); // Stops the program
    }
}

int main() {
    // Example initialization
    xmax = 10.0;
    xmin = 5.0;

    // You can adjust xmax and xmin values here to test different scenarios
    // For example:
    // xmax = 4.0;
    // xmin = 5.0;

    // Check parameters
    checa_parametros();

    // If checa_parametros does not exit the program, it means the check passed
    std::cout << "Parameters are valid. Continuing the program..." << std::endl;

    // The rest of your program logic goes here

    return 0;
}