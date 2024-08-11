// CombinedCounters.cpp
#include <iostream>

// Define the Counters class directly in this file
class Counters {
public:
    static int killed_photons_geo;
    static int killed_photons_int;
    static int killed_photons_reabs;
};

// Initialize static members of Counters
int Counters::killed_photons_geo = 0;
int Counters::killed_photons_int = 0;
int Counters::killed_photons_reabs = 0;

int main() {
    // Test incrementing killed_photons_geo
    Counters::killed_photons_geo += 1;
    if (Counters::killed_photons_geo != 1) {
        std::cout << "Test failed for killed_photons_geo." << std::endl;
    } else {
        std::cout << "Test passed for killed_photons_geo." << std::endl;
    }

    // Test incrementing killed_photons_int
    Counters::killed_photons_int += 1;
    if (Counters::killed_photons_int != 1) {
        std::cout << "Test failed for killed_photons_int." << std::endl;
    } else {
        std::cout << "Test passed for killed_photons_int." << std::endl;
    }

    // Test incrementing killed_photons_reabs
    Counters::killed_photons_reabs += 1;
    if (Counters::killed_photons_reabs != 1) {
        std::cout << "Test failed for killed_photons_reabs." << std::endl;
    } else {
        std::cout << "Test passed for killed_photons_reabs." << std::endl;
    }

    return 0;
}