#include <iostream>
#include <cstdlib>

int edg(int l, int k, int e[3][/* appropriate size */]) {
    for (int i = 0; i < 3; ++i) {
        if (e[i][l] == k) {
            return i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
        }
    }

    std::cerr << "0***error in function edg***" << std::endl;
    std::cerr << "***elements not adjacent***" << std::endl;
    std::exit(201);
}

int main() {
    // Example usage, e.g.:
    int l = /* appropriate value */;
    int k = /* appropriate value */;
    int e[3][/* appropriate size */] = { /* appropriate initialization */ };

    int result = edg(l, k, e);

    // Output the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}