#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    try {
        std::string textt(7, ' '); // equivalent to character (len = 7), target :: textt
        std::string& textp = textt; // equivalent to character (len = 7), pointer :: textp
        std::string textp2 = textt.substr(0, 5); // equivalent to character (len = 5), pointer :: textp2

        // Check the length conditions
        if (textp.length() != 7) throw std::runtime_error("STOP 1");
        if (textp2.length() != 5) throw std::runtime_error("STOP 2");

        // Modify the strings
        textp = "aaaaaaa"; // equivalent to textp = 'aaaaaaa'
        textp2 = "bbbbb"; // equivalent to textp2 = 'bbbbbbb'

        // Reflect the changes back to textt
        textt.replace(0, 5, textp2); // Reflecting changes of textp2 back to textt

        // Check the final conditions
        if (textp != "bbbbbaa") throw std::runtime_error("STOP 3");
        if (textp2 != "bbbbb") throw std::runtime_error("STOP 4");

        std::cout << "Program executed successfully!" << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}