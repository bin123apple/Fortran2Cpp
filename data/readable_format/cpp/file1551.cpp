#include <string>
#include <array>
#include <iostream>

void foo() {
    std::array<int, 4> ibufr = {/* Initialize array with your values here */};
    std::string value;

    // Assuming CHAR(IBUFR(i)) is intended to convert the integer at IBUFR[i-1] (Fortran is 1-indexed, C++ is 0-indexed)
    // to its ASCII character equivalent and then concatenate.
    for (int i = 0; i < 4; ++i) {
        if (ibufr[i] >= 0 && ibufr[i] <= 255) {
            // Making sure the value is in the valid range for ASCII characters before conversion.
            value += static_cast<char>(ibufr[i]);
        } else {
            // Handle the error or ignore invalid values.
            std::cerr << "Value out of ASCII range: " << ibufr[i] << std::endl;
        }
    }

    // Assuming you want to do something with 'value', like print it
    std::cout << "Value: " << value << std::endl;
}

int main() {
    foo();
    return 0;
}