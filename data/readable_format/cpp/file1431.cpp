#include <iostream>
#include <cmath>
#include <cstdlib> // For std::exit()

int main() {
    double theta = 1.0; // Angle in radians

    // Calculate the cosine and sine of theta
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    // Calculate the norm of the vector [cos(theta), sin(theta)]
    double norm = sqrt(cosTheta*cosTheta + sinTheta*sinTheta);

    // Check if the norm is approximately 1
    if (std::abs(norm - 1.0) > 1.0e-4) {
        std::cerr << "Error: The norm of the vector is not approximately 1." << std::endl;
        std::exit(1); // Exit with an error
    }

    // If this point is reached, the norm is approximately 1
    // (You can add further processing here if needed)

    return 0;
}