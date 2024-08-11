#include <iostream>
#include <type_traits>

// Define the namespace and double precision type as in your original request
namespace types {
    using dp = double;
}

int main() {
    // Check if types::dp is indeed double
    if (std::is_same<types::dp, double>::value) {
        std::cout << "Test passed: dp is double precision." << std::endl;
    } else {
        std::cout << "Test failed: dp is not double precision." << std::endl;
    }

    return 0;
}