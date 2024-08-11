#include <iostream>
#include <array>

class Vec3 {
public:
    std::array<float, 3> coords;

    // Default constructor
    Vec3() : coords{0.0f, 0.0f, 0.0f} {}

    // Initializer constructor
    Vec3(float x, float y, float z) : coords{x, y, z} {}
};

int main() {
    // Equivalent of the Fortran 'parameter' attribute for constants
    const Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(1.0f, 2.0f, 3.0f); // Direct initialization

    float x = v1.coords[0]; // Indexing from 0 in C++

    for (int i = 0; i < 3; ++i) { // Looping from 0 to 2
        x = v1.coords[i];
        x = v2.coords[i];
    }

    int i = 2; // To use in the reordering, note the change due to 0-based indexing

    // Manually reorder based on the Fortran example, taking into account 0-based indexing
    v2 = Vec3(v1.coords[(i+1)%3], v1.coords[i%3], v1.coords[(i-1+3)%3]);

    return 0;
}