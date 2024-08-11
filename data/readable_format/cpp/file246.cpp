#include <iostream>

// Equivalent to Fortran's type t
class T {
public:
    int x; // Assuming default initialization or constructor will handle it
    // In C++, you typically initialize primitives in a constructor or directly.
    T() : x(0) {} // Default constructor initializing x
};

// Equivalent to Fortran's type t2
class T2 {
public:
    T* a; // Pointer to T, equivalent to allocatable
    T2() : a(nullptr) {} // Default constructor initializing a to nullptr
    T2(const T2& other) { // Copy constructor
        if (other.a != nullptr) {
            a = new T();
            *a = *(other.a); // Shallow copy of the content
        } else {
            a = nullptr;
        }
    }
    ~T2() { delete a; } // Destructor to deallocate memory
    T2& operator=(const T2& other) { // Copy assignment operator
        if (this != &other) { // Protect against self-assignment
            delete a; // Free existing resource
            if (other.a != nullptr) {
                a = new T();
                *a = *(other.a); // Shallow copy of the content
            } else {
                a = nullptr;
            }
        }
        return *this;
    }
};

void test2() {
    T2 one, two;

    two.a = new T(); // Allocate memory for a in object two
    one = two; // Uses copy assignment operator
}

int main() {
    test2();
    return 0;
}