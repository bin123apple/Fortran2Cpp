#include <iostream>
#include <string>

// Declare a namespace to encapsulate the functionality, similar to the Fortran module
namespace coop_wrapper_typedef {

// Assuming coop_version is a global variable defined here
std::string coop_version = "1.0.0";

void coop_wrapper_typedef_print() {
    std::cout << "This is COOP VERSION " << coop_version << std::endl;
    std::cout << "Wrapper for typedef." << std::endl;
}

} // namespace coop_wrapper_typedef

int main() {
    // Call the function within the namespace
    coop_wrapper_typedef::coop_wrapper_typedef_print();

    return 0;
}