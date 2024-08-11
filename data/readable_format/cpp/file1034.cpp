#include <iostream>

// Equivalent C++ structure to Fortran module
class m1 {
public:
    // Equivalent C++ functions to Fortran subroutines
    void bar() {
        // Implementation of subroutine bar
    }

    void bar_none(int i) {
        // Implementation of subroutine bar_none with an integer parameter
    }

    void none_bar(float x) {
        // Implementation of subroutine none_bar with a real (float) parameter
    }
};

int main() {
    // Example usage
    m1 instance;
    instance.bar();
    instance.bar_none(5);
    instance.none_bar(3.14f);

    return 0;
}