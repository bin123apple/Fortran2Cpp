// Define a namespace to simulate the Fortran module
namespace m1 {
    extern int i; // Declare i as an external variable
}

// Definition of the external variable
int m1::i;

int main() {
    // main() function does not need to do anything specific
    // just demonstrating the use of the external variable
    m1::i = 10; // Assign a value to i
    return 0;
}