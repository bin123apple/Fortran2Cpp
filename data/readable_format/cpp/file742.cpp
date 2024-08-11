#include <iostream>

// Define the 't' class directly in this file
class t {
public:
    int x; // Equivalent to 'integer :: x'

    // Constructors
    t() : x(0) {} // Default constructor
    t(int val) : x(val) {} // Parameterized constructor

    // Overloaded operator functions
    friend bool operator==(const t& lhs, const t& rhs) {
        return lhs.x == rhs.x;
    }

    friend bool operator!=(const t& lhs, const t& rhs) {
        return !(lhs == rhs);
    }

    // Custom functions to simulate the .FOO. operator behavior
    bool foo(const t& other) const {
        return false; // Placeholder logic
    }

    bool bar(const t& other) const {
        return false; // Placeholder logic
    }
};

// Test functions
void testEquality(const t& obj1, const t& obj2) {
    std::cout << "obj1 == obj2: " << (obj1 == obj2 ? "true" : "false") << std::endl;
}

void testInequality(const t& obj1, const t& obj2) {
    std::cout << "obj1 != obj2: " << (obj1 != obj2 ? "true" : "false") << std::endl;
}

void testFoo(const t& obj1, const t& obj2) {
    std::cout << "obj1.foo(obj2): " << (obj1.foo(obj2) ? "true" : "false") << std::endl;
}

void testBar(const t& obj1, const t& obj2) {
    std::cout << "obj1.bar(obj2): " << (obj1.bar(obj2) ? "true" : "false") << std::endl;
}

// Main function
int main() {
    t obj1(1), obj2(1); // Initialized to make them equal

    testEquality(obj1, obj2);
    testInequality(obj1, obj2);
    testFoo(obj1, obj2);
    testBar(obj1, obj2);

    return 0;
}