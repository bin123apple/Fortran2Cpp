#include <iostream>
#include <cassert>

class ovlp_I {
public:
    int ovlp(int IC) {
        return IC * 2;
    }
};

void testOvlp() {
    ovlp_I instance;
    assert(instance.ovlp(5) == 10); // Simple test case
    std::cout << "Test passed: ovlp(5) == 10" << std::endl;

    // Add more tests as needed
}

int main() {
    testOvlp(); // Run the test
    return 0;
}