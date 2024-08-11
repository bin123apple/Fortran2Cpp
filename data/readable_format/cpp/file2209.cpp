#include <iostream>

float chgtemp(float stationelev, float cellelev) {
    return 0.0065 * (stationelev - cellelev);
}

int main() {
    float stationelev = 1500.0; // Example value for station elevation
    float cellelev = 1000.0;    // Example value for cell elevation

    float temperatureChange = chgtemp(stationelev, cellelev);
    std::cout << "Temperature change: " << temperatureChange << std::endl;

    return 0;
}