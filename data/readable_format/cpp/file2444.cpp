#include <iostream>
#include <array>
#include <cmath>

void eulerrot(const std::array<double, 3>& ang, std::array<std::array<double, 3>, 3>& rot) {
    double sa = sin(ang[0]);
    double sb = sin(ang[1]);
    double sg = sin(ang[2]);
    double ca = cos(ang[0]);
    double cb = cos(ang[1]);
    double cg = cos(ang[2]);

    rot[0][0] = cg * cb * ca - sg * sa;
    rot[0][1] = cg * cb * sa + sg * ca;
    rot[0][2] = -cg * sb;
    rot[1][0] = -sg * cb * ca - cg * sa;
    rot[1][1] = -sg * cb * sa + cg * ca;
    rot[1][2] = sg * sb;
    rot[2][0] = sb * ca;
    rot[2][1] = sb * sa;
    rot[2][2] = cb;
}

int main() {
    std::array<double, 3> angles = {0.1, 0.2, 0.3};  // Example angles in radians
    std::array<std::array<double, 3>, 3> rotationMatrix;

    eulerrot(angles, rotationMatrix);

    // Output the results for visual verification
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "rot(" << i+1 << "," << j+1 << ") = " << rotationMatrix[i][j] << std::endl;
        }
    }

    return 0;
}