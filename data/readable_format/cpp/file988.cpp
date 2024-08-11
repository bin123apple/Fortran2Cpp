#include <iostream>
#include <string>

// Instead of using a separate namespace, define the function directly in the global namespace
void mphys_tau_bin_interface() {
    // Array of strings to hold the lines of message
    std::string lines[] = {
        "===========================================================",
        "This is a dummy stub for the Tel-Aviv University bin ",
        "microphysics code. This code is not part of the current",
        "distribution.  To obtain the code, either email ",
        "ben.shipway@metoffice.gov.uk or visit the downloads",
        "page at http://www.convection.info/microphysics",
        "The program will now exit...",
        "==========================================================="
    };

    // Loop through each string in the array and output it
    for (const auto& line : lines) {
        std::cout << std::endl << line << std::endl;
    }

    // Exit the program
    exit(0);
}

int main() {
    // Call the function directly
    mphys_tau_bin_interface();
    return 0;
}