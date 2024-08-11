#include <iostream>
#include <cassert> // For basic assertions

// Definition of the global structure mimicking the Fortran common block
struct BlockA {
    double a = 0.0; // Default-initialized to 0.0
    double b = 0.0; // Default-initialized to 0.0
    double d[10][30] = {}; // Default-initialized to 0.0
} blocka;

int main() {
    // Print ok to match the original Fortran program's behavior
    std::cout << "ok" << std::endl;

    // Basic checks to assert the default values of blocka members
    assert(blocka.a == 0.0);
    assert(blocka.b == 0.0);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 30; ++j) {
            assert(blocka.d[i][j] == 0.0); // Verifying each element is initialized to 0.0
        }
    }

    // If the program reaches this point, the basic integrity checks passed
    std::cout << "Basic integrity checks passed." << std::endl;

    return 0;
}