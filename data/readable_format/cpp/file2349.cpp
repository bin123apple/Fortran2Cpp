#include <vector>
#include <iostream>
#include <cmath>

// Define precision types
using ReKi = double;
using IntKi = int;

struct IceFloe_ParameterType {
    std::vector<std::vector<ReKi>> loadSeries;
    ReKi iceVel;
    ReKi iceDirection;
    ReKi minStrength;
    ReKi minStrengthNegVel;
    ReKi defaultArea;
    ReKi crushArea;
    ReKi coeffStressRate;
    ReKi C[4];
    ReKi dt;
    ReKi rampTime;
    std::vector<ReKi> legX;
    std::vector<ReKi> legY;
    std::vector<ReKi> ks;
    IntKi numLegs;
    IntKi iceType;
    IntKi logUnitNum;
    bool singleLoad;
    bool initFlag;
};

// Constants
const ReKi Pi = 3.141592654;
const ReKi D2R = Pi / 180.0;
const ReKi R2D = 180.0 / Pi;

int main() {
    // Example of creating an instance of IceFloe_ParameterType
    IceFloe_ParameterType iceFloeParams;

    // Initialize some values
    iceFloeParams.iceVel = 5.0;
    iceFloeParams.iceDirection = 90.0 * D2R; // Convert degrees to radians
    iceFloeParams.minStrength = 1.0;
    iceFloeParams.singleLoad = true;
    iceFloeParams.initFlag = false;

    // Print some values
    std::cout << "Ice Velocity: " << iceFloeParams.iceVel << std::endl;
    std::cout << "Ice Direction (rad): " << iceFloeParams.iceDirection << std::endl;
    std::cout << "Ice Direction (deg): " << iceFloeParams.iceDirection * R2D << std::endl;

    return 0;
}