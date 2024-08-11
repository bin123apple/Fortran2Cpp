#include <iostream>

// Definition of the base class 'bar_type'
class bar_type {
public:
    virtual ~bar_type() = default; // Virtual destructor for polymorphic deletion
    virtual void test_method() const = 0; // Pure virtual function
};

// Definition of the derived class 'foo_type'
class foo_type : public bar_type {
public:
    // Override the test method to provide specific functionality
    void test_method() const override {
        std::cout << "foo_type test method called" << std::endl;
    }
};

// A simple function to demonstrate the test method functionality
void demonstrate_test_method(const bar_type& obj) {
    obj.test_method();
}

// Main function to run the demonstration
int main() {
    foo_type myFoo; // Create an instance of the derived class
    demonstrate_test_method(myFoo); // Demonstrate the test method

    return 0; // Indicates successful execution
}