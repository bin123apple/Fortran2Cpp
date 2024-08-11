#include <iostream>
#include <cstdlib>

class Foo {
public:
    float* c_a; // Pointer to a float

    // Constructor
    Foo() : c_a(nullptr) {}

    // Bind the pointer to the address of a variable
    void bind(float& variable) {
        c_a = &variable;
    }

    // Assign a value to the variable pointed to by c_a
    void assign(float value) {
        if(c_a) {
            *c_a = value;
        }
    }
};

int main() {
    Foo foo;
    float z = 0.0f;

    foo.bind(z); // Bind the address of z to c_a
    foo.assign(42); // Assign 42 to the location pointed by c_a, which is z

    if (z == 42) {
        std::cout << "Test passed: z is 42" << std::endl;
    } else {
        std::cerr << "Test failed: z is not 42" << std::endl;
        return 1; // Return an error code
    }

    return 0; // Success
}