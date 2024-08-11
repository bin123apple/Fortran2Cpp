#include <cstdlib> // For std::abort

class M {
public:
    static int a;
};

int M::a = 0; // Definition of the static member variable

int main() {
    int& local1 = M::a; // Reference to the static member variable, analogous to 'use, local1 => a'
    int& local2 = M::a; // Another reference to the same static member variable, analogous to 'use, local2 => a'

    local1 = 5; // Modifying the variable through one reference
    local2 = 3; // Modifying the same variable through another reference

    // Since local1 and local2 reference the same variable, they must be equal. If not, abort.
    if (local1 != local2) {
        std::abort();
    }

    return 0;
}