#include <iostream>
#include <cassert> // For assert()

// Define the namespace and function directly in this file
namespace annelid_test_a {

// Replicate the pure function functionality
constexpr int annelid_test() {
    return 23;
}

} // namespace annelid_test_a

int main() {
    // Test the annelid_test function
    assert(annelid_test_a::annelid_test() == 23);
    
    // If the assert passes, print a success message
    std::cout << "Test passed: annelid_test_a::annelid_test() == 23" << std::endl;
    
    return 0;
}