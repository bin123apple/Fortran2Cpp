#include <iostream>
#include <string>
#include <vector>

class ForceInterface {
public:
    virtual ~ForceInterface() {}
    virtual void force() const = 0;
};

class ForceImpl : public ForceInterface {
public:
    void force() const override {
        std::cout << "Force calculation" << std::endl;
    }
};

// A very simple test function that doesn't depend on any external testing framework.
void testForceCalculation(const ForceInterface& forceInstance) {
    std::cout << "Testing force calculation..." << std::endl;
    forceInstance.force();
    std::cout << "Test passed." << std::endl;
}

int main() {
    ForceImpl forceImpl;
    testForceCalculation(forceImpl);
    return 0;
}