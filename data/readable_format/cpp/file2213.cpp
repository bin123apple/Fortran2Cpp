#include <iostream>

namespace broken_mod {
    // In the original Fortran code, the module `broken_mod` doesn't have any content.
    // We'll leave it empty as well.
}

int main() {
    using namespace broken_mod;

    int x = 1;
    int y = 2;
    int z = x + y;

    std::cout << "z = " << z << std::endl;

    return 0;
}