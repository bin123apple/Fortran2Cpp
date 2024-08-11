#include <iostream>
#include <cstdlib>  // For std::abort

struct xyz {
    int x;
    xyz() : x(123) {}  // Constructor to initialize x to 123
};

int main() {
    xyz a;  // Create an instance of xyz with default initialization
    xyz b;  // Create another instance of xyz with default initialization

    if (a.x != 123) std::abort();
    if (b.x != 123) std::abort();

    return 0;
}