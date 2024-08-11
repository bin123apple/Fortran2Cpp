#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>
#include <cstdlib>

// Base class
class T {
public:
    virtual ~T() = default; // Ensure proper cleanup of derived types
};

// Derived class
class T2 : public T {
    // Implementation specific to T2
};

// Function to check if two objects are of the same dynamic type
template<typename T1, typename T2>
bool same_type_as(const std::unique_ptr<T1>& a, const std::unique_ptr<T2>& b) {
    if (!a || !b) return false; // Check if either pointer is null
    return typeid(*a) == typeid(*b);
}

// Test function
void run_tests() {
    bool all_tests_passed = true;

    // Test 1: Allocation and move semantics
    std::unique_ptr<T> a = std::make_unique<T2>();
    auto a_raw = a.get(); // Store raw pointer for comparison
    std::unique_ptr<T> b = std::move(a);

    if (a != nullptr || b.get() != a_raw) {
        all_tests_passed = false;
        std::cerr << "Test 1 Failed: Allocation or move semantics not working as expected." << std::endl;
    }

    // Test 2: Type checking
    std::unique_ptr<T> c = std::make_unique<T2>();
    if (!same_type_as(b, c)) {
        all_tests_passed = false;
        std::cerr << "Test 2 Failed: Type checking not working as expected." << std::endl;
    }

    if (all_tests_passed) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cerr << "Some tests failed." << std::endl;
    }
}

int main() {
    run_tests();
    return 0;
}