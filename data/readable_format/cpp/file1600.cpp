#include <cstdint>

// C++ structure to mimic the Fortran common block and equivalence behavior
struct B8_COM {
    // Union to simulate the equivalence between B8_nfa and B8_cm
    union {
        float B8_nfa; // Assuming 'real' in Fortran is equivalent to 'float' in C++
        int32_t B8_cm; // Assuming 'integer' in Fortran maps to 'int32_t' in C++ for 32-bit integer
    };

    // Static member to hold the size parameter
    static const int B8_sz = 1;
};

// You can use B8_COM like this:
int main() {
    B8_COM b8;
    b8.B8_nfa = 5.0f; // Assign a value to B8_nfa

    // Due to the union, B8_cm now holds the bit representation of 5.0f float value
    // Note: Directly printing b8.B8_cm will not print '5' because it prints the integer representation of the binary float value.
    // Access and use b8.B8_nfa or b8.B8_cm depending on the context in which you need them.

    return 0;
}