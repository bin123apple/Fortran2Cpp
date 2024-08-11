#include <iostream>
#include <array>
#include <string>

class Deriv {
public:
    std::string name;
    Deriv(std::string name = "") : name(name) {}
};

std::array<std::string, 2> DEF_ECOSYSTEMS = {"Gridxxxx", "StringYY"};

Deriv DepEcoSystem(DEF_ECOSYSTEMS[0]);

void Init_EcoSystems() {
    int i = 1; // Adjusted for 0-based indexing
    DepEcoSystem = Deriv(DEF_ECOSYSTEMS[i]);
}

void check_system(const std::string& expected_name, int test_id) {
    if (DepEcoSystem.name == expected_name) {
        std::cout << "Test " << test_id << " passed." << std::endl;
    } else {
        std::cout << "Test " << test_id << " failed: expected " << expected_name << ", but got " << DepEcoSystem.name << std::endl;
    }
}

int main() {
    // Test 1: Check initial condition
    check_system("Gridxxxx", 1);
    
    DepEcoSystem.name = "ABCDEFGHIJ";
    Init_EcoSystems();
    
    // Test 2: After Init_EcoSystems
    check_system("StringYY", 2);
    
    return 0;
}