#include <iostream>

// Equivalent of the Fortran module 'm' and type 't'
class t {
    // Private method, equivalent to Fortran's 'PRIVATE :: priv'
    void priv() {
        std::cout << "Private method called" << std::endl;
    }

public:
    // Public method, equivalent to Fortran's 'PUBLIC :: publ'
    void publ() {
        std::cout << "Public method called" << std::endl;
    }

    // Friend function declaration to allow test2 to access private members
    friend void test2();
};

// Equivalent of the Fortran subroutine 'test1'
void test1() {
    t obj;
    // Directly calling priv is not allowed here since it's private
    // obj.priv(); // Uncommenting this line would cause a compile-time error
    obj.publ();
}

// Equivalent of the Fortran subroutine 'test2' and use of 'USE m'
void test2() {
    t obj;
    // Direct access to private member due to friend declaration
    obj.priv();
    obj.publ();
}

int main() {
    test1();
    test2();
    return 0;
}