#include <iostream>
// Assuming the namespace foodie_error_codes is defined in this or another included file.
namespace foodie_error_codes {
    using I_P = int;
    constexpr I_P ERROR_UNSUPPORTED_SCHEME = 1;
}

int main() {
    std::cout << "Testing ERROR_UNSUPPORTED_SCHEME..." << std::endl;
    if (foodie_error_codes::ERROR_UNSUPPORTED_SCHEME == 1) {
        std::cout << "Test passed: ERROR_UNSUPPORTED_SCHEME = 1" << std::endl;
    } else {
        std::cout << "Test failed: ERROR_UNSUPPORTED_SCHEME /= 1" << std::endl;
    }

    return 0;
}