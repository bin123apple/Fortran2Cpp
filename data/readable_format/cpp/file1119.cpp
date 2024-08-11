#include<iostream>

class File1 {
public:
    static float dist1;
};

// Initialization of static member
float File1::dist1 = 10.0f;

int main() {
    std::cout << "Testing dist1 from File1 class..." << std::endl;
    
    // Simple test assertion
    if (File1::dist1 == 10.0f) {
        std::cout << "Test passed: dist1 is initialized correctly." << std::endl;
    } else {
        std::cout << "Test failed: dist1 is NOT initialized correctly." << std::endl;
    }

    return 0;
}