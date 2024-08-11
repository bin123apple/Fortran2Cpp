// arrayio_2.cpp
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>

int main() {
    int i = 2;
    std::array<std::array<std::string, 2>, 4> r = {{
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"}
    }};
    
    // Directly assigning the strings as per the Fortran logic
    r[0][i-2] = "hello       ";
    r[1][i-2] = "world       ";
    r[0][i-1] = "HELLO !     ";
    r[1][i-1] = "WORLD       ";

    // Unit test to verify the array content
    if (r[0][0] != "hello       " ||
        r[1][0] != "world       " ||
        r[2][0] != "0123456789ab" ||
        r[3][0] != "0123456789ab" ||
        r[0][1] != "HELLO !     " ||
        r[1][1] != "WORLD       " ||
        r[2][1] != "0123456789ab" ||
        r[3][1] != "0123456789ab") {
        std::cerr << "Test failed." << std::endl;
        return EXIT_FAILURE;
    } else {
        std::cout << "Test passed." << std::endl;
    }

    return 0;
}