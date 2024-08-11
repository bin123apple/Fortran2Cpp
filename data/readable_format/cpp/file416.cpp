#include <memory> // For std::unique_ptr

class T { // Equivalent to the Fortran TYPE
  // Class contents go here
};

class Main {
public:
    void run() {
        T b; // Stack allocation, equivalent to Fortran's TYPE(t), TARGET :: b
        T* a = &b; // Pointer, equivalent to CLASS(t), POINTER :: a => b
        std::unique_ptr<T> c(new T); // Smart pointer for dynamic allocation, similar to ALLOCATABLE

        sub(a);
    }

private:
    void sub(T* a) {
        // Pointer passed to subroutine, equivalent to CLASS(t), POINTER :: a in Fortran
        // Functionality for subroutine goes here
    }
};

int main() {
    Main program;
    program.run();
    return 0;
}