#include <iostream>

// Define the MyMod class directly in this file
class MyMod {
public:
    int intnum;
};

// Function to test the intnum variable within MyMod
void testIntNum() {
    MyMod mod;
    mod.intnum = 5;

    if (mod.intnum == 5) {
        std::cout << "Test passed: intnum == 5" << std::endl;
    } else {
        std::cout << "Test failed: intnum /= 5" << std::endl;
    }
}

int main() {
    testIntNum();
    return 0;
}