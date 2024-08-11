#include <iostream>
#include <vector>
#include <cmath> // For std::abs

class UpdateVelocAcoustic {
public:
    static void updateVelocAcoustic(int nglob, float* velocOuterCore, float* accelOuterCore, float deltaTover2) {
        for (int i = 0; i < nglob; ++i) {
            velocOuterCore[i] += accelOuterCore[i] * deltaTover2;
        }
    }
};

bool areFloatsEqual(float a, float b) {
    return std::abs(a - b) < 1e-5;
}

void testUpdateVelocAcoustic() {
    int nglob = 5;
    float deltaTover2 = 0.5f;
    std::vector<float> velocOuterCore(nglob, 0.0f);
    std::vector<float> accelOuterCore = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f}; // Initialized with test accelerations

    // Expected velocities after update
    std::vector<float> expectedVelocities = {0.05f, 0.1f, 0.15f, 0.2f, 0.25f};

    UpdateVelocAcoustic::updateVelocAcoustic(nglob, velocOuterCore.data(), accelOuterCore.data(), deltaTover2);

    bool testPassed = true;
    for (int i = 0; i < nglob; ++i) {
        if (!areFloatsEqual(velocOuterCore[i], expectedVelocities[i])) {
            std::cout << "Test failed at index " << i << ": expected " << expectedVelocities[i] << ", got " << velocOuterCore[i] << std::endl;
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << "All tests passed successfully." << std::endl;
    }
}

int main() {
    testUpdateVelocAcoustic();
    return 0;
}