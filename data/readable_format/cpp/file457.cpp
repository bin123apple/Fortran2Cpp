#include <iostream>
#include <cstdint> // for std::int32_t

// Function definitions
extern "C" char return_char1(std::int32_t i) {
    return static_cast<char>(i);
}

extern "C" char return_char2(std::int32_t i) {
    return static_cast<char>(i);
}

extern "C" char return_char3(std::int32_t i) {
    return static_cast<char>(i);
}

int main() {
    std::int32_t test_values[] = {65, 66, 97, 98, 48}; // ASCII values for 'A', 'B', 'a', 'b', '0'
    int num_values = sizeof(test_values) / sizeof(test_values[0]);

    // Test return_char1
    for (int i = 0; i < num_values; ++i) {
        char result = return_char1(test_values[i]);
        std::cout << "return_char1(" << test_values[i] << ") = " << result << std::endl;
    }

    // Test return_char2
    for (int i = 0; i < num_values; ++i) {
        char result = return_char2(test_values[i]);
        std::cout << "return_char2(" << test_values[i] << ") = " << result << std::endl;
    }

    // Test return_char3
    for (int i = 0; i < num_values; ++i) {
        char result = return_char3(test_values[i]);
        std::cout << "return_char3(" << test_values[i] << ") = " << result << std::endl;
    }

    return 0;
}