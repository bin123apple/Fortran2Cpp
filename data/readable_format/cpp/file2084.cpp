#include <iostream>
#include <array>

int main() {
    std::array<float, 3> vector3d;
    std::array<std::array<float, 3>, 3> matrix3d;

    // Initializing the 3D vector
    vector3d[0] = 1.0f;
    vector3d[1] = 2.0f;
    vector3d[2] = 3.0f;

    // Initializing the 3x3 matrix with 1.0f
    for (auto &row : matrix3d) {
        row.fill(1.0f);
    }

    return 0;
}