#include <iostream>
#include <cstdlib> // For std::abort()

// Function prototypes
double add(double x, double y);
bool greater(double x, double y);

int main() {
    // Function pointer declaration
    double (*f)(double, double);
    bool g;

    // First check
    g = greater(4., add(1., 2.));
    if (!g) std::abort();

    // Setting the function pointer to point to add function
    f = add;

    // Second check using the function pointer
    g = greater(4., f(1., 2.));
    if (!g) std::abort();

    return 0;
}

// Definition of the add function
double add(double x, double y) {
    std::cout << "add: " << x << " " << y << std::endl;
    return x + y;
}

// Definition of the greater function
bool greater(double x, double y) {
    return x > y;
}