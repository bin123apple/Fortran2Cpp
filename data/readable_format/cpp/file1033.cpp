#include <iostream>

// Equivalent to Fortran module A
namespace A {
    class A_type {
    public:
        float comp; // Assuming 'real' translates to 'float' in C++
    };
}

// Equivalent to Fortran module B
namespace B {
    class B_var_class {
    public:
        A::A_type B_var; // Instance of A_type as a public member
    };

    // Instantiating B_var_class to make B_var publicly accessible
    B_var_class B_var_instance;
}

int main() {
    A::A_type A_var; // Equivalent to type(A_type):: A_var in Fortran
    B::B_var_instance.B_var.comp = 10.0f; // Setting value for demonstration
    
    // Example usage: Accessing and setting values
    A_var.comp = 5.0f;

    // Output the values to verify
    std::cout << "A_var.comp = " << A_var.comp << std::endl;
    std::cout << "B_var_instance.B_var.comp = " << B::B_var_instance.B_var.comp << std::endl;

    return 0;
}