#include <iostream>
#include <type_traits>
#include <cassert>
#include <cstdint>

// Define the namespace and its contents within this file
namespace def_kinrea {
    constexpr int32_t ip = 0;
    using rp = double;
}

// Function prototypes for tests
void testIntegerParameter();
void testRealParameterType();

int main() {
    // Run the tests
    testIntegerParameter();
    testRealParameterType();
    
    std::cout << "All tests passed successfully!" << std::endl;
    
    return 0;
}

void testIntegerParameter() {
    // Test the value of `ip`
    assert(def_kinrea::ip == 0);
    
    // Test the type of `ip`
    static_assert(std::is_same<decltype(def_kinrea::ip), const int32_t>::value, "ip must be of type int32_t");
    
    std::cout << "Integer parameter tests passed." << std::endl;
}

void testRealParameterType() {
    // Test the type of `rp`
    static_assert(std::is_same<def_kinrea::rp, double>::value, "rp must be an alias for double");
    
    std::cout << "Real parameter type tests passed." << std::endl;
}