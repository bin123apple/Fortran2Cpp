#include <iostream>
#include <vector>
#include <stdexcept>

// Define the T structure
struct T {
    int I;
};

// Function to check bounds
void check(int lbnd, int ubnd, int lower, int upper) {
    if (lbnd != lower) throw std::runtime_error("Lower bound check failed");
    if (ubnd != upper) throw std::runtime_error("Upper bound check failed");
}

int main() {
    // Define the T1 array with bounds 0 to 3
    std::vector<T> T1(4); // Fortran arrays are traditionally 1-based, but T1(0:3) is 0-based in Fortran.

    // Associate P with T1's I components
    std::vector<int> P;
    for (auto& t : T1) {
        P.push_back(t.I);
    }

    // Check the bounds for P
    check(1, 4, 1, 4); // P is 1-based in Fortran context

    // Associate P2 with T1(:)'s I components (which is actually the same as P)
    std::vector<int> P2 = P;

    // Check the bounds for P2
    check(1, 4, 1, 4);

    // Associate Q with T1
    std::vector<T>& Q = T1;

    // Check the bounds for Q
    check(0, 3, 0, 3); // Q is 0-based in Fortran context

    // Associate Q2 with T1(:) (which is actually the same as Q)
    std::vector<T>& Q2 = T1;

    // Check the bounds for Q2
    check(1, 4, 1, 4); // Q2 is 1-based in Fortran context

    std::cout << "All checks passed successfully." << std::endl;

    return 0;
}