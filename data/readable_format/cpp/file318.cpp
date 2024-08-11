#include <memory> // For std::unique_ptr

// Forward declaration for 't' to be used in 't2'
class t;

// Definition of 't' as an abstract class to allow for polymorphism
class t {
public:
    virtual ~t() = default; // Virtual destructor for proper cleanup of derived classes
};

// Definition of 't2' which contains a pointer to 't'
class t2 {
public:
    std::unique_ptr<t> t_ptr; // Using unique_ptr for automatic memory management
};

// Test function to demonstrate usage
void test() {
    // Dynamically allocated instances of 't', though 't' is abstract and cannot be instantiated directly
    // In a real scenario, 't' would have derived classes that could be instantiated
    std::unique_ptr<t> a, c, d;
    
    // Demonstration of allocating 't2' and its member of type 't'
    t2 b;
    // Since 't' is abstract, we cannot directly allocate an object of type 't'
    // b.t_ptr = std::make_unique<t>(); // This is conceptually what we want, but won't compile due to 't' being abstract
    
    // The correct approach in a real scenario would be to have a derived class from 't' and allocate that
    // For example: b.t_ptr = std::make_unique<DerivedClass>();
}

int main() {
    test();
    return 0;
}