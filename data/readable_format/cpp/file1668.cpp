#include <iostream>
#include <cstdlib>

// Equivalent of the Fortran subroutine 'aborts'
void aborts(const char* s) {
    std::cout << s << std::endl;
    std::exit(1);
}

// Equivalent of the Fortran module and structure
struct s6 {
    int i;
};

// Equivalent of the Fortran 'structure /s7/'
struct s7 {
    float r;
};

int main() {
    s6 s6_instance;
    s7 s7_instances[3]; // Array of 3 s7 instances, equivalent to the 'record /s7/ s7(3)'

    s6_instance.i = 0;
    s7_instances[0].r = 1.0f;
    s7_instances[1].r = 2.0f;
    s7_instances[2].r = 3.0f;

    if (s6_instance.i != 0) {
        aborts("s6.i");
    }

    if (s7_instances[0].r != 1.0f) {
        aborts("s7(1).r");
    }

    if (s7_instances[1].r != 2.0f) {
        aborts("s7(2).r");
    }

    // The original Fortran code stops execution with a non-zero status in the 'aborts' subroutine,
    // so no explicit return statement is required here, as 'std::exit' is called in 'aborts'.

    return 0;
}