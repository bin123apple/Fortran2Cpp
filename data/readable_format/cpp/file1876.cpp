#include <iostream>
#include <sstream>
#include <array>
#include <string>
#include <iomanip>

int main() {
    // Equivalent 2D array in C++
    std::array<std::array<std::string, 2>, 4> r = {{
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"}
    }};

    // Equivalent to the Fortran WRITE statements using std::stringstream for formatting
    std::stringstream ss;
    ss << "hello\nworld";
    r[0][0] = ss.str().substr(0, 12); // The substr() call simulates the fixed length of Fortran character variables.
    r[1][0] = ss.str().substr(6, 12);

    ss.str(""); // Clear the stringstream
    ss << "hello " << std::setw(1) << "HELLO !" << "\n" << std::left << std::setw(12) << "world" << "WORLD";
    r[0][1] = ss.str().substr(0, 12);
    r[1][1] = ss.str().substr(13, 12);

    // Equivalent to the Fortran condition checking and STOP
    if (r[0][0] != "hello      " || r[1][0] != "world      " ||
        r[2][0] != "0123456789a" || r[3][0] != "0123456789a" ||
        r[0][1] != "hello HELLO" || r[1][1] != "world      " ||
        r[2][1] != "0123456789a" || r[3][1] != "0123456789a") {
        std::cerr << "An error occurred." << std::endl;
        return 1;
    }

    return 0;
}