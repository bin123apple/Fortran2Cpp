#include <cassert>
#include <iostream>
#include <string>

struct FLAGS {
    std::string Encodings;

    char& at;
    char& dev;

    // Constructor to initialize references
    FLAGS(std::string& encodings) : Encodings(encodings), at(Encodings[0]), dev(Encodings[1]) {
        // Ensure Encodings has enough space
        Encodings.resize(5, ' '); // Defaulting to spaces to mimic Fortran behavior
    }
};

int main() {
    // Initialize a string for Encodings
    std::string encodings(5, ' '); // Make sure it's pre-sized to 5, filled with spaces
    FLAGS flags(encodings);

    // First test
    flags.Encodings = "ABCDE";
    flags.at = 'Z';  // This should update Encodings[0] to 'Z', making it "ZYCDE"
    flags.dev = 'Y'; // This should update Encodings[1] to 'Y', reaffirming it as "ZYCDE"

    assert(flags.Encodings == "ZYCDE");
    std::cout << "Test passed: Encodings correctly updated to ZYCDE." << std::endl;

    // Second test
    flags.Encodings = "12345";
    flags.at = '9'; // Expected to update Encodings[0] to '9', making it "98345"
    flags.dev = '8'; // Expected to update Encodings[1] to '8', reaffirming it as "98345"

    assert(flags.Encodings == "98345");
    std::cout << "Test passed: Encodings correctly updated to 98345." << std::endl;

    return 0;
}