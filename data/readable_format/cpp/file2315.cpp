#include <iostream>
#include <cstdlib>

// Define the class with default initialization
class DefaultInitialization {
public:
    int x = 42; // Default value for x

    // Constructor
    DefaultInitialization() = default;
};

// Create an instance of the class
DefaultInitialization t;

int main() {
    // Check if the default value is correctly set
    if (t.x != 42) {
        std::abort();
    }

    // Modify the value and check again
    t.x = 0;
    if (t.x != 0) {
        std::abort();
    }

    return 0;
}