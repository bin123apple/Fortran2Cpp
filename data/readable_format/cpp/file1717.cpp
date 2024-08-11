#include <iostream>

// Define the abstract class with a pure virtual function
class NOISE_ADD_SOURCE_MASTER_REC__genmod {
public:
    virtual void NOISE_ADD_SOURCE_MASTER_REC() = 0;
    virtual ~NOISE_ADD_SOURCE_MASTER_REC__genmod() {}
};

// Implement the class that inherits from the abstract class
class NoiseAdder : public NOISE_ADD_SOURCE_MASTER_REC__genmod {
public:
    void NOISE_ADD_SOURCE_MASTER_REC() override {
        std::cout << "Noise added" << std::endl;
    }
};

// Main function to test the functionality
int main() {
    NoiseAdder noiseAdder;
    noiseAdder.NOISE_ADD_SOURCE_MASTER_REC();
    return 0;
}