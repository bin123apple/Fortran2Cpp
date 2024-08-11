#include <cstdlib> // For std::abort()

class m {
public:
    // Function that mimics the Fortran function 'f'
    int f() {
        value = 42; // Initialize the return value
        sub(); // Call the nested subroutine
        if (value == 1) value += 1; // Modify the return value based on a condition
        return value; // Return the modified value
    }

private:
    // Member variable to hold the "return" value
    int value;
    
    // Nested subroutine that can modify 'value'
    void sub() {
        if (value == 42) value -= 41;
    }
};

int main() {
    m module; // Create an instance of the class 'm'
    if (module.f() != 2) std::abort(); // Use the function and check its return value
    return 0;
}