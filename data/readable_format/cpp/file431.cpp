#include <iostream>
#include <vector>
#include <cstdlib> // For std::abort()

class Mod1 {
public:
    static void sub(std::vector<float>& vec, int& ny) {
        // Corrected the function call to match the expected signature
        ny = fun(vec, ny, 1);
    }

    static float fun(std::vector<float>& r1, int i1, int i2) {
        if (i1 < 1 || i2 > r1.size()) { // Adjusting for 1-based indexing
            throw std::out_of_range("Index out of bounds");
        }
        r1[i1 - 1] = i1 + 1; // Adjusting for 0-based indexing
        r1[i2 - 1] = i2 + 1;
        return r1[i1 - 1] + r1[i2 - 1];
    }
};

void testFun() {
    std::vector<float> di(5, 0); // initialize all to 0
    float result = Mod1::fun(di, 1, 2);
    if (result != 5) {
        std::cout << "Test fun() Failed" << std::endl;
        std::abort();
    } else {
        std::cout << "Test fun() Passed" << std::endl;
    }
}

void testSub() {
    std::vector<float> di(5, 0); // initialize all to 0
    int i = 1;
    Mod1::sub(di, i);
    if (i != 4) {
        std::cout << "Test sub() Failed" << std::endl;
        std::abort();
    } else {
        std::cout << "Test sub() Passed" << std::endl;
    }
}

int main() {
    try {
        testFun();
        testSub();
        std::cout << "All tests passed." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return 1; // Return non-zero to indicate failure
    }
    return 0;
}