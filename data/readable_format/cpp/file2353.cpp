#include <iostream> // For std::cout, std::endl
#include <cstdlib>  // For std::exit

// Assuming mp_global_end is a function that needs to be called
void mp_global_end() {
    // Implementation of mp_global_end goes here
}

// The translated function
void stop_code(bool flag) {
    mp_global_end();
    if (flag) {
        std::exit(0);
    } else {
        std::exit(1);
    }
}

int main() {
    // Example usage of stop_code
    bool flag = true; // or false
    stop_code(flag);
    return 0; // This will never be reached due to std::exit
}