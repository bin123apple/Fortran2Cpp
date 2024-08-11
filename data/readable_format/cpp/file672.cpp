#include <iostream>
#include <memory> // For std::unique_ptr

class Foo {
public:
    // Constructor
    Foo() : p(nullptr) {} // Initialize p as nullptr

    // Pure function bar equivalent in C++
    int bar(int a) const {
        return a;
    }

private:
    std::unique_ptr<int> p; // Using unique_ptr for automatic memory management
};

int main() {
    Foo fooInstance;
    std::cout << fooInstance.bar(10) << std::endl; // Example usage of bar function
    return 0;
}