#include <iostream>
#include <vector>
#include <cmath>

class Barrel {
private:
    int nvats;
    float vol;
    float strength;
    std::vector<std::vector<float>> vat;

public:
    // Constructor
    Barrel(float _strength) : nvats(0), vol(119.2), strength(_strength) {}

    // Destructor
    ~Barrel() {}

    // Methods
    int get_nvats() const { return nvats; }
    float get_vol() const { return vol; }
    float get_strength() const { return strength; }
    void distil(float volume) {
        vat.clear(); // Clear existing vats
        nvats = std::ceil(volume / vol); // Calculate the number of vats needed
        vat.resize(nvats, std::vector<float>(2)); // Assuming a 2-column matrix for simplicity
    }
};

// Test or example usage
int main() {
    Barrel myBarrel(50.0); // Create a Barrel with a specified strength
    myBarrel.distil(500.0); // Distil to a certain volume

    std::cout << "Number of vats: " << myBarrel.get_nvats() << std::endl;
    std::cout << "Volume per vat: " << myBarrel.get_vol() << std::endl;
    std::cout << "Overall strength: " << myBarrel.get_strength() << std::endl;

    return 0;
}