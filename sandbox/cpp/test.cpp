#include <iostream>

// Define the mod21 namespace and its functions directly
namespace mod21 {
    void test_mod21() {
        std::cout << "mod21 is working" << std::endl;
    }
}

// Define the mod22 namespace and its functions directly
namespace mod22 {
    void test_mod22() {
        std::cout << "mod22 is working" << std::endl;
    }
}

// Define the mod23 namespace, include usage of mod22 directly, and define its functions
namespace mod23 {
    // Direct usage of mod22 within mod23
    void test_mod23() {
        std::cout << "mod23 is working" << std::endl;
        mod22::test_mod22(); // Ensure mod22 is accessible
    }
}

int main() {
    mod21::test_mod21();
    mod22::test_mod22();
    mod23::test_mod23();
    return 0;
}