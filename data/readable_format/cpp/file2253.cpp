#include <iostream>
#include <string>

struct AStruct {
    bool a1;
    bool a2;
};

// A simple assert function for testing
void assertTest(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "Test failed: " << message << std::endl;
    } else {
        std::cout << "Test passed: " << message << std::endl;
    }
}

int main() {
    bool l;
    bool l1;  // In Fortran, (kind=1)
    bool l2;  // In Fortran, (kind=2)
    bool l4;  // In Fortran, (kind=4)
    bool l8;  // In Fortran, (kind=8)

    AStruct s1;

    s1.a1 = true;
    s1.a2 = false;

    l1 = true;
    l2 = true;
    l4 = true;
    l8 = true;

    l = false;

    // Running tests
    assertTest(s1.a1 == true, "s1.a1 should be true");
    assertTest(s1.a2 == false, "s1.a2 should be false");
    assertTest(l1 == true, "l1 should be true");
    assertTest(l2 == true, "l2 should be true");
    assertTest(l4 == true, "l4 should be true");
    assertTest(l8 == true, "l8 should be true");
    assertTest(l == false, "l should be false");

    return 0;
}