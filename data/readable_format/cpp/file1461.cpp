#include <iostream>
#include <cmath> // For std::sqrt

// DE class definition
class DE {
public:
    static float zu(float az, float xx) {
        return 1.0f - lz(az, xx) - lz(xx, az);
    }

    static float lz(float ho, float gh) {
        return std::sqrt(ho) - ho * gh;
    }
};

// A simple function to compare floats with a tolerance
bool compareFloat(float a, float b, float tolerance = 0.0001f) {
    return std::abs(a - b) < tolerance;
}

// Main program
int main() {
    // Test lz function
    float lzResult = DE::lz(4.0f, 2.0f);
    std::cout << "Test lz(4.0, 2.0): " << lzResult << std::endl;
    if (!compareFloat(lzResult, std::sqrt(4.0f) - 4.0f * 2.0f)) {
        std::cerr << "Test failed for lz(4.0, 2.0)" << std::endl;
    }

    // Test zu function
    float zuResult = DE::zu(4.0f, 2.0f);
    std::cout << "Test zu(4.0, 2.0): " << zuResult << std::endl;
    if (!compareFloat(zuResult, 1.0f - DE::lz(4.0f, 2.0f) - DE::lz(2.0f, 4.0f))) {
        std::cerr << "Test failed for zu(4.0, 2.0)" << std::endl;
    }

    // Add more tests if needed

    return 0;
}