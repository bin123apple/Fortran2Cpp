#include <iostream>
#include <array>

struct g1 {
    std::array<int, 3> a;
    std::array<double, 3> r;
};

int main() {
    g1 ex, goal;

    // In Fortran example, only the first elements are assigned, not the entire arrays.
    // Adjusting that in C++:
    ex.a[0] = 3; // Assuming intent was to assign only the first element based on Fortran code
    ex.r[0] = 1.2; // Same assumption as above

    // The Fortran `transfer` call doesn't have a direct analogue in C++,
    // especially as used in the example. Direct memory copy can be achieved with std::memcpy if needed.
    // Here, we assign `ex` directly to `goal` to demonstrate simple structure assignment.
    goal = ex;

    // Printing values
    std::cout << "goal.a[0]: " << goal.a[0] << ", goal.r[0]: " << goal.r[0] << std::endl;

    return 0;
}