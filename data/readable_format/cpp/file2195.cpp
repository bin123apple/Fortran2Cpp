#include <iostream>

// Define the constants directly in this file
namespace constants {
    const int long_string_size = 100000;
    const int string_size = 1000;
    const int short_string_size = 10;
}

int main() {
    // Use the constants in your main function or any other part of this file
    std::cout << "Long string size: " << constants::long_string_size << std::endl;
    std::cout << "String size: " << constants::string_size << std::endl;
    std::cout << "Short string size: " << constants::short_string_size << std::endl;

    // Check if the values are correct, as a form of simple test
    if (constants::long_string_size != 100000) {
        std::cout << "Test failed: long_string_size" << std::endl;
    } else if (constants::string_size != 1000) {
        std::cout << "Test failed: string_size" << std::endl;
    } else if (constants::short_string_size != 10) {
        std::cout << "Test failed: short_string_size" << std::endl;
    } else {
        std::cout << "All tests passed." << std::endl;
    }

    return 0;
}